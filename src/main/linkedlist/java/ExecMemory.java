import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// Inclui a biblioteca para contagem de alocação de memória
import org.github.jamm.MemoryMeter;
// Comando de compilação sugerido:
// javac -cp lib/jamm-0.4.0.jar src/main/linkedlist/java/*.java
// Comando de execução sugerido:
// java -cp lib/jamm-0.4.0.jar:src/main/linkedlist/java ExecMemory <arquivo_de_entrada>

/**
 * Classe para medição de consumo de memória de operações em uma estrutura ll.
 * Gera arquivos de saída com os picos de memória medidos para análise.
 */
public class ExecMemory {
    // Nomes das operações que serão medidas
    private static final String[] METHOD_NAMES = {
        "remove_last",
        "add_last",
        "get_last",
        "remove_first",
        "add_first",
        "get_first",
        "remove_middle",
        "add_middle",
        "get_middle"
    };

    // Número de execuções para medição (deve ser ímpar para cálculo da mediana)
    private static final int MEASUREMENT_RUNS = 5;
    // Diretório de saída
    private static final String OUTPUT_DIR = "data/results/memory/";
    // Instância do medidor de memória JAMM
    private static final MemoryMeter memoryMeter = MemoryMeter.builder().build();
    
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("ERRO: nenhum argumento!");
            System.exit(1);
        }

        // Arquivo de entrada com os dados de teste
        String inputFile = args[0];
        // Garante que o diretório de saída existe
        createOutputDirectory();

        try {
            // Lê todas as linhas do arquivo de entrada
            List<String> lines = readAllLines(inputFile);
            // Inicializa writers para os arquivos de saída
            PrintWriter[] writers = initializeWriters();

            // Processa cada linha e realiza as medições
            processLines(lines, writers);

            // Fecha todos os arquivos de saída
            closeWriters(writers);
            System.out.printf("\rFinalizado! Processadas %d linhas.%n", lines.size());
        } catch (IOException e) {
            System.err.println("ERRO: " + e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }

    private static void createOutputDirectory() {
        File outputDirFile = new File(OUTPUT_DIR);
        if (!outputDirFile.exists() && !outputDirFile.mkdirs()) {
            System.err.println("Falha ao criar diretório de saída: " + OUTPUT_DIR);
            System.exit(1);
        }
    }

    private static List<String> readAllLines(String inputFile) throws IOException {
        List<String> lines = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (!line.isBlank()) {
                    lines.add(line);
                }
            }
        }
        return lines;
    }

    private static PrintWriter[] initializeWriters() throws IOException {
        PrintWriter[] writers = new PrintWriter[METHOD_NAMES.length];
        for (int i = 0; i < METHOD_NAMES.length; i++) {
            File outputFile = new File(OUTPUT_DIR + METHOD_NAMES[i] + ".data");
            boolean fileExists = outputFile.exists();
            boolean fileIsEmpty = fileExists ? outputFile.length() == 0 : true;

            // Abre arquivo em modo append (adiciona ao existente)
            writers[i] = new PrintWriter(new FileWriter(outputFile, true));

            // Se o arquivo não existia ou está vazio, escreve o cabeçalho
            if (!fileExists || fileIsEmpty) {
                writers[i].println("estrutura_linguagem memoria tamanho");
            }
        }
        return writers;
    }

    private static void processLines(List<String> lines, PrintWriter[] writers) {
        int totalLines = lines.size();
        for (int i = 0; i < totalLines; i++) {
            String line = lines.get(i);
            System.out.printf("\rProcessando linha %d/%d", i + 1, totalLines);
            System.out.flush();

            try {
                // Converte a linha em array de inteiros
                int[] elements = Arrays.stream(line.split("\\s+"))
                                     .mapToInt(Integer::parseInt)
                                     .toArray();
                // Realiza os testes com os elementos lidos
                testllOperations(writers, elements);
            } catch (NumberFormatException e) {
                System.err.printf("%nErro ao analisar linha %d: %s%n", i + 1, line);
            }
        }
    }

    private static void closeWriters(PrintWriter[] writers) {
        for (PrintWriter writer : writers) {
            if (writer != null) {
                writer.close();
            }
        }
    }
    
    private static void testllOperations(PrintWriter[] writers, int[] elements) {
        int length = elements.length;
        int middle = length / 2;
        long[][] memoryPeaks = new long[METHOD_NAMES.length][MEASUREMENT_RUNS];

        // Inicializa a fila com os elementos fornecidos
        LinkedList ll = new LinkedList();
        for (int num : elements) {
            ll.addLast(num);
        }

        // Fase de medição - registra os picos de memória
        for (int run = 0; run < MEASUREMENT_RUNS; run++) {
            performMemoryMeasurements(ll, middle, memoryPeaks, run);
        }

        // Calcula a mediana dos picos de memória e escreve nos arquivos
        for (int method = 0; method < METHOD_NAMES.length; method++) {
            Arrays.sort(memoryPeaks[method]);
            long medianMemory = memoryPeaks[method][MEASUREMENT_RUNS / 2] / 1024; // Convertendo para KB

            writers[method].printf("linkedlist_java %d %d%n", medianMemory, length);
            writers[method].flush();
        }
    }

    private static void performMemoryMeasurements(LinkedList ll, int middle, 
                                                long[][] memoryPeaks, int currentRun) {
        // Mede o pico de memória para cada operação
        memoryPeaks[0][currentRun] = measureMemoryPeak(ll, () -> ll.removeLast());
        memoryPeaks[1][currentRun] = measureMemoryPeak(ll, () -> ll.addLast(999));
        memoryPeaks[2][currentRun] = measureMemoryPeak(ll, () -> ll.getLast());
        memoryPeaks[3][currentRun] = measureMemoryPeak(ll, () -> ll.removeFirst());
        memoryPeaks[4][currentRun] = measureMemoryPeak(ll, () -> ll.addFirst(999));
        memoryPeaks[5][currentRun] = measureMemoryPeak(ll, () -> ll.getFirst());
        memoryPeaks[6][currentRun] = measureMemoryPeak(ll, () -> ll.removeByIndex(middle));
        memoryPeaks[7][currentRun] = measureMemoryPeak(ll, () -> ll.add(999, middle));
        memoryPeaks[8][currentRun] = measureMemoryPeak(ll, () -> ll.get(middle));
    }

    private static long measureMemoryPeak(LinkedList ll, Runnable operation) {
        // Executa a operação
        operation.run();
        
        // Retorna o consumo de memória do objeto ll
        return memoryMeter.measureDeep(ll);
    }
}

