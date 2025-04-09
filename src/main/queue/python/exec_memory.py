import sys
import os
import tracemalloc
from statistics import median

from queue import Queue

class ExecMemory:
    METHOD_NAMES = [
        "addLast",
        "addFirst",
        "add",
        "removeFirst",
        "removeLast",
        "remove",
        "getFirst",
        "getLast",
        "get"
    ]

    @staticmethod
    def main():
        if len(sys.argv) < 2:
            print("Uso: python exec_memory.py <arquivo_entrada>")
            return

        input_file = sys.argv[1]
        output_dir = "data/results/memory/"

        try:
            # Cria o diretório de saída se não existir
            os.makedirs(output_dir, exist_ok=True)

            # Abre os arquivos de saída para escrita
            writers = []
            for method in ExecMemory.METHOD_NAMES:
                writers.append(open(f"{output_dir}{method}.data", "a"))

            # Conta o número total de linhas no arquivo
            with open(input_file, 'r') as reader:
                total_lines = sum(1 for line in reader if line.strip())

            with open(input_file, 'r') as reader:
                current_line = 0
                for line in reader:
                    line = line.strip()
                    if not line:
                        continue

                    current_line += 1
                    print(f"Processando linha {current_line}/{total_lines}", end='\r')

                    elements = list(map(int, line.split()))
                    ExecMemory.test_queue_operations(writers, elements)

            print(f"Concluído! Processadas {total_lines} linhas.")

        except IOError as e:
            print(f"\nErro ao processar arquivos: {e}")
        finally:
            # Fecha todos os arquivos de saída
            for writer in writers:
                writer.close()

    @staticmethod
    def test_queue_operations(writers, elements):
        length = len(elements)
        middle = length // 2
        RUNS = 5
        all_memory = [[] for _ in range(len(ExecMemory.METHOD_NAMES))]

        for run in range(RUNS):
            queue = Queue(length + 1)

            # Preenche a fila com os elementos iniciais
            for num in elements:
                queue.add_last(num)

            # Testa addLast
            tracemalloc.start()
            queue.add_last(999)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[0].append(peak)
            tracemalloc.stop()
            queue.remove_last()

            # Testa addFirst
            tracemalloc.start()
            queue.add_first(999)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[1].append(peak)
            tracemalloc.stop()
            queue.remove_first()

            # Testa add (middle)
            tracemalloc.start()
            queue.add(999, middle)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[2].append(peak)
            tracemalloc.stop()
            queue.remove(middle)

            # Testa removeFirst
            tracemalloc.start()
            queue.remove_first()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[3].append(peak)
            tracemalloc.stop()
            queue.add_first(elements[0])

            # Testa removeLast
            tracemalloc.start()
            queue.remove_last()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[4].append(peak)
            tracemalloc.stop()
            queue.add_last(elements[-1])

            # Testa remove (middle)
            tracemalloc.start()
            queue.remove(middle)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[5].append(peak)
            tracemalloc.stop()
            queue.add_last(999)

            # Testa getFirst
            tracemalloc.start()
            queue.get_first()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[6].append(peak)
            tracemalloc.stop()

            # Testa getLast
            tracemalloc.start()
            queue.get_last()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[7].append(peak)
            tracemalloc.stop()

            # Testa get (middle)
            tracemalloc.start()
            queue.get(middle)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[8].append(peak)
            tracemalloc.stop()

        # Calcula a mediana do uso de memória e escreve nos arquivos
        for i, method in enumerate(ExecMemory.METHOD_NAMES):
            if all_memory[i]:
                median_memory = int(median(all_memory[i]))
                writers[i].write(f"queue-python {median_memory} {length}\n")
                writers[i].flush()

if __name__ == "__main__":
    ExecMemory.main()
