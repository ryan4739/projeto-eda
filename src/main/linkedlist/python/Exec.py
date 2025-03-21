from linked_list import LinkedList
from time import perf_counter_ns
import sys

valores = sys.stdin.read().strip().split("\n")  

for valor in valores:
    ll = LinkedList()
    for v in valor:
        ll.add_last(v)

    start_time = perf_counter_ns()
    # Método sendo testado
    # ll.[...]

    end_time = perf_counter_ns()

    time = end_time - start_time
    print(f"linkedlist {time} {ll.size_ll()}")
