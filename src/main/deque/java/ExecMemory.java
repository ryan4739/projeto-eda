import java.io.*;
import java.util.*;

public class ExecMemory {

    private static final String[] METHOD_NAMES = {
        "add_last",
        "add_first",
        "add_middle",
        "remove_first",
        "remove_last",
        "remove_middle",
        "get_first",
        "get_last",
        "get_middle"
    };

    public static void main(String[] args) {

        String inputFile = args[0];
        String outputDir = "data/results/memory/";

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            int totalLines = 0;
            while (reader.readLine() != null) totalLines++;
            reader.close();

            PrintWriter[] writers = new PrintWriter[METHOD_NAMES.length];
            for (int i = 0; i < METHOD_NAMES.length; i++) {
                writers[i] = new PrintWriter(new FileWriter(outputDir + METHOD_NAMES[i] + ".data", true));
            }

            BufferedReader processingReader = new BufferedReader(new FileReader(inputFile));
            String line;
            int currentLine = 0;

            while ((line = processingReader.readLine()) != null) {
                System.out.println("linha "+ currentLine);
                currentLine++;
                if (line.isBlank()) continue;

                System.out.printf("\rProcessando linha %d/%d", currentLine, totalLines);
                System.out.flush();

                int[] elements = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();
                testDequeOperations(writers, elements);
            }

            for (PrintWriter writer : writers) {
                writer.close();
            }

            System.out.printf("\rConcluído! Processadas " + totalLines + " linhas.\n");

            processingReader.close();
        } catch (IOException e) {
            System.err.println("Erro processando arquivo: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static void testDequeOperations(PrintWriter[] writers, int[] elements) {
        int length = elements.length;
        int middle = length / 2;
        int RUNS = 30;
        long[][] allMemory = new long[METHOD_NAMES.length][RUNS];

        Deque deque = new Deque(length + 3);
        for (int num : elements) {
            deque.addLast(num);
        }
        for (int run = 0; run < RUNS; run++) {
            

            // Executa o garbage collector antes dos testes
            System.gc();
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            // Testa addLast
            long memoryBefore = getUsedMemory();
            deque.addLast(999);
            long memoryAfter = getUsedMemory();
            allMemory[0][run] = memoryAfter - memoryBefore;

            // Testa addFirst
            memoryBefore = getUsedMemory();
            deque.addFirst(999);
            memoryAfter = getUsedMemory();
            allMemory[1][run] = memoryAfter - memoryBefore;
            deque.removeFirst();

            // Testa add (middle)
            memoryBefore = getUsedMemory();
            deque.add(999, middle);
            memoryAfter = getUsedMemory();
            allMemory[2][run] = memoryAfter - memoryBefore;
            deque.remove(middle);

            // Testa removeFirst
            deque.addFirst(999);
            memoryBefore = getUsedMemory();
            deque.removeFirst();
            memoryAfter = getUsedMemory();
            allMemory[3][run] = memoryBefore - memoryAfter;

            // Testa removeLast
            deque.addLast(999);
            memoryBefore = getUsedMemory();
            deque.removeLast();
            memoryAfter = getUsedMemory();
            allMemory[4][run] = memoryBefore - memoryAfter;

            // Testa remove (middle)
            deque.add(999, middle);
            memoryBefore = getUsedMemory();
            deque.remove(middle);
            memoryAfter = getUsedMemory();
            allMemory[5][run] = memoryBefore - memoryAfter;

            // Testa getFirst
            memoryBefore = getUsedMemory();
            deque.getFirst();
            memoryAfter = getUsedMemory();
            allMemory[6][run] = memoryAfter - memoryBefore;

            // Testa getLast
            memoryBefore = getUsedMemory();
            deque.getLast();
            memoryAfter = getUsedMemory();
            allMemory[7][run] = memoryAfter - memoryBefore;

            // Testa get (middle)
            memoryBefore = getUsedMemory();
            deque.get(middle);
            memoryAfter = getUsedMemory();
            allMemory[8][run] = memoryAfter - memoryBefore;
        }

        for (int method = 0; method < METHOD_NAMES.length; method++) {
            Arrays.sort(allMemory[method]);
            long medianMemory = allMemory[method][RUNS / 2];

            writers[method].println("deque-java " + medianMemory + " " + length);
            writers[method].flush();
        }
    }

    private static long getUsedMemory() {
        Runtime runtime = Runtime.getRuntime();
        return runtime.totalMemory() - runtime.freeMemory();
    }
}
