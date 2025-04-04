#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include "queue.cpp"

using namespace std;
using namespace std::chrono;

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

void testQueueOperations(const vector<int>& elements, ofstream writers[]) {
    int length = elements.size();
    int middle = length / 2;
    const int RUNS = 30;
    vector<vector<long>> allTimes(METHOD_NAMES.size(), vector<long>(RUNS));

    for (int run = 0; run < RUNS; run++) {
        Queue<int> queue(length + 3);
        
        // Preenche a fila com os elementos iniciais
        for (int num : elements) {
            queue.addLast(num);
        }

        // Testa addLast
        auto startTime = high_resolution_clock::now();
        queue.addLast(999);
        auto endTime = high_resolution_clock::now();
        allTimes[0][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa addFirst
        startTime = high_resolution_clock::now();
        queue.addFirst(999);
        endTime = high_resolution_clock::now();
        allTimes[1][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa add (middle)
        startTime = high_resolution_clock::now();
        queue.add(999, middle);
        endTime = high_resolution_clock::now();
        allTimes[2][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa removeFirst
        startTime = high_resolution_clock::now();
        queue.removeFirst();
        endTime = high_resolution_clock::now();
        allTimes[3][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa removeLast
        startTime = high_resolution_clock::now();
        queue.removeLast();
        endTime = high_resolution_clock::now();
        allTimes[4][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa remove (middle)
        startTime = high_resolution_clock::now();
        queue.remove(middle);
        endTime = high_resolution_clock::now();
        allTimes[5][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa getFirst
        startTime = high_resolution_clock::now();
        queue.getFirst();
        endTime = high_resolution_clock::now();
        allTimes[6][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa getLast
        startTime = high_resolution_clock::now();
        queue.getLast();
        endTime = high_resolution_clock::now();
        allTimes[7][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa get (middle)
        startTime = high_resolution_clock::now();
        queue.get(middle);
        endTime = high_resolution_clock::now();
        allTimes[8][run] = duration_cast<nanoseconds>(endTime - startTime).count();
    }

    // Calcula e escreve a mediana para cada método
    for (size_t method = 0; method < METHOD_NAMES.size(); method++) {
        sort(allTimes[method].begin(), allTimes[method].end());
        long medianTime = allTimes[method][RUNS / 2];
        
        writers[method] << "queue-cpp " << medianTime << " " << length << endl;
        writers[method].flush();
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_entrada>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputDir = "data/results/time/";

    // Abre arquivos de saída para cada método
    ofstream writers[METHOD_NAMES.size()];
    for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
        string outputFile = outputDir + METHOD_NAMES[i] + ".data";
        writers[i].open(outputFile, ios::app); // Modo append
        if (!writers[i]) {
            cerr << "Erro ao abrir arquivo de saída: " << outputFile << endl;
            return 1;
        }
    }

    try {
        ifstream reader(inputFile);
        if (!reader) {
            throw runtime_error("Não foi possível abrir o arquivo de entrada: " + inputFile);
        }

        string line;
        while (getline(reader, line)) {
            if (line.empty()) continue;
            
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

            testQueueOperations(elements, writers);
        }

        // Fecha todos os arquivos
        for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
            writers[i].close();
        }

    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
            if (writers[i].is_open()) {
                writers[i].close();
            }
        }
        return 1;
    }

    return 0;
}
