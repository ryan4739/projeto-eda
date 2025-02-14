#include <iostream>
#include <deque>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void append_left(deque<int>& dq, int entrada) {
    for (int i = 0; i < entrada; i++) {
        dq.push_front(i);
    }
}

void append_right(deque<int>& dq, int entrada) {
    for (int i = 0; i < entrada; i++) {
        dq.push_back(i);
    }
}

void extend_left(deque<int>& dq, const deque<int>& valores) {
    for (auto it = valores.rbegin(); it != valores.rend(); ++it) {
        dq.push_front(*it);
    }
}

void extend_right(deque<int>& dq, const deque<int>& valores) {
    dq.insert(dq.end(), valores.begin(), valores.end());
}

void pop_left(deque<int>& dq) {
    while (!dq.empty()) {
        dq.pop_front();
    }
}

void pop_right(deque<int>& dq) {
    while (!dq.empty()) {
        dq.pop_back();
    }
}

int access_left(const deque<int>& dq) {
    return dq.empty() ? -1 : dq.front();
}

int access_right(const deque<int>& dq) {
    return dq.empty() ? -1 : dq.back();
}

int access_random(const deque<int>& dq) {
    if (dq.empty()) return -1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<size_t> distrib(0, dq.size() - 1);
    return dq[distrib(gen)];
}

void rotate_deque(deque<int>& dq, int n) {
    if (dq.empty()) return;
    n %= dq.size();
    rotate(dq.begin(), dq.begin() + (n < 0 ? dq.size() + n : n), dq.end());
}

void remove_value(deque<int>& dq, int value) {
    dq.erase(remove(dq.begin(), dq.end(), value), dq.end());
}

int count_value(const deque<int>& dq, int value) {
    return count(dq.begin(), dq.end(), value);
}

