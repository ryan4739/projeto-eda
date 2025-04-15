#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include "Deque.cpp"

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

        if (operacao == "add_first") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            deque.addFirst(valor);
            auto fim = high_resolution_clock::now();
            cout << "add_first: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "add_last") {
            ss >> valor;
            auto inicio = high_resolution_clock::now();
            deque.addLast(valor);
            auto fim = high_resolution_clock::now();
            cout << "add_last: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "add_middle") {
            ss >> valor;
            int index = deque.getSize() / 2;
            auto inicio = high_resolution_clock::now();
            try {
                deque.add(valor, index);
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "add_middle: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "remove_first") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.removeFirst();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "remove_first: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "remove_last") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.removeLast();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "remove_last: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "remove_middle") {
            int index = deque.getSize() / 2;
            auto inicio = high_resolution_clock::now();
            try {
                deque.remove(index);
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "remove_middle: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "get_first") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.getFirst();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "get_first: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "get_last") {
            auto inicio = high_resolution_clock::now();
            try {
                deque.getLast();
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "get_last: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
        else if (operacao == "get_middle") {
            int index = deque.getSize() / 2;
            auto inicio = high_resolution_clock::now();
            try {
                deque.get(index);
            } catch (const out_of_range& e) {}
            auto fim = high_resolution_clock::now();
            cout << "get_middle: " << duration<double, micro>(fim - inicio).count() << " us" << endl;
        }
    }

    entrada.close();
    return 0;
}
