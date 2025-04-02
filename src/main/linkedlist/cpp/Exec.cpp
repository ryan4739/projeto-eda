#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>
#include "LinkedList.cpp"

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

    vector<string> methods = {"addFirst", "add", "addLast",
                              "getFirst", "get", "getLast",
                              "removeFirst", "remove", "removeLast"};

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
                LinkedList ll;
                for (int val : input) {
                    ll.addLast(val);
                }

                auto start = high_resolution_clock::now();

                if (method == "addFirst") {
                    ll.addFirst(10);
                } else if (method == "add") {
                    ll.add(10, input.size() / 2);
                } else if (method == "addLast") {
                    ll.addLast(10);
                } else if (method == "getFirst") {
                    ll.getFirst();
                } else if (method == "get") {
                    ll.get(input.size() / 2);
                } else if (method == "getLast") {
                    ll.getLast();
                } else if (method == "removeFirst") {
                    ll.removeFirst();
                } else if (method == "remove") {
                    ll.removeByIndex(input.size() / 2);
                } else if (method == "removeLast") {
                    ll.removeLast();
                }

                auto end = high_resolution_clock::now();
                results[i] = duration_cast<nanoseconds>(end - start).count();
            }

            sort(results.begin(), results.end());
            long medianTime = results[14];

            string filename = method + ".data";
            ensureHeaderExists(filename);  // Garante que o cabeçalho só seja escrito uma vez

            ofstream file(filename, ios::app);
            file << "linkedlist-cpp " << medianTime << " " << input.size() << endl;
        }
    }
    return 0;
}
