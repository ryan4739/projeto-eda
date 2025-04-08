import sys
import time
import os
import statistics
from linked_list import LinkedList

methods = [
    "addFirst", "add", "addLast",
    "getFirst", "get", "getLast",
    "removeFirst", "remove", "removeLast"
]

def mede_tempo(ll, method, n):
    index = n // 2
    start = end = 0

    if method == "addFirst":
        start = time.perf_counter_ns()
        ll.add_first(10)
        end = time.perf_counter_ns()
        ll.remove_first()

    elif method == "add":
        start = time.perf_counter_ns()
        ll.add(10, index)
        end = time.perf_counter_ns()
        ll.remove_by_index(index)

    elif method == "addLast":
        start = time.perf_counter_ns()
        ll.add_last(10)
        end = time.perf_counter_ns()
        ll.remove_last()

    elif method == "getFirst":
        start = time.perf_counter_ns()
        ll.get_first()
        end = time.perf_counter_ns()

    elif method == "get":
        start = time.perf_counter_ns()
        ll.get(index)
        end = time.perf_counter_ns()

    elif method == "getLast":
        start = time.perf_counter_ns()
        ll.get_last()
        end = time.perf_counter_ns()

    elif method == "removeFirst":
        val = ll.get_first()
        start = time.perf_counter_ns()
        ll.remove_first()
        end = time.perf_counter_ns()
        ll.add_first(val)

    elif method == "remove":
        val = ll.get(index)
        start = time.perf_counter_ns()
        ll.remove_by_index(index)
        end = time.perf_counter_ns()
        ll.add(val, index)

    elif method == "removeLast":
        val = ll.get_last()
        start = time.perf_counter_ns()
        ll.remove_last()
        end = time.perf_counter_ns()
        ll.add_last(val)

    return end - start


def salva_resultado(method, tempo, tamanho):
    file_name = f"{method}.data"
    is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0

    with open(file_name, "a") as file:
        if is_new_file:
            file.write("estrutura-linguagem tempo tamanho_da_entrada\n")
        file.write(f"linkedlist-python {tempo} {tamanho}\n")


def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue

        input_list = list(map(int, line.split()))
        n = len(input_list)

        ll = LinkedList()
        for num in input_list:
            ll.add_last(num)

        for method in methods:
            resultados = []
            for _ in range(101):
                tempo = mede_tempo(ll, method, n)
                resultados.append(tempo)

            mediana = statistics.median(resultados)
            salva_resultado(method, int(mediana), n)


if __name__ == "__main__":
    main()
