import sys
import time
import os
from linked_list import LinkedList

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
        results = []
        
        for _ in range(30):
            ll = LinkedList()
            for num in input_list:
                ll.add_last(num)
            
            start = 0
            end = 0
            
            if method == "addFirst":
                start = time.perf_counter_ns()
                ll.add_first(10)
                end = time.perf_counter_ns()
            elif method == "add":
                start = time.perf_counter_ns()
                ll.add(10, n // 2)
                end = time.perf_counter_ns()
            elif method == "addLast":
                start = time.perf_counter_ns()
                ll.add_last(10)
                end = time.perf_counter_ns()
            elif method == "getFirst":
                start = time.perf_counter_ns()
                ll.get_first()
                end = time.perf_counter_ns()
            elif method == "get":
                start = time.perf_counter_ns()
                ll.get(n // 2)
                end = time.perf_counter_ns()
            elif method == "getLast":
                start = time.perf_counter_ns()
                ll.get_last()
                end = time.perf_counter_ns()
            elif method == "removeFirst":
                start = time.perf_counter_ns()
                ll.remove_first()
                end = time.perf_counter_ns()
            elif method == "remove":
                start = time.perf_counter_ns()
                ll.remove_by_index(n // 2)
                end = time.perf_counter_ns()
            elif method == "removeLast":
                start = time.perf_counter_ns()
                ll.remove_last()
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