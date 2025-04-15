import sys
import os
import tracemalloc
from statistics import median
from deque import Deque

output_dir = "data/results/memory"
os.makedirs(output_dir, exist_ok=True)

methods = ["add_first", "add_last", "add_middle",
           "remove_first", "remove_last", "remove_middle",
           "get_first", "get_last", "get_middle"]

def mem_diff(snapshot1, snapshot2):
    return sum(stat.size_diff for stat in snapshot2.compare_to(snapshot1, 'lineno'))

def write_result(method, median_mem, n):
    file_path = os.path.join(output_dir, f"{method}MEMO.data")
    is_new_file = not os.path.exists(file_path) or os.stat(file_path).st_size == 0

    with open(file_path, "a") as f:
        if is_new_file:
            f.write("estrutura_linguagem memoria tamanho\n")
        f.write(f"deque-python {median_mem} {n}\n")

for line_number, line in enumerate(sys.stdin, 1):
    line = line.strip()
    if not line:
        continue

    print(f"[+] Processando linha {line_number}...", file=sys.stderr)

    input_list = list(map(int, line.split()))
    n = len(input_list)
    middle = n // 2

    dq = Deque(n + 2)
    for num in input_list:
        dq.add_last(num)

    mem_usage = {method: [] for method in methods}

    for _ in range(30):
        # ADD FIRST
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.add_first(999)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        dq.remove_first()
        mem_usage["add_first"].append(mem_diff(snapshot1, snapshot2))

        # ADD LAST
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.add_last(999)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        dq.remove_last()
        mem_usage["add_last"].append(mem_diff(snapshot1, snapshot2))

        # ADD (middle)
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.add(999, middle)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        dq.remove(middle)
        mem_usage["add_middle"].append(mem_diff(snapshot1, snapshot2))

        val = dq.get_first()
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.remove_first()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        dq.addFirst(val)
        mem_usage["remove_first"].append(mem_diff(snapshot1, snapshot2))

        val = dq.get_last()
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.remove_last()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        dq.add_last(val)
        mem_usage["remove_last"].append(mem_diff(snapshot1, snapshot2))

        val = dq.get(middle)
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.remove(middle)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        dq.add(middle, val)
        mem_usage["remove_middle"].append(mem_diff(snapshot1, snapshot2))

        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.get_first()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["get_first"].append(mem_diff(snapshot1, snapshot2))

        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.get_last()
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["get_last"].append(mem_diff(snapshot1, snapshot2))

        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()
        dq.get(middle)
        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()
        mem_usage["get_middle"].append(mem_diff(snapshot1, snapshot2))

    for method in methods:
        write_result(method, sorted(mem_usage[method])[14], n)
