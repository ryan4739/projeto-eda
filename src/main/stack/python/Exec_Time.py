import time
import sys
import os
from statistics import median

from stack import Stack

class Exec_Time:
    """
    Classe responsável por medir e registrar os tempos de execução de operações em uma fila.
    Os resultados são salvos em arquivos separados para cada tipo de operação.
    """

    # Nomes dos métodos que serão testados e correspondem aos nomes dos arquivos de saída
    METHOD_NAMES = [
        "remove_last",
        "add_last",
        "get_last",
        "remove_first",
        "add_first",
        "get_first",
        "remove_middle",
        "add_middle",
        "get_middle"
    ]

    @staticmethod
    def main():
        """
        Método principal que coordena a execução do programa.
        Lê o arquivo de entrada, prepara os arquivos de saída e processa cada linha.
        """

        # Verifica se o número de argumentos é válido
        if len(sys.argv) < 2:
            print("ERRO: número de argumentos inválido!")
            return

        input_file = sys.argv[1] # Arquivo de entrada contendo os tamanhos das filas
        output_dir = "data/results/time/" # Diretório onde serão salvos os resultados

        try:
            # Cria o diretório de saída se não existir
            os.makedirs(output_dir, exist_ok=True)

            # Abre os arquivos de saída para escrita
            writers = []
            try:
                for method in ExecTime.METHOD_NAMES:
                    file_path = f"{output_dir}{method}.data"
                    # Abre o arquivo em modo de leitura e append
                    f = open(file_path, 'a+')
                    # Verifica se o arquivo está vazio e adiciona cabeçalho, se necessário
                    if os.fstat(f.fileno()).st_size == 0:
                        f.write("estrutura_linguagem tempo tamanho\n")
                    writers.append(f)
            except IOError as e:
                for f in writers:
                    f.close()
                raise

            # Conta o número total de linhas no arquivo para mostrar progresso
            with open(input_file, 'r') as reader:
                total_lines = sum(1 for line in reader if line.strip())

            # Processa cada linha do arquivo de entrada
            with open(input_file, 'r') as reader:
                current_line = 0
                for line in reader:
                    line = line.strip()
                    if not line:
                        continue

                    current_line += 1
                    print(f"Processando linha {current_line}/{total_lines}", end='\r')

                    # Converte a linha em uma lista de inteiros
                    elements = list(map(int, line.split()))
                    # Testa as operações com os elementos da linha atual
                    ExecTime.test_stack_operations(writers, elements)

            print(f"\rConcluído! Processadas {total_lines} linhas.")

        except IOError as e:
            print(f"Erro ao processar arquivos: {e}")
        finally:
            # Garante que todos os arquivos serão fechados
            for writer in writers:
                writer.close()

    @staticmethod
    def test_stack_operations(writers, elements):
        """
        Testa as operações da fila com os elementos fornecidos e registra os tempos.

        Args:
            writers: Lista de arquivos abertos para escrita dos resultados
            elements: Lista de elementos para preencher a fila inicialmente
        """
        length = len(elements) # Tamanho atual da fila
        middle = length // 2 # Índice do elemento do meio
        RUNS = 30 # Número de execuções para cada operação
        all_times = [[] for _ in range(len(ExecTime.METHOD_NAMES))] # Armazena tempos de cada operação

        # Preenche a fila com os elementos iniciais
        stack = stack(length)
        for num in elements:
            stack.add_last(num)

        # Executa os testes determinada quantia de vezes para extrair a mediana
        for run in range(RUNS):
            # Testa removeLast
            start_time = time.perf_counter_ns()
            stack.pop()
            end_time = time.perf_counter_ns()
            all_times[0].append(end_time - start_time)

            # Testa addLast
            start_time = time.perf_counter_ns()
            stack.push(999)
            end_time = time.perf_counter_ns()
            all_times[1].append(end_time - start_time)

            # Testa getLast
            start_time = time.perf_counter_ns()
            stack.peek()
            end_time = time.perf_counter_ns()
            all_times[2].append(end_time - start_time)

            # Testa removeFirst
            start_time = time.perf_counter_ns()
            stack.popLast()
            end_time = time.perf_counter_ns()
            all_times[3].append(end_time - start_time)

            # Testa addFirst
            start_time = time.perf_counter_ns()
            stack.pushLast(999)
            end_time = time.perf_counter_ns()
            all_times[4].append(end_time - start_time)

            # Testa getFirst
            start_time = time.perf_counter_ns()
            stack.peekLast()
            end_time = time.perf_counter_ns()
            all_times[5].append(end_time - start_time)

            # Testa remove (middle)
            start_time = time.perf_counter_ns()
            stack.popIndex(middle)
            end_time = time.perf_counter_ns()
            all_times[6].append(end_time - start_time)

            # Testa add (middle)
            start_time = time.perf_counter_ns()
            stack.pushIndex(999, middle)
            end_time = time.perf_counter_ns()
            all_times[7].append(end_time - start_time)

            # Testa get (middle)
            start_time = time.perf_counter_ns()
            stack.peekIndex(middle)
            end_time = time.perf_counter_ns()
            all_times[8].append(end_time - start_time)

        # Calcula a mediana dos tempos e escreve nos arquivos
        for i, method in enumerate(ExecTime.METHOD_NAMES):
            if all_times[i]:
                median_time = int(median(all_times[i]))
                writers[i].write(f"stack_python {median_time} {length}\n")
                writers[i].flush()

if __name__ == "__main__":
    ExecTime.main()
