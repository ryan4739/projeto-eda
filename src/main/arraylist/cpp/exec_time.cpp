#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <stdexcept>
#include "ArrayList.cpp"
#include "ArrayList.h"

using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_de_entrada>" << endl;
        return 1;
    }

    ifstream entrada(argv[1]);
    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    ArrayList arraylist;
    string linha;
    int valor;

    while (getline(entrada, linha)) {
        stringstream ss(linha);
        string operacao;
        ss >> operacao;

        if (operacao == "add_first") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            arraylist.addFirst(valor);
            auto fim = high_resolution_clock::now();
            cout << "add_first: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "add_last") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            arraylist.addLast(valor);
            auto fim = high_resolution_clock::now();
cout << "add_last: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "add_middle") {
            ss >> valor;
            int index = arraylist.getSize() / 2;
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.addIndex(valor, index);
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "add_middle: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "remove_first") {
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.rmvFirst();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "remove_first: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "remove_last") {
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.rmvLast();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "remove_last: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "remove_middle") {
            int index = arraylist.getSize() / 2;
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.rmvIndex(index);
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "remove_middle: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "get_first") {
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.getFirst();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "get_first: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "get_last") {
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.getLast();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "get_last: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "get_middle") {
            int index = arraylist.getSize() / 2;
            auto inicio = high_resolution_clock::now();
            try {
                arraylist.get(index);
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "get_middle: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
    }

    entrada.close();
    return 0;
}
