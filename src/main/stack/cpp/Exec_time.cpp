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

    vector<string> methods = {"pushIndex", "push", "pushLast",
                              "peekIndex", "peek", "peekLast",
                              "removeFirst", "pop", "removeIndex"};

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
                } else if (method == "peek") {
                    ll.peek(input.size() / 2);
                } else if (method == "peekIndex") {
                    ll.peekIndex(input.size() / 2);
                } else if (method == "peekLast") {
                    ll.peekLast();
                } else if (method == "removeFirst") {
                    ll.removeFirst();
                } else if (method == "removeIndex") {
                    ll.removeIndex(input.size() / 2);
                } else if (method == "pop") {
                    ll.pop();
                }

                auto end = high_resolution_clock::now();
                results[i] = duration_cast<nanoseconds>(end - start).count();
            }

            sort(results.begin(), results.end());
            long medianTime = results[14];

            string filename = method + ".data";
            ensureHeaderExists(filename);

            ofstream file(filename, ios::app);
            file << "Stack-cpp " << medianTime << " " << input.size() << endl;
        }
    }
    return 0;
}
