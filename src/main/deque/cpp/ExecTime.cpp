#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include "Deque.cpp" // Inclua sua classe diretamente (ou use o mesmo arquivo)

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

    Deque deque;
    string linha;
    int valor;

    while (getline(entrada, linha)) {
        stringstream ss(linha);
        string operacao;
        ss >> operacao;

        if (operacao == "addFirst") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            deque.addFirst(valor);
            auto fim = high_resolution_clock::now();
            cout << "addFirst: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "addLast") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            deque.addLast(valor);
            auto fim = high_resolution_clock::now();
            cout << "addLast: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "removeFirst") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.removeFirst();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "removeFirst: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "removeLast") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.removeLast();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "removeLast: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "getFirst") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.getFirst();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "getFirst: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "getLast") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.getLast();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "getLast: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "contains") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            deque.contains(valor);
            auto fim = high_resolution_clock::now();
            cout << "contains: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
    }

    entrada.close();
    return 0;
}
