#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>
#include "LinkedList.cpp" 

using namespace std;
using namespace chrono;

long medeTempo(LinkedList& ll, const string& metodo, const vector<int>& entrada) {
    int indice = entrada.size() / 2;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();

    if (metodo == "addFirst") {
        start = high_resolution_clock::now();
        ll.addFirst(10);
        end = high_resolution_clock::now();
        ll.removeFirst();
    } else if (metodo == "add") {
        start = high_resolution_clock::now();
        ll.add(10, indice);
        end = high_resolution_clock::now();
        ll.removeByIndex(indice);
    } else if (metodo == "addLast") {
        start = high_resolution_clock::now();
        ll.addLast(10);
        end = high_resolution_clock::now();
        ll.removeLast();
    } else if (metodo == "getFirst") {
        start = high_resolution_clock::now();
        ll.getFirst();
        end = high_resolution_clock::now();
    } else if (metodo == "get") {
        start = high_resolution_clock::now();
        ll.get(indice);
        end = high_resolution_clock::now();
    } else if (metodo == "getLast") {
        start = high_resolution_clock::now();
        ll.getLast();
        end = high_resolution_clock::now();
    } else if (metodo == "removeFirst") {
        int val = ll.getFirst();
        start = high_resolution_clock::now();
        ll.removeFirst();
        end = high_resolution_clock::now();
        ll.addFirst(val);
    } else if (metodo == "remove") {
        int val = ll.get(indice);
        start = high_resolution_clock::now();
        ll.removeByIndex(indice);
        end = high_resolution_clock::now();
        ll.add(val, indice);
    } else if (metodo == "removeLast") {
        int val = ll.getLast();
        start = high_resolution_clock::now();
        ll.removeLast();
        end = high_resolution_clock::now();
        ll.addLast(val);
    }

    return duration_cast<nanoseconds>(end - start).count();
}

void salvaResultado(const string& metodo, long tempo, size_t tamanhoEntrada) {
    string nomeArquivo = metodo + ".data";
    bool novoArquivo = false;

    ifstream in(nomeArquivo);
    novoArquivo = !in.good() || in.peek() == ifstream::traits_type::eof();
    in.close();

    ofstream out(nomeArquivo, ios::app);
    if (novoArquivo) {
        out << "estrutura-linguagem tempo tamanho_da_entrada" << endl;
    }
    out << "linkedlist-cpp " << tempo << " " << tamanhoEntrada << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> metodos = {
        "addFirst", "add", "addLast",
        "getFirst", "get", "getLast",
        "removeFirst", "remove", "removeLast"
    };

    string linha;
    while (getline(cin, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        vector<int> entrada;
        int num;
        while (ss >> num) entrada.push_back(num);

        LinkedList ll;
        for (int val : entrada) ll.addLast(val);

        for (const string& metodo : metodos) {
            vector<long> resultados(101);
            for (int i = 0; i < 101; ++i) {
                resultados[i] = medeTempo(ll, metodo, entrada);
            }

            sort(resultados.begin(), resultados.end());
            long mediana = resultados[50];

            salvaResultado(metodo, mediana, entrada.size());
        }
    }

    return 0;
}
