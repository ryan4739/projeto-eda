from collections import deque
from memory_profiler import profile
import timeit
import random

def append_left(dq: deque,entrada):
    for i in range(entrada):
        dq.appendleft(i)
    return dq

def append_right(dq: deque,entrada):
    for i in range(entrada):
        dq.append(i)
    return dq

def extend_left(dq: deque, valores):    
    dq.extendleft(valores)
    return dq

def extend_right(dq: deque, valores):    
    dq.extend(valores)
    return dq

def pop_left(dq: deque):
    while dq: 
        dq.popleft()
    return dq

def pop_right(dq: deque):
    while dq:
        dq.pop()
    return dq

def access_left(dq: deque):
    return dq[0]

def access_right(dq: deque):
    return dq[-1]

def access_random(dq: deque):
    if not dq:
        return None
    index = random.randint(0, len(dq) - 1)
    return dq[index]

def rotate_deque(dq: deque, n: int):   
    dq.rotate(n)
    return dq

def remove_value(dq: deque, value):    
    try:
        dq.remove(value)
    except ValueError:
        pass  # Ignora erro se o valor não estiver no deque
    return dq

def count_value(dq: deque, value):    
    return dq.count(value)


