import sys
import time
import os
from deque import Deque

output_dir = "data/results/time"
os.makedirs(output_dir, exist_ok=True)
def measure_time(func_name, input_list):
    n = len(input_list)
    results = []
    dq = Deque(n+1)
    
    for _ in range(30):
        for num in input_list:
            dq.addLast(num)

        func = getattr(dq, func_name)
        if not callable(func):
            raise ValueError(f"'{func_name}' não é uma função válida do objeto.")
        
        start = time.perf_counter_ns()

        if func_name in ["addFirst", "addLast"]:
            func(10)
        elif func_name == "add":
            func(10, n//2)
        elif func_name in ["getFirst", "getLast", "removeFirst", "removeLast"]:
            func()
        elif func_name in ["get", "remove"]:
            func(n//2)
        else:
            raise ValueError(f"Função '{func_name}' não reconhecida.")

        end = time.perf_counter_ns()
        results.append(end - start)

    results = sorted(results)
    output_line = f"deque-python {results[14]} {n}"

    file_path = os.path.join(output_dir, f"{func_name}.data")
    is_new_file = not os.path.exists(file_path) or os.stat(file_path).st_size == 0    

    with open(file_path, "a") as file:
        if is_new_file:
            file.write("estrutura-linguagem tempo tamanho_da_entrada\n")
        file.write(output_line + "\n")


methods = ["addFirst", "add", "addLast",
    "getFirst", "get", "getLast",
    "removeFirst", "remove", "removeLast"]



for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    
    input_list = list(map(int, line.split()))
    n = len(input_list)
    
    for method in methods:
        measure_time(method,input_list)
