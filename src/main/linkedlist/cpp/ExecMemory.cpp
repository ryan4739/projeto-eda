#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <unistd.h>
#include "LinkedList.cpp"

// Inclui a biblioteca para contagem de alocação de memória
#include <malloc_count.h>
// Comando de compilação sugerido:
// g++ exec_memory.cpp ../../../../lib/malloc_count/malloc_count.c -o exec_memory.out -I../../../../lib/malloc_count

using namespace std;
namespace fs = std::filesystem;

/**
 * @brief Nomes dos métodos que serão testados para medição de memória
 *
 * Esta lista contém os nomes de todas as operações que serão executadas na fila
 * para medição do pico de memória durante cada operação.
 */
const vector<string> METHOD_NAMES = {
    "removeLast",
    "addLast",
    "getLast",
    "removeFirst",
    "addFirst",
    "getFirst",
    "removeByIndex",
    "add",
    "get"
};

/**
 * @brief Testa operações na fila medindo o pico de memória durante execução
 *
 * @param elements Vetor de inteiros contendo os elementos a serem inseridos na fila
 * @param writers Array de streams de arquivo para escrita dos resultados
 * @param currentLine Número da linha atual sendo processada (para feedback)
 * @param totalLines Total de linhas a serem processadas (para feedback)
 */
void testllOperations(const vector<int>& elements, ofstream writers[], int currentLine, int totalLines) {
    int length = elements.size();
    int middle = length / 2;
    const int RUNS = 5;

    // Matriz para armazenar os picos de memória de cada método em cada execução
    vector<vector<size_t>> memoryPeaks(METHOD_NAMES.size(), vector<size_t>(RUNS));

    // Cria e preenche a fila com os elementos fornecidos
    LinkedList ll = LinkedList();
    for (int num : elements) {
        ll.addLast(num);
    }

    for (int run = 0; run < RUNS; run++) {
        // Testa removeLast
        malloc_count_reset_peak();
        ll.removeLast();
        memoryPeaks[0][run] = malloc_count_peak() / 1024; // Convertendo para KB

        // Testa addLast
        malloc_count_reset_peak();
        ll.addLast(999);
        memoryPeaks[1][run] = malloc_count_peak() / 1024;

        // Testa getLast
        malloc_count_reset_peak();
        ll.getLast();
        memoryPeaks[2][run] = malloc_count_peak() / 1024;

        // Testa removeFirst
        malloc_count_reset_peak();
        ll.removeFirst();
        memoryPeaks[3][run] = malloc_count_peak() / 1024;

        // Testa addFirst
        malloc_count_reset_peak();
        ll.addFirst(999);
        memoryPeaks[4][run] = malloc_count_peak() / 1024;

        // Testa getFirst
        malloc_count_reset_peak();
        ll.getFirst();
        memoryPeaks[5][run] = malloc_count_peak() / 1024;

        // Testa remove (middle)
        malloc_count_reset_peak();
        ll.removeByIndex(middle);
        memoryPeaks[6][run] = malloc_count_peak() / 1024;

        // Testa add (middle)
        malloc_count_reset_peak();
        ll.add(999, middle);
        memoryPeaks[7][run] = malloc_count_peak() / 1024;
        
        // Testa get (middle)
        malloc_count_reset_peak();
        ll.get(middle);
        memoryPeaks[8][run] = malloc_count_peak() / 1024;
    }

    // Processa os resultados calculando a mediana dos picos de memória
    for (size_t method = 0; method < METHOD_NAMES.size(); method++) {
        sort(memoryPeaks[method].begin(), memoryPeaks[method].end());
        size_t medianPeak = memoryPeaks[method][RUNS / 2];
        
        // Escreve resultado no arquivo correspondente
        writers[method] << "linkedlist_cpp " << medianPeak << " " << length << endl;
        writers[method].flush();
    }

    // Exibe progresso para o usuário
    cerr << "\rProcessando linha " << currentLine << "/" << totalLines << flush;
}

/**
 * @brief Função principal que coordena a execução do programa
 *
 * @param argc Número de argumentos de linha de comando
 * @param argv Vetor de argumentos de linha de comando
 * @return int Código de saída (0 para sucesso, 1 para erro)
 */
int main(int argc, char* argv[]) {
    // Verifica argumentos de linha de comando
    if (argc < 2) {
        cerr << "ERRO: número de argumentos inválido!" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputDir = "data/results/memory/";

    // Cria diretório de saída se não existir
    try {
        fs::create_directories(outputDir);
    } catch (const fs::filesystem_error& e) {
        cerr << "ERRO: Não foi possível criar o diretório de saída: "
             << outputDir << "\n" << e.what() << endl;
        return 1;
    }

    // Prepara arquivos de saída para cada método
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

        // Escreve cabeçalho se o arquivo for novo ou estiver vazio
        if (!fileExists || fileIsEmpty) {
            writers[i] << "estrutura_linguagem memoria tamanho" << endl;
        }
    }

    try {
        // Abre arquivo de entrada
        ifstream reader(inputFile);
        if (!reader) {
            throw runtime_error("\nNão foi possível abrir o arquivo de entrada: " + inputFile);
        }

        // Conta total de linhas para feedback de progresso
        int totalLines = 0;
        string line;
        while (getline(reader, line)) {
            if (!line.empty()) totalLines++;
        }
        reader.clear();
        reader.seekg(0);

        // Processa cada linha do arquivo de entrada
        int currentLine = 0;
        while (getline(reader, line)) {
            if (line.empty()) continue;
            currentLine++;
            
            // Converte linha em vetor de inteiros
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

            // Testa operações com os elementos lidos
            testllOperations(elements, writers, currentLine, totalLines);
        }

        cerr << "\rConcluído! Processadas " << totalLines << " linhas." << endl;

        // Fecha todos os arquivos de saída
        for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
            writers[i].close();
        }

    } catch (const exception& e) {
        // Tratamento de erros durante a execução
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

