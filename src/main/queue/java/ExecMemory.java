package src.main.queue.java;

import java.io.*;
import java.util.*;

public class ExecMemory {

    private static final String[] METHOD_NAMES = {
        "addLast",
        "addFirst",
        "add",
        "removeFirst",
        "removeLast",
        "remove",
        "getFirst",
        "getLast",
        "get"
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
                currentLine++;
                if (line.isBlank()) continue;
                
                System.out.printf("\rProcessando linha %d/%d", currentLine, totalLines);
                System.out.flush();
                
                int[] elements = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();
                testQueueOperations(writers, elements);
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

    private static void testQueueOperations(PrintWriter[] writers, int[] elements) {
        int length = elements.length;
        int middle = length/2;
        int RUNS = 30;
        long[][] allMemory = new long[METHOD_NAMES.length][RUNS];

        for (int run = 0; run < RUNS; run++) {
            Queue<Integer> queue = new Queue<>(length + 3);
            for (int num : elements) {
                queue.addLast(num);
            }

            // Executa o garbage collector antes dos testes
            System.gc();
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            // Testa addLast
            long memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.addLast(999);
            long memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[0][run] = memoryAfter - memoryBefore;
            
            // Testa addFirst
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.addFirst(999);
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[1][run] = memoryAfter - memoryBefore;
            queue.removeFirst();

            // Testa add (middle)
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.add(999, middle);
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[2][run] = memoryAfter - memoryBefore;
            queue.remove(middle);
            
            // Testa removeLast
            queue.addLast(999);
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.removeLast();
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[3][run] = memoryBefore - memoryAfter;
            
            // Testa removeFirst
            queue.addFirst(999);
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.removeFirst();
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[4][run] = memoryBefore - memoryAfter;
            
            // Testa remove (middle)
            queue.add(999, middle);
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.remove(middle);
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[5][run] = memoryBefore - memoryAfter;
            
            // Testa getFirst
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.getFirst();
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[6][run] = memoryAfter - memoryBefore;
            
            // Testa getLast
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.getLast();
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[7][run] = memoryAfter - memoryBefore;
            
            // Testa get (middle)
            memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            queue.get(middle);
            memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            allMemory[8][run] = memoryAfter - memoryBefore;
        }

        for (int method = 0; method < METHOD_NAMES.length; method++) {
            Arrays.sort(allMemory[method]);
            long medianMemory = allMemory[method][RUNS/2];
            
            writers[method].println("queue-java " + medianMemory + " " + length);
            writers[method].flush();
        }
    }
}
