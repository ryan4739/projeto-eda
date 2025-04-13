import sys
import os
import tracemalloc
from statistics import median

from queue import Queue

class ExecMemory:
    """
    Classe responsável por medir e registrar as memórias de execução de operações em uma fila.
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
        output_dir = "data/results/memory/" # Diretório onde serão salvos os resultados

        try:
            # Cria o diretório de saída se não existir
            os.makedirs(output_dir, exist_ok=True)

            # Abre os arquivos de saída para escrita
            writers = []
            try:
                for method in ExecMemory.METHOD_NAMES:
                    file_path = f"{output_dir}{method}.data"
                    # Abre o arquivo em modo de leitura e append
                    f = open(file_path, 'a+')
                    # Verifica se o arquivo está vazio e adiciona cabeçalho, se necessário
                    if os.fstat(f.fileno()).st_size == 0:
                        f.write("estrutura_linguagem memoria tamanho\n")
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
                    ExecMemory.test_queue_operations(writers, elements)

            print(f"\rConcluído! Processadas {total_lines} linhas.")

        except IOError as e:
            print(f"Erro ao processar arquivos: {e}")
        finally:
            # Garante que todos os arquivos serão fechados
            for writer in writers:
                writer.close()

    @staticmethod
    def test_queue_operations(writers, elements):
        """
        Testa as operações da fila com os elementos fornecidos e registra as memórias.

        Args:
            writers: Lista de arquivos abertos para escrita dos resultados
            elements: Lista de elementos para preencher a fila inicialmente
        """
        length = len(elements) # Tamanho atual da fila
        middle = length // 2 # Índice do elemento do meio
        RUNS = 30 # Número de execuções para cada operação
        all_memory = [[] for _ in range(len(ExecMemory.METHOD_NAMES))] # Armazena tempos de cada operação

        # Preenche a fila com os elementos iniciais
        queue = Queue(length)
        for num in elements:
            queue.add_last(num)

        # Executa os testes determinada quantia de vezes para extrair a mediana
        for run in range(RUNS):
            # Testa removeLast
            tracemalloc.start()
            queue.remove_last()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[0].append(peak)
            tracemalloc.stop()

            # Testa addLast
            tracemalloc.start()
            queue.add_last(999)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[1].append(peak)
            tracemalloc.stop()

            # Testa getLast
            tracemalloc.start()
            queue.get_last()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[2].append(peak)
            tracemalloc.stop()

            # Testa removeFirst
            tracemalloc.start()
            queue.remove_first()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[3].append(peak)
            tracemalloc.stop()

            # Testa addFirst
            tracemalloc.start()
            queue.add_first(999)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[4].append(peak)
            tracemalloc.stop()

            # Testa getFirst
            tracemalloc.start()
            queue.get_first()
            current, peak = tracemalloc.get_traced_memory()
            all_memory[5].append(peak)
            tracemalloc.stop()

            # Testa remove (middle)
            tracemalloc.start()
            queue.remove(middle)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[6].append(peak)
            tracemalloc.stop()

            # Testa add (middle)
            tracemalloc.start()
            queue.add(999, middle)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[7].append(peak)
            tracemalloc.stop()

            # Testa get (middle)
            tracemalloc.start()
            queue.get(middle)
            current, peak = tracemalloc.get_traced_memory()
            all_memory[8].append(peak)
            tracemalloc.stop()

        # Calcula a mediana dos tempos e escreve nos arquivos
        for i, method in enumerate(ExecMemory.METHOD_NAMES):
            if all_memory[i]:
                median_memory = int(median(all_memory[i]))
                writers[i].write(f"queue_python {median_memory} {length}\n")
                writers[i].flush()

if __name__ == "__main__":
    ExecMemory.main()

