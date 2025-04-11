package src.main.queue.java;

import java.io.*;
import java.util.*;

public class ExecTime {

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
        String outputDir = "data/results/time/";

        // Cria o diretório de saída se ele não existir
        File outputDirFile = new File(outputDir);
        if (!outputDirFile.exists()) {
            outputDirFile.mkdirs();
        }

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
        long[][] allTimes = new long[METHOD_NAMES.length][RUNS];

        for (int run = 0; run < RUNS; run++) {
            Queue<Integer> queue = new Queue<>(length + 1);
            for (int num : elements) {
                queue.addLast(num);
            }

            // Test addLast
            long startTime = System.nanoTime();
            queue.addLast(999);
            long endTime = System.nanoTime();
            allTimes[0][run] = endTime - startTime;
            queue.removeFirst();

            // Test addFirst
            startTime = System.nanoTime();
            queue.addFirst(999);
            endTime = System.nanoTime();
            allTimes[1][run] = endTime - startTime;
            queue.removeFirst();

            // Test addMiddle
            startTime = System.nanoTime();
            queue.add(999, middle);
            endTime = System.nanoTime();
            allTimes[2][run] = endTime - startTime;
            queue.removeFirst();
            
            // Test removeLast
            startTime = System.nanoTime();
            queue.removeLast();
            endTime = System.nanoTime();
            allTimes[3][run] = endTime - startTime;
            queue.addLast(999);
            
            // Test removeFirst
            startTime = System.nanoTime();
            queue.removeFirst();
            endTime = System.nanoTime();
            allTimes[4][run] = endTime - startTime;
            queue.addLast(999);
            
            // Test removeMiddle
            startTime = System.nanoTime();
            queue.remove(middle);
            endTime = System.nanoTime();
            allTimes[5][run] = endTime - startTime;
            queue.addLast(999);
            
            // Test getFirst
            startTime = System.nanoTime();
            queue.getFirst();
            endTime = System.nanoTime();
            allTimes[6][run] = endTime - startTime;
            
            // Test getLast
            startTime = System.nanoTime();
            queue.getLast();
            endTime = System.nanoTime();
            allTimes[7][run] = endTime - startTime;
            
            // Test getMiddle
            startTime = System.nanoTime();
            queue.get(middle);
            endTime = System.nanoTime();
            allTimes[8][run] = endTime - startTime;
        }

        for (int method = 0; method < METHOD_NAMES.length; method++) {
            Arrays.sort(allTimes[method]);
            long medianTime = allTimes[method][RUNS/2];
            
            writers[method].println("queue-java " + medianTime + " " + length);
            writers[method].flush();
        }
    }
}
