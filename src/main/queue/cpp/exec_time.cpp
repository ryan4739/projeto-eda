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

// Lista de nomes das operações que serão testadas
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

/**
 * Testa todas as operações da fila e registra os tempos de execução
 *
 * @param elements Vetor contendo os elementos iniciais da fila
 * @param writers Array de arquivos de saída para gravar os resultados
 * @param currentLine Número da linha atual sendo processada (para exibir progresso)
 * @param totalLines Total de linhas a processar (para exibir progresso)
 */
void testQueueOperations(const vector<int>& elements, ofstream writers[], int currentLine, int totalLines) {
    // Tamanho da fila
    int length = elements.size();
    // Posição do meio para algumas operações
    int middle = length / 2;
    // Número de execuções para cada teste
    const int RUNS = 30;

    // Matriz para armazenar todos os tempos de execução
    // Cada linha representa uma operação, cada coluna uma execução
    vector<vector<long>> allTimes(METHOD_NAMES.size(), vector<long>(RUNS));

    // Executa cada operação RUNS vezes para obter dados estatísticos
    for (int run = 0; run < RUNS; run++) {
        Queue<int> queue(length + 1);
        
        // Preenche a fila com os elementos iniciais
        for (int num : elements) {
            queue.addLast(num);
        }

        // Testa addLast
        auto startTime = high_resolution_clock::now();
        queue.addLast(999);
        auto endTime = high_resolution_clock::now();
        allTimes[0][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        queue.removeFirst();

        // Testa addFirst
        startTime = high_resolution_clock::now();
        queue.addFirst(999);
        endTime = high_resolution_clock::now();
        allTimes[1][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        queue.removeFirst();

        // Testa add (middle)
        startTime = high_resolution_clock::now();
        queue.add(999, middle);
        endTime = high_resolution_clock::now();
        allTimes[2][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        queue.removeFirst();
        
        // Testa removeFirst
        startTime = high_resolution_clock::now();
        queue.removeFirst();
        endTime = high_resolution_clock::now();
        allTimes[3][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        queue.addLast(999);
        
        // Testa removeLast
        startTime = high_resolution_clock::now();
        queue.removeLast();
        endTime = high_resolution_clock::now();
        allTimes[4][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        queue.addLast(999);
        
        // Testa remove (middle)
        startTime = high_resolution_clock::now();
        queue.remove(middle);
        endTime = high_resolution_clock::now();
        allTimes[5][run] = duration_cast<nanoseconds>(endTime - startTime).count();
        queue.addLast(999);
        
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

    // Processa os resultados: calcula a mediana para cada operação
    for (size_t method = 0; method < METHOD_NAMES.size(); method++) {
        // Ordena os tempos para cálculo da mediana
        sort(allTimes[method].begin(), allTimes[method].end());
        long medianTime = allTimes[method][RUNS / 2];
        
        // Grava no formato: "queue_cpp <tempo> <tamanho>"
        writers[method] << "queue_cpp " << medianTime << " " << length << endl;
        writers[method].flush();
    }

    // Exibe progresso do processamento
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
    // Verifica se o arquivo de entrada foi fornecido
    if (argc < 2) {
        cerr << "ERRO: nenhum argumento!" << endl;
        return 1;
    }

    // Arquivo com dados de entrada
    string inputFile = argv[1];
    // Diretório de saída
    string outputDir = "data/results/time/";

    // Prepara os arquivos de saída (um para cada operação)
    ofstream writers[METHOD_NAMES.size()];
    for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
        string outputFile = outputDir + METHOD_NAMES[i] + ".data";
        writers[i].open(outputFile, ios::app); // Modo append para não sobrescrever
        if (!writers[i]) {
            cerr << "\nErro ao abrir arquivo de saída: " << outputFile << endl;
            return 1;
        }
    }

    try {
        // Abre arquivo de entrada
        ifstream reader(inputFile);
        if (!reader) {
            throw runtime_error("\nNão foi possível abrir o arquivo de entrada: " + inputFile);
        }

        // Conta o número total de linhas para mostrar progresso
        int totalLines = 0;
        string line;
        while (getline(reader, line)) {
            if (!line.empty()) totalLines++;
        }
        // Limpa flags de erro
        reader.clear();
        // Volta para o início do arquivo
        reader.seekg(0);

        // Processa cada linha do arquivo de entrada
        int currentLine = 0;
        while (getline(reader, line)) {
            if (line.empty()) continue; // Ignora linhas vazias
            currentLine++;
            
            // Converte a linha (string) para vetor de inteiros
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

            // Executa os testes para esta linha
            testQueueOperations(elements, writers, currentLine, totalLines);
        }

        cerr << "\rConcluído! Processadas " << totalLines << " linhas." << endl;

        // Fecha todos os arquivos de saída
        for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
            writers[i].close();
        }

    } catch (const exception& e) {
        // Tratamento de erros
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
