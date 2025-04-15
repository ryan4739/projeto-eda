import time
import sys
import os
from statistics import median

from ArrayList import ArrayList 

class ExecTime:
    """
    Classe responsável por medir e registrar os tempos de execução de operações em uma ArrayList.
    Os resultados são salvos em arquivos separados para cada tipo de operação.
    """

    METHOD_NAMES = [
        "rmv_last",
        "add_last",
        "get_last",
        "rmv_first",
        "add_first",
        "get_first",
        "rmv_middle",
        "add_middle",
        "get_middle"
    ]

    @staticmethod
    def main():
        if len(sys.argv) < 2:
            print("ERRO: número de argumentos inválido!")
            return

        input_file = sys.argv[1]
        output_dir = "data/results/time/"

        try:
            os.makedirs(output_dir, exist_ok=True)

            writers = []
            try:
                for method in ExecTime.METHOD_NAMES:
                    file_path = f"{output_dir}{method}.data"
                    f = open(file_path, 'a+')
                    if os.fstat(f.fileno()).st_size == 0:
                        f.write("estrutura_linguagem tempo tamanho\n")
                    writers.append(f)
            except IOError as e:
                for f in writers:
                    f.close()
                raise

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
                    ExecTime.test_arraylist_operations(writers, elements)

            print(f"\rConcluído! Processadas {total_lines} linhas.")

        except IOError as e:
            print(f"Erro ao processar arquivos: {e}")
        finally:
            for writer in writers:
                writer.close()

    @staticmethod
    def test_arraylist_operations(writers, elements):
        length = len(elements)
        middle = length // 2
        RUNS = 30
        all_times = [[] for _ in range(len(ExecTime.METHOD_NAMES))]

        # Como a ArrayList é imutável, precisamos reatribuir em cada operação
        array_list = ArrayList(elements)

        for run in range(RUNS):
            # Testa rmvLast
            start_time = time.perf_counter_ns()
            new_list = array_list.rmvLast()
            end_time = time.perf_counter_ns()
            all_times[0].append(end_time - start_time)
            array_list = ArrayList(new_list)  # Atualiza com o novo estado

            # Testa addLast
            start_time = time.perf_counter_ns()
            new_list = array_list.addLast(999)
            end_time = time.perf_counter_ns()
            all_times[1].append(end_time - start_time)
            array_list = ArrayList(new_list)

            # Testa getLast
            start_time = time.perf_counter_ns()
            array_list.getLast()
            end_time = time.perf_counter_ns()
            all_times[2].append(end_time - start_time)

            # Testa rmvFirst
            start_time = time.perf_counter_ns()
            new_list = array_list.rmvFirst()
            end_time = time.perf_counter_ns()
            all_times[3].append(end_time - start_time)
            array_list = ArrayList(new_list)

            # Testa addFirst
            start_time = time.perf_counter_ns()
            new_list = array_list.addFirst(999)
            end_time = time.perf_counter_ns()
            all_times[4].append(end_time - start_time)
            array_list = ArrayList(new_list)

            # Testa getFirst
            start_time = time.perf_counter_ns()
            array_list.getFirst()
            end_time = time.perf_counter_ns()
            all_times[5].append(end_time - start_time)

            # Testa rmvIndex (middle)
            start_time = time.perf_counter_ns()
            new_list = array_list.rmvIndex(middle)
            end_time = time.perf_counter_ns()
            all_times[6].append(end_time - start_time)
            array_list = ArrayList(new_list)

            # Testa addIndex (middle)
            start_time = time.perf_counter_ns()
            new_list = array_list.addIndex(999, middle)
            end_time = time.perf_counter_ns()
            all_times[7].append(end_time - start_time)
            array_list = ArrayList(new_list)

            # Testa get (middle)
            start_time = time.perf_counter_ns()
            array_list.get(middle)
            end_time = time.perf_counter_ns()
            all_times[8].append(end_time - start_time)

        for i, method in enumerate(ExecTime.METHOD_NAMES):
            if all_times[i]:
                median_time = int(median(all_times[i]))
                writers[i].write(f"arraylist_python {median_time} {length}\n")
                writers[i].flush()

if __name__ == "__main__":
    ExecTime.main()
