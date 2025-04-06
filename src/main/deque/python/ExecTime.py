import sys
import time
import os
from deque import Deque


def measure_time(func_name, input_list):
    n = len(input_list)
    results = []
    dq = Deque(1000)
    for num in input_list:
        dq.add_last(num)
    for _ in range(30):
            func = getattr(dq, func_name) 
            if not callable(func):
                raise ValueError(f"'{func_name}' não é uma função válida do objeto.")
            else:
                if func_name.endswith("last") or func_name.endswith("first"):
                    if func_name.startswith("add"):
                        start = time.perf_counter_ns()
                        func(10)
                        end = time.perf_counter_ns()

                    else:
                        start = time.perf_counter_ns()
                        func()
                        end = time.perf_counter_ns()
                else:
                    start = time.perf_counter_ns()
                    func(10, n//2)
                    end = time.perf_counter_ns()

                results.append(end - start)
    results = sorted(results)
    output_line = f"deque-python {results[14]} {n}"
    
    file_name = f"{func_name}.data"
    is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0
    
    with open(file_name, "a") as file:
        if is_new_file:
            file.write("estrutura-linguagem tempo tamanho_da_entrada\n")
        file.write(output_line + "\n")

methods = ["add_first", "add_last", 
           "get_first", "get_last",
           "remove_first", "remove_last"]



for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    
    input_list = list(map(int, line.split()))
    n = len(input_list)
    
    for method in methods:
        measure_time(method,input_list)
