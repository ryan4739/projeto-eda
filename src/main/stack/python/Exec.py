import sys
import time
import os
from linked_list import LinkedList

methods = ["pushIndex", "push", "PushLast", 
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
            ll = Stack(60)
            for num in input_list:
                ll.push(num)
            
            start = 0
            end = 0
            
            if method == "pushIndex":
                start = time.perf_counter_ns()
                ll.pushIndex(10)
                end = time.perf_counter_ns()
            elif method == "push":
                start = time.perf_counter_ns()
                ll.push(10, n // 2)
                end = time.perf_counter_ns()
            elif method == "PushLast":
                start = time.perf_counter_ns()
                ll.PushLast(10)
                end = time.perf_counter_ns()
            elif method == "peekIndex":
                start = time.perf_counter_ns()
                ll.peekIndex()
                end = time.perf_counter_ns()
            elif method == "peek":
                start = time.perf_counter_ns()
                ll.peek(n // 2)
                end = time.perf_counter_ns()
            elif method == "peekLast":
                start = time.perf_counter_ns()
                ll.peekLast()
                end = time.perf_counter_ns()
            elif method == "removeIndex":
                start = time.perf_counter_ns()
                ll.removeIndex()
                end = time.perf_counter_ns()
            elif method == "pop":
                start = time.perf_counter_ns()
                ll.pop(n // 2)
                end = time.perf_counter_ns()
            elif method == "removeLast":
                start = time.perf_counter_ns()
                ll.removeLast()
                end = time.perf_counter_ns()
            results.append(end - start)
        
        results = sorted(results)
        output_line = f"linkedlist-python {results[14]} {n}"
        
        file_name = f"{method}.data"
        is_new_file = not os.path.exists(file_name) or os.stat(file_name).st_size == 0
        
        with open(file_name, "a") as file:
            if is_new_file:
                file.write("estrutura-linguagem tempo tamanho_da_entrada\n")
            file.write(output_line + "\n")
