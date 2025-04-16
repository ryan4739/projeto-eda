#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <unistd.h>
#include "ArrayList.h"
#include <malloc_count.h>
// Compile com: 
// g++ ExecMemo.cpp ArrayList.cpp ../../../../lib/malloc_count/malloc_count.c -o ExecMemo.out -I../../../../lib/malloc_count

using namespace std;
namespace fs = std::filesystem;

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

void testArrayListOperations(const vector<int>& elements, ofstream writers[], int currentLine, int totalLines) {
    int length = elements.size();
    int middle = length / 2;
    const int RUNS = 5;

    vector<vector<size_t>> memoryPeaks(METHOD_NAMES.size(), vector<size_t>(RUNS));

    ArrayList arrayList(length);
    for (int num : elements) {
        arrayList.addLast(num);
    }

    for (int run = 0; run < RUNS; run++) {
        malloc_count_reset_peak();
        arrayList.rmvLast();
        memoryPeaks[0][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.addLast(999);
        memoryPeaks[1][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.getLast();
        memoryPeaks[2][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.rmvFirst();
        memoryPeaks[3][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.addFirst(999);
        memoryPeaks[4][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.getFirst();
        memoryPeaks[5][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.rmvIndex(middle);
        memoryPeaks[6][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.addIndex(999, middle);
        memoryPeaks[7][run] = malloc_count_peak() / 1024;

        malloc_count_reset_peak();
        arrayList.get(middle);
        memoryPeaks[8][run] = malloc_count_peak() / 1024;
    }

    for (size_t method = 0; method < METHOD_NAMES.size(); method++) {
        sort(memoryPeaks[method].begin(), memoryPeaks[method].end());
        size_t medianPeak = memoryPeaks[method][RUNS / 2];
        writers[method] << "arraylist_cpp " << medianPeak << " " << length << endl;
        writers[method].flush();
    }

    cerr << "\rProcessando linha " << currentLine << "/" << totalLines << flush;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "ERRO: número de argumentos inválido!" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputDir = "data/results/memory/";

    try {
        fs::create_directories(outputDir);
    } catch (const fs::filesystem_error& e) {
        cerr << "ERRO ao criar diretório: " << outputDir << "\n" << e.what() << endl;
        return 1;
    }

    ofstream writers[METHOD_NAMES.size()];
    for (size_t i = 0; i < METHOD_NAMES.size(); i++) {
        string outputFile = outputDir + METHOD_NAMES[i] + ".data";
        bool exists = fs::exists(outputFile);
        bool empty = exists ? fs::file_size(outputFile) == 0 : true;

        writers[i].open(outputFile, ios::app);
        if (!writers[i]) {
            cerr << "Erro ao abrir: " << outputFile << endl;
            return 1;
        }

        if (!exists || empty) {
            writers[i] << "estrutura_linguagem memoria tamanho" << endl;
        }
    }

    try {
        ifstream reader(inputFile);
        if (!reader) throw runtime_error("Não foi possível abrir o arquivo: " + inputFile);

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
                elements.push_back(stoi(line.substr(0, pos)));
                line.erase(0, pos + 1);
            }
            if (!line.empty()) elements.push_back(stoi(line));

            testArrayListOperations(elements, writers, currentLine, totalLines);
        }

        cerr << "\rConcluído! Processadas " << totalLines << " linhas." << endl;

        for (auto& w : writers) w.close();

    } catch (const exception& e) {
        cerr << "\nErro: " << e.what() << endl;
        for (auto& w : writers) if (w.is_open()) w.close();
        return 1;
    }

    return 0;
}
