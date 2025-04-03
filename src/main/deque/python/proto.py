import sys
import time
import tracemalloc
from deque import Deque


def measure_time(obj, func_name, *args):
    tempo = 0
    func = getattr(obj, func_name)  # Obtém a função da classe do objeto
    if not callable(func):
        raise ValueError(f"'{func_name}' não é uma função válida do objeto.")
    else:
        for _ in range(30):
            start = time.perf_counter_ns()
            func(*args)
            end = time.perf_counter_ns()
            tempo+=end - start
    return (tempo/30)

def measure_memory(obj, func_name, *args):
    memory_usage = 0
    func = getattr(obj, func_name)
    if not callable(func):
        raise ValueError(f"'{func_name}' não é uma função válida do objeto.")
    else:
        tracemalloc.start()  # Inicia o rastreamento de memória antes do loop

        memory_usages = []  # Lista para armazenar o consumo de memória

        for _ in range(30):  # Executa 30 vezes para obter uma média
            snapshot_before = tracemalloc.take_snapshot()
            func(*args)  
            snapshot_after = tracemalloc.take_snapshot()

            # Calcula a diferença de memória entre os snapshots
            stats = snapshot_after.compare_to(snapshot_before, 'lineno')
            total_memory = sum(stat.size for stat in stats) / 1024  # Convertendo para KiB

            memory_usages.append(total_memory)

        tracemalloc.stop()  # Para o rastreamento após os testes

        return sum(memory_usages) / len(memory_usages)
    
#cria um objeto da classe a ser usada
obj = Deque(100)
#nome da função a ser usada
nome_da_funcao = "extend_right"
#imput da função(caso ela receba algum argumento que não seja um array)
index = None
#tup = (30, 40, 32, 1,4, 2, 44,2 ,2,3,34,2 ,223,34,24 , 4, 24, 2, 2,21 ,9)


for line in sys.stdin:
    line = line.strip()
    if not line:
        continue

    nums = list(map(int, line.split())) 
    size = len(nums)
    
        
    #se o método utilizado tiver algum parametro colocar após nome da função
    tempo_de_processamento = measure_time(obj, nome_da_funcao, nums)
    print(f"python {nome_da_funcao} {tempo_de_processamento:.6f} {size}")