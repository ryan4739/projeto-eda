#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "queue.cpp"

#ifdef __linux__
#include <sys/resource.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <psapi.h>
#endif

using namespace std;

const vector<string> METHOD_NAMES = {
    "addLast",
    "addFirst",
    "add",
    "removeFirst",
    "removeLast",
    "remove",
    "getFirst",
    "getLast",
    "get"
};

long getMemoryUsage() {
    #ifdef __linux__
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss * 1024; // Convertendo de KB para bytes
    #elif defined(_WIN32) || defined(_WIN64)
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    return pmc.PrivateUsage;
    #else
    return 0; // Não suportado em outras plataformas
    #endif
}

void testQueueOperations(const vector<int>& elements, ofstream writers[], int currentLine, int totalLines) {
    int length = elements.size();
    int middle = length / 2;
    const int RUNS = 30;
    vector<vector<long>> allMemoryUsage(METHOD_NAMES.size(), vector<long>(RUNS));

    for (int run = 0; run < RUNS; run++) {
        Queue<int> queue(length + 3);
        
        // Preenche a fila com os elementos iniciais
        for (int num : elements) {
            queue.addLast(num);
        }

        // Medição de memória antes e depois de cada operação
        long beforeMem, afterMem;

        // Testa addLast
        beforeMem = getMemoryUsage();
        queue.addLast(999);
        afterMem = getMemoryUsage();
        allMemoryUsage[0][run] = afterMem - beforeMem;

        // Testa addFirst
        beforeMem = getMemoryUsage();
        queue.addFirst(999);
        afterMem = getMemoryUsage();
        allMemoryUsage[1][run] = afterMem - beforeMem;

        // Testa add (middle)
        beforeMem = getMemoryUsage();
        queue.add(999, middle);
        afterMem = getMemoryUsage();
        allMemoryUsage[2][run] = afterMem - beforeMem;
        
        // Testa removeFirst
        beforeMem = getMemoryUsage();
        queue.removeFirst();
        afterMem = getMemoryUsage();
        allMemoryUsage[3][run] = afterMem - beforeMem;
        
        // Testa removeLast
        beforeMem = getMemoryUsage();
        queue.removeLast();
        afterMem = getMemoryUsage();
        allMemoryUsage[4][run] = afterMem - beforeMem;
        
        // Testa remove (middle)
        beforeMem = getMemoryUsage();
        queue.remove(middle);
        afterMem = getMemoryUsage();
        allMemoryUsage[5][run] = afterMem - beforeMem;
        
        // Testa getFirst (operações get não devem alocar memória)
        beforeMem = getMemoryUsage();
        queue.getFirst();
        afterMem = getMemoryUsage();
        allMemoryUsage[6][run] = afterMem - beforeMem;
        
        // Testa getLast
        beforeMem = getMemoryUsage();
        queue.getLast();
        afterMem = getMemoryUsage();
        allMemoryUsage[7][run] = afterMem - beforeMem;
        
        // Testa get (middle)
        beforeMem = getMemoryUsage();
        queue.get(middle);
        afterMem = getMemoryUsage();
        allMemoryUsage[8][run] = afterMem - beforeMem;
    }

    // Calcula e escreve a mediana para cada método
    for (size_t method = 0; method < METHOD_NAMES.size(); method++) {
        sort(allMemoryUsage[method].begin(), allMemoryUsage[method].end());
        long medianMemory = allMemoryUsage[method][RUNS / 2];
        
        writers[method] << "queue-cpp " << medianMemory << " " << length << endl;
        writers[method].flush();
    }

    // Imprimindo o progresso
    cerr << "\rProcessando linha " << currentLine << "/" << totalLines << flush;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_entrada>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputDir = "data/results/memory/"; // Alterado para diretório de memória

    // Abre arquivos de saída para cada método
    ofstream writers[METHOD_NAMES.size()];
    for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
        string outputFile = outputDir + METHOD_NAMES[i] + ".data";
        writers[i].open(outputFile, ios::app); // Modo append
        if (!writers[i]) {
            cerr << "\nErro ao abrir arquivo de saída: " << outputFile << endl;
            return 1;
        }
    }

    try {
        ifstream reader(inputFile);
        if (!reader) {
            throw runtime_error("\nNão foi possível abrir o arquivo de entrada: " + inputFile);
        }

        // Captando o total de linhas
        int totalLines = 0;
        string line;
        while (getline(reader, line)) {
            if (!line.empty()) totalLines++;
        }
        reader.clear();
        reader.seekg(0);

        int currentLine = 0;
        while (getline(reader, line)) {
            if (line.empty()) continue;
            currentLine++;
            
            // Converte a linha para vetor de inteiros
            vector<int> elements;
            size_t pos = 0;
            while ((pos = line.find(' ')) != string::npos) {
                string token = line.substr(0, pos);
                elements.push_back(stoi(token));
                line.erase(0, pos + 1);
            }
            if (!line.empty()) {
                elements.push_back(stoi(line));
            }

            testQueueOperations(elements, writers, currentLine, totalLines);
        }

        cerr << "\rConcluído! Processadas " << totalLines << " linhas." << endl;

        // Fecha todos os arquivos
        for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
            writers[i].close();
        }

    } catch (const exception& e) {
        cerr << "\nErro: " << e.what() << endl;
        for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
            if (writers[i].is_open()) {
                writers[i].close();
            }
        }
        return 1;
    }

    return 0;
}

