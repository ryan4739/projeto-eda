import sys
import os
import tracemalloc
import gc
import time
from linked_list import LinkedList
from multiprocessing import Process

methods = [
    "add_first", "add_middle", "add_last",
    "get_first", "get_middle", "get_last",
    "remove_first", "remove_middle", "remove_last"
]

def mede_memoria_peak_e_delta(ll, method, n):
    index = n // 2
    gc.collect()
    tracemalloc.start()
    before = tracemalloc.take_snapshot()

    if method == "add_first":
        ll.add_first(10)
        peak = tracemalloc.get_traced_memory()[1]
        ll.remove_first()

    elif method == "add_middle":
        ll.add(10, index)
        peak = tracemalloc.get_traced_memory()[1]
        ll.remove_by_index(index)

    elif method == "add_last":
        ll.add_last(10)
        peak = tracemalloc.get_traced_memory()[1]
        ll.remove_last()

    elif method == "get_first":
        ll.get_first()
        peak = tracemalloc.get_traced_memory()[1]

    elif method == "get_middle":
        ll.get(index)
        peak = tracemalloc.get_traced_memory()[1]

    elif method == "get_last":
        ll.get_last()
        peak = tracemalloc.get_traced_memory()[1]

    elif method == "remove_first":
        val = ll.get_first()
        ll.remove_first()
        peak = tracemalloc.get_traced_memory()[1]
        ll.add_first(val)

    elif method == "remove_middle":
        val = ll.get(index)
        ll.remove_by_index(index)
        peak = tracemalloc.get_traced_memory()[1]
        ll.add(val, index)

    elif method == "remove_last":
        val = ll.get_last()
        ll.remove_last()
        peak = tracemalloc.get_traced_memory()[1]
        ll.add_last(val)

    after = tracemalloc.take_snapshot()
    tracemalloc.stop()

    diff = after.compare_to(before, 'filename')
    delta = sum(stat.size_diff for stat in diff if "linked_list" in stat.traceback[0].filename)

    return int(peak), int(delta)

def salva_resultado(method, peak_bytes, delta_bytes, tamanho):
    file_name = f"{method}.data"
    is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0

    with open(file_name, "a") as file:
        if is_new_file:
            file.write("estrutura_linguagem memoria tamanho\n")
        file.write(f"linkedlist_python {peak_bytes} {tamanho}\n")

def processa_method(method, input_list, n):
    ll = LinkedList()
    for num in input_list:
        ll.add_last(num)

    peaks = []
    deltas = []

    for _ in range(101):
        peak, delta = mede_memoria_peak_e_delta(ll, method, n)
        peaks.append(peak)
        deltas.append(delta)

    peaks.sort()
    deltas.sort()
    med_peak = peaks[50]
    med_delta = deltas[50]

    salva_resultado(method, med_peak, med_delta, n)

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue

        input_list = list(map(int, line.split()))
        n = len(input_list)

        # Cria um processo separado por método
        processes = []
        for method in methods:
            p = Process(target=processa_method, args=(method, input_list, n))
            p.start()
            processes.append(p)

        for p in processes:
            p.join()

if __name__ == "__main__":
    main()
