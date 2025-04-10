#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>
#include "Stack.cpp"

using namespace std;
using namespace chrono;

void ensureHeaderExists(const string& filename) {
    ifstream infile(filename);
    bool isNewFile = !infile.good() || infile.peek() == ifstream::traits_type::eof();
    infile.close();

    if (isNewFile) {
        ofstream outfile(filename);
        outfile << "estrutura-linguagem tempo tamanho_da_entrada" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> methods = {"PushIndex", "push", "pushLast",
                              "peekIndex", "peek", "peekLast",
                              "RemoveFirst", "pop", "RemoveIndex"};

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        vector<int> input;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            input.push_back(num);
        }

        for (const auto& method : methods) {
            vector<long> results(30);

            for (int i = 0; i < 30; i++) {
                Stack ll;
                for (int val : input) {
                    ll.push(val);
                }

                auto start = high_resolution_clock::now();

                if (method == "push") {
                    ll.push(10);
                } else if (method == "pushIndex") {
                    ll.pushIndex(10, input.size() / 2);
                } else if (method == "pushLast") {
                    ll.pushLast(10);
                } else if (method == "push") {
                    ll.push();
                } else if (method == "peek") {
                    ll.peek(input.size() / 2);
                } else if (method == "peekLast") {
                    ll.peekLast();
                } else if (method == "RemoveFirst") {
                    ll.removeFirst();
                } else if (method == "RemoveIndex") {
                    ll.RemoveIndex(input.size() / 2);
                } else if (method == "pop") {
                    ll.pop();
                }

                auto end = high_resolution_clock::now();
                results[i] = duration_cast<nanoseconds>(end - start).count();
            }

            sort(results.begin(), results.end());
            long medianTime = results[14];

            string filename = method + ".data";
            ensureHeaderExists(filename);  // Garante que o cabeçalho só seja escrito uma vez

            ofstream file(filename, ios::app);
            file << "Stack-cpp-memory " << medianTime << " " << input.size() << endl;
        }
    }
    return 0;
}
