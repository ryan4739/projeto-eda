import sys
import os
import tracemalloc
from deque import Deque


def measure_memory(func_name, input_list):
    n = len(input_list)
    dq = Deque(n)
    for num in input_list:
        dq.add_last(num)

    func = getattr(dq, func_name)

    if not callable(func):
        raise ValueError(f"'{func_name}' não é uma função válida do objeto.")
    else:
        tracemalloc.start()
        if func_name.endswith("last") or func_name.endswith("first"):
            if func_name.startswith("add"):
                func(10)
            else:
                func()
        else:
            func(10,n//2)
        current, peak_memory = tracemalloc.get_traced_memory()
        tracemalloc.stop()

    output_line = f"deque-python {peak_memory}(bytes) {n}"

    file_name = f"{func_name}MEMO.data"
    is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0

    with open(file_name, "a") as file:
        if is_new_file:
            file.write("estrutura-linguagem pico_da_memoria tamanho_da_entrada\n")
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
