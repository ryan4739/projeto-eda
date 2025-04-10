import sys
import time
import os
from stack import Stack  # Assuming Stack class is in stack.py

methods = ["pushIndex", "push", "pushLast", 
           "popIndex", "pop", "popLast", 
           "peekIndex", "peek", "peekLast"]

for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    
    input_list = list(map(int, line.split()))
    n = len(input_list)
    
    for method in methods:
        results = []
        
        for _ in range(30):
            stack = Stack(60)  #inicializar com 60
            for num in input_list:
                stack.push(num)  # encher a stack
            
            start = 0
            end = 0
            
            if method == "pushIndex":
                start = time.perf_counter_ns()
                stack.pushIndex(10, n // 2)  # Insert at middle
                end = time.perf_counter_ns()
            elif method == "push":
                start = time.perf_counter_ns()
                stack.push(10)  # Push to top
                end = time.perf_counter_ns()
            elif method == "pushLast":
                start = time.perf_counter_ns()
                stack.pushLast(10)  # Push to bottom
                end = time.perf_counter_ns()
            elif method == "popIndex":
                start = time.perf_counter_ns()
                stack.popIndex(n // 2)  # Remove from middle
                end = time.perf_counter_ns()
            elif method == "pop":
                start = time.perf_counter_ns()
                stack.pop()  # Remove from top
                end = time.perf_counter_ns()
            elif method == "popLast":
                start = time.perf_counter_ns()
                stack.popLast()  # Remove from bottom
                end = time.perf_counter_ns()
            elif method == "peekIndex":
                start = time.perf_counter_ns()
                stack.peekIndex(n // 2)  # Peek middle
                end = time.perf_counter_ns()
            elif method == "peek":
                start = time.perf_counter_ns()
                stack.peek()  # Peek top
                end = time.perf_counter_ns()
            elif method == "peekLast":
                start = time.perf_counter_ns()
                stack.peekLast()  # Peek bottom
                end = time.perf_counter_ns()
            
            results.append(end - start)
        
        results = sorted(results)
        median_time = results[14]  # Median of 30 runs (index 14)
        output_line = f"stack-python {median_time} {n}"
        
        file_name = f"{method}.data"
        is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0
        
        with open(file_name, "a") as file:
            if is_new_file:
                file.write("estrutura-linguagem tempo tamanho_da_entrada\n")
            file.write(output_line + "\n")
