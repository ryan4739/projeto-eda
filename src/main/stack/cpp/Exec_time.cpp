#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include "Stack.cpp"  

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

// Lista de nomes das operações que serão testadas
const vector<string> METHOD_NAMES = {
    "remove_last",
    "add_last",
    "get_last",
    "remove_first",
    "add_first",
    "get_first",
    "remove_middle",
    "add_middle",
    "get_middle"
};

/**
 * Testa todas as operações da Stack e registra os tempos de execução
 *
 * @param elements Vetor contendo os elementos iniciais da Stack
 * @param writers Array de arquivos de saída para gravar os resultados
 * @param currentLine Número da linha atual sendo processada (para exibir progresso)
 * @param totalLines Total de linhas a processar (para exibir progresso)
 */
void testStackOperations(const vector<int>& elements, ofstream writers[], int currentLine, int totalLines) {
    int length = elements.size();
    // Posição do meio para algumas operações
    int middle = length / 2;
    // Número de execuções para cada teste
    const int RUNS = 30;

    // Matriz para armazenar todos os tempos de execução
    vector<vector<long>> allTimes(METHOD_NAMES.size(), vector<long>(RUNS));

    // Cria e preenche a Stack com os elementos iniciais
    Stack stack;  // Supondo que a classe Stack tenha esse construtor
    for (int num : elements) {
        stack.addLast(num);  // Usando addLast para adicionar elementos
    }

    // Executa cada operação RUNS vezes para obter dados estatísticos
    for (int run = 0; run < RUNS; run++) {
        // Testa removeLast
        auto startTime = high_resolution_clock::now();
        stack.pop();
        auto endTime = high_resolution_clock::now();
        allTimes[0][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa addLast
        startTime = high_resolution_clock::now();
        stack.push(999);  // Adiciona 999 no final
        endTime = high_resolution_clock::now();
        allTimes[1][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa getLast
        startTime = high_resolution_clock::now();
        stack.peek();  // Obtém o último valor
        endTime = high_resolution_clock::now();
        allTimes[2][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa removeFirst
        startTime = high_resolution_clock::now();
        stack.RemoveFirst();  // Remove o primeiro elemento
        endTime = high_resolution_clock::now();
        allTimes[3][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa addFirst
        startTime = high_resolution_clock::now();
        stack.pushLast(999);  // Adiciona 999 no começo
        endTime = high_resolution_clock::now();
        allTimes[4][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa getFirst
        startTime = high_resolution_clock::now();
        stack.peekLast();  // Obtém o primeiro valor
        endTime = high_resolution_clock::now();
        allTimes[5][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa remove (middle)
        startTime = high_resolution_clock::now();
        stack.RemoveIndex(middle);  // Remove o valor no meio
        endTime = high_resolution_clock::now();
        allTimes[6][run] = duration_cast<nanoseconds>(endTime - startTime).count();

        // Testa add (middle)
        startTime = high_resolution_clock::now();
        stack.PushIndex(999, middle);  // Adiciona 999 no meio
        endTime = high_resolution_clock::now();
        allTimes[7][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        
        // Testa get (middle)
        startTime = high_resolution_clock::now();
        stack.peekIndex(middle);  // Obtém o valor no meio
        endTime = high_resolution_clock::now();
        allTimes[8][run] = duration_cast<nanoseconds>(endTime - startTime).count();
    }

    // Processa os resultados: calcula a mediana para cada operação
    for (size_t method = 0; method < METHOD_NAMES.size(); method++) {
        sort(allTimes[method].begin(), allTimes[method].end());
        long medianTime = allTimes[method][RUNS / 2];
        
        writers[method] << "stack_cpp " << medianTime << " " << length << endl;
        writers[method].flush();
    }

    cerr << "\rProcessando linha " << currentLine << "/" << totalLines << flush;
}

/**
 * Função principal do programa
 *
 * @param argc Número de argumentos de linha de comando
 * @param argv Array de argumentos (argv[1] = arquivo de entrada)
 * @return 0 em caso de sucesso, 1 em caso de erro
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "ERRO: número de argumentos inválido!" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputDir = "data/results/time/";

    try {
        fs::create_directories(outputDir);
    } catch (const fs::filesystem_error& e) {
        cerr << "ERRO: Não foi possível criar o diretório de saída: "
             << outputDir << "\n" << e.what() << endl;
        return 1;
    }

    ofstream writers[METHOD_NAMES.size()];
    for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
        string outputFile = outputDir + METHOD_NAMES[i] + ".data";
        bool fileExists = fs::exists(outputFile);
        bool fileIsEmpty = fileExists ? fs::file_size(outputFile) == 0 : true;
        writers[i].open(outputFile, ios::app);
        if (!writers[i]) {
            cerr << "\nErro ao abrir arquivo de saída: " << outputFile << endl;
            return 1;
        }
        if (!fileExists || fileIsEmpty) {
            writers[i] << "estrutura_linguagem tempo tamanho" << endl;
        }
    }

    try {
        ifstream reader(inputFile);
        if (!reader) {
            throw runtime_error("\nNão foi possível abrir o arquivo de entrada: " + inputFile);
        }

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

            teststackOperations(elements, writers, currentLine, totalLines);
        }

        cerr << "\rConcluído! Processadas " << totalLines << " linhas." << endl;

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
