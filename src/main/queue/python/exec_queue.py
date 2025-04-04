import time
import sys
from statistics import median

from queue import Queue

class ExecQueue:
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
            print("Uso: python exec_queue.py <arquivo_entrada>")
            return

        input_file = sys.argv[1]
        output_dir = "data/results/time/"

        try:
            # Cria o diretório de saída se não existir
            import os
            os.makedirs(output_dir, exist_ok=True)

            # Abre os arquivos de saída para escrita
            writers = []
            for method in ExecQueue.METHOD_NAMES:
                writers.append(open(f"{output_dir}{method}.data", "a"))

            with open(input_file, 'r') as reader:
                for line in reader:
                    line = line.strip()
                    if not line:
                        continue

                    elements = list(map(int, line.split()))
                    ExecQueue.test_queue_operations(writers, elements)

        except IOError as e:
            print(f"Erro ao processar arquivos: {e}")
        finally:
            # Fecha todos os arquivos de saída
            for writer in writers:
                writer.close()

    @staticmethod
    def test_queue_operations(writers, elements):
        length = len(elements)
        middle = length // 2
        RUNS = 30
        all_times = [[] for _ in range(len(ExecQueue.METHOD_NAMES))]

        for run in range(RUNS):
            queue = Queue(length + 1)

            # Preenche a fila com os elementos iniciais
            for num in elements:
                queue.add_last(num)

            # Testa addLast
            start_time = time.perf_counter_ns()
            queue.add_last(999)
            end_time = time.perf_counter_ns()
            all_times[0].append(end_time - start_time)
            queue.remove_last()

            # Testa addFirst
            start_time = time.perf_counter_ns()
            queue.add_first(999)
            end_time = time.perf_counter_ns()
            all_times[1].append(end_time - start_time)
            queue.remove_first()

            # Testa add (middle)
            start_time = time.perf_counter_ns()
            queue.add(999, middle)
            end_time = time.perf_counter_ns()
            all_times[2].append(end_time - start_time)
            queue.remove(middle)

            # Testa removeFirst
            start_time = time.perf_counter_ns()
            queue.remove_first()
            end_time = time.perf_counter_ns()
            all_times[3].append(end_time - start_time)
            queue.add_first(elements[0])

            # Testa removeLast
            start_time = time.perf_counter_ns()
            queue.remove_last()
            end_time = time.perf_counter_ns()
            all_times[4].append(end_time - start_time)
            queue.add_last(elements[-1])

            # Testa remove (middle)
            start_time = time.perf_counter_ns()
            queue.remove(middle)
            end_time = time.perf_counter_ns()
            all_times[5].append(end_time - start_time)
            queue.add_last(999)

            # Testa getFirst
            start_time = time.perf_counter_ns()
            queue.get_first()
            end_time = time.perf_counter_ns()
            all_times[6].append(end_time - start_time)

            # Testa getLast
            start_time = time.perf_counter_ns()
            queue.get_last()
            end_time = time.perf_counter_ns()
            all_times[7].append(end_time - start_time)

            # Testa get (middle)
            start_time = time.perf_counter_ns()
            queue.get(middle)
            end_time = time.perf_counter_ns()
            all_times[8].append(end_time - start_time)

        # Calcula a mediana dos tempos e escreve nos arquivos
        for i, method in enumerate(ExecQueue.METHOD_NAMES):
            if all_times[i]:
                median_time = int(median(all_times[i]))
                writers[i].write(f"queue-python {median_time} {length}\n")
                writers[i].flush()

if __name__ == "__main__":
    ExecQueue.main()
