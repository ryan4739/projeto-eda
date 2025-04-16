import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import org.github.jamm.MemoryMeter;

/**
 * Classe para medição de consumo de memória de operações em uma ArrayList personalizada.
 * Versão simplificada sem declaração de pacote.
 */
public class ExecMemory {
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

    private static final int MEASUREMENT_RUNS = 5;
    private static final String OUTPUT_DIR = "data/results/memory/";
    private static final MemoryMeter memoryMeter = MemoryMeter.builder().build();
    
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("ERRO: nenhum argumento! Forneça o arquivo de entrada.");
            System.exit(1);
        }

        String inputFile = args[0];
        createOutputDirectory();

        try {
            String[] lines = readAllLines(inputFile);
            PrintWriter[] writers = initializeWriters();
            processLines(lines, writers);
            closeWriters(writers);
            System.out.printf("\nFinalizado! Processadas %d linhas.\n", lines.length);
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

    private static String[] readAllLines(String inputFile) throws IOException {
        StringBuilder content = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (!line.isBlank()) {
                    content.append(line).append("\n");
                }
            }
        }
        return content.toString().split("\n");
    }

    private static PrintWriter[] initializeWriters() throws IOException {
        PrintWriter[] writers = new PrintWriter[METHOD_NAMES.length];
        for (int i = 0; i < METHOD_NAMES.length; i++) {
            File outputFile = new File(OUTPUT_DIR + METHOD_NAMES[i] + ".data");
            boolean fileExists = outputFile.exists();
            boolean fileIsEmpty = !fileExists || outputFile.length() == 0;

            writers[i] = new PrintWriter(new FileWriter(outputFile, true));

            if (fileIsEmpty) {
                writers[i].println("estrutura_linguagem memoria tamanho");
            }
        }
        return writers;
    }

    private static void processLines(String[] lines, PrintWriter[] writers) {
        for (int i = 0; i < lines.length; i++) {
            String line = lines[i];
            System.out.printf("\rProcessando linha %d/%d", i + 1, lines.length);

            try {
                int[] elements = Arrays.stream(line.trim().split("\\s+"))
                                    .mapToInt(Integer::parseInt)
                                    .toArray();
                testArrayListOperations(writers, elements);
            } catch (NumberFormatException e) {
                System.err.printf("%nErro na linha %d: %s%n", i + 1, line);
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
    
    private static void testArrayListOperations(PrintWriter[] writers, int[] elements) {
        int length = elements.length;
	int middle = length / 2;
        long[][] measurements = new long[METHOD_NAMES.length][MEASUREMENT_RUNS];

        ArrayList list = new ArrayList(length);
        for (int num : elements) {
            list.addLast(num);
        }

        for (int run = 0; run < MEASUREMENT_RUNS; run++) {
            measurements[0][run] = measureOp(list, () -> list.rmvLast());
            measurements[1][run] = measureOp(list, () -> list.addLast(999));
            measurements[2][run] = measureOp(list, () -> list.getLast());
            measurements[3][run] = measureOp(list, () -> list.rmvFirst());
            measurements[4][run] = measureOp(list, () -> list.addFirst(999));
            measurements[5][run] = measureOp(list, () -> list.getFirst());
            measurements[6][run] = measureOp(list, () -> list.rmvIndex(middle));
            measurements[7][run] = measureOp(list, () -> list.addIndex(999, middle));
            measurements[8][run] = measureOp(list, () -> list.get(middle));
        }

        for (int i = 0; i < METHOD_NAMES.length; i++) {
            Arrays.sort(measurements[i]);
            long median = measurements[i][MEASUREMENT_RUNS / 2] / 1024; // KB
            writers[i].printf("arraylist_java %d %d%n", median, length);
        }
    }

    private static long measureOp(ArrayList list, Runnable operation) {
        operation.run();
        return memoryMeter.measureDeep(list);
    }
}
