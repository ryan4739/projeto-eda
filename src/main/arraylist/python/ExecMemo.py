import sys
import os
import tracemalloc
from statistics import median
from ArrayList import ArrayList

output_dir = "data/results/memory"
os.makedirs(output_dir, exist_ok=True)

methods = ["add_first",
           "add_last",
           "add_middle",
           "remove_first",
           "remove_last",
           "remove_middle",
           "get_first",
           "get_last",
           "get_middle"]

def mem_diff(snapshot1, snapshot2):
    return sum(stat.size_diff for stat in snapshot2.compare_to(snapshot1, 'lineno'))

def write_result(method, median_mem, n):
    file_path = os.path.join(output_dir, f"{method}.data")
    is_new_file = not os.path.exists(file_path) or os.stat(file_path).st_size == 0

    with open(file_path, "a") as f:
        if is_new_file:
            f.write("estrutura_linguagem memoria tamanho\n")
        f.write(f"arraylist-python {median_mem} {n}\n")

for line_number, line in enumerate(sys.stdin, 1):
    line = line.strip()
    if not line:
        continue

    print(f"[+] Processando linha {line_number}...", file=sys.stderr)

    input_list = list(map(int, line.split()))
    n = len(input_list)
    middle = n // 2

    # Inicializa a ArrayList com os elementos de entrada
    array_list = ArrayList(input_list)
    
    mem_usage = {method: [] for method in methods}

    for _ in range(30):
        # Testa addFirst
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        new_list = array_list.addFirst(999)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["add_first"].append(mem_diff(snapshot1, snapshot2))
        array_list = ArrayList(new_list)  # Atualiza a referência

        # Testa addLast
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        new_list = array_list.addLast(999)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["add_last"].append(mem_diff(snapshot1, snapshot2))
        array_list = ArrayList(new_list)

        # Testa addIndex (middle)
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        new_list = array_list.addIndex(999, middle)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["add_middle"].append(mem_diff(snapshot1, snapshot2))
        array_list = ArrayList(new_list)

        # Testa rmvFirst
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        new_list = array_list.rmvFirst()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["remove_first"].append(mem_diff(snapshot1, snapshot2))
        array_list = ArrayList(new_list)

        # Testa rmvLast
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        new_list = array_list.rmvLast()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["remove_last"].append(mem_diff(snapshot1, snapshot2))
        array_list = ArrayList(new_list)

        # Testa rmvIndex (middle)
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        new_list = array_list.rmvIndex(middle)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["remove_middle"].append(mem_diff(snapshot1, snapshot2))
        array_list = ArrayList(new_list)

        # Testa getFirst
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        array_list.getFirst()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["get_first"].append(mem_diff(snapshot1, snapshot2))

        # Testa getLast
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        array_list.getLast()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["get_last"].append(mem_diff(snapshot1, snapshot2))

        # Testa get (middle)
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        array_list.get(middle)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["get_middle"].append(mem_diff(snapshot1, snapshot2))

    for method in methods:
        write_result(method, sorted(mem_usage[method])[14], n)
