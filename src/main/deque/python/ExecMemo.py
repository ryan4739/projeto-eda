import sys
import os
import tracemalloc
from deque import Deque


def measure_memory(func_name, input_list):
    n = len(input_list)
    dq = Deque(n+1)
    for num in input_list:
        dq.add_last(num)
    
    func = getattr(dq, func_name)

    if not callable(func):
        raise ValueError(f"'{func_name}' não é uma função válida do objeto.")
    else:
        tracemalloc.start()
        snapshot1 = tracemalloc.take_snapshot()

        # Executa o método
        if func_name.endswith("last") or func_name.endswith("first"):
            if func_name.startswith("add"):
                func(10)
            else:
                func()
        else:
            func(10, n//2)

        snapshot2 = tracemalloc.take_snapshot()
        tracemalloc.stop()

        stats = snapshot2.compare_to(snapshot1, 'lineno')
        peak_memory = sum([stat.size_diff for stat in stats])
    
    output_line = f"deque-python {peak_memory} {n}"

    output_dir = "data/results/memory"
    os.makedirs(output_dir, exist_ok=True)  # Garante que a pasta exista
    file_name = os.path.join(output_dir, f"{func_name}MEMO.data")
    is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0

    with open(file_name, "a") as file:
        if is_new_file:
            file.write("estrutura_linguagem memoria tamanho\n")
        file.write(output_line + "\n")

methods = ["add_first", "add_last", 
           "get_first", "get_last",
           "remove_first", "remove_last"]

for line in sys.stdin:
    line = line.strip()
    if not line:
        continue

    input_list = list(map(int, line.split()))
    
    for method in methods:
        measure_memory(method, input_list)
