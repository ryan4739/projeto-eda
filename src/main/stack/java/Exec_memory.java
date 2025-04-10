import java.io.*;
import java.util.*;

public class Exec_memory {
    ublic static void main(String[] args) {
            
        private static final String[] methods = {
                "pushIndex", "push", "pushLast",
                "popIndex", "pop", "popLast",
                "peekIndex", "peek", "peekLast"
            };
    
            // Leitura do input
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))){
            String line;

            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) continue;

                int[] input = Arrays.stream(line.trim().split("\\s+"))
                                    .mapToInt(Integer::parseInt)
                                    .toArray();

                for (String method : methods) {
                    long[] results = new long[30];

                    for (int i = 0; i < 30; i++) {
                        Stack stack = new Stack(100); // capacidade grande o suficiente

                        // Preenche a pilha com os elementos de entrada
                        for (int value : input) {
                            stack.push(value);
                        }

                        long start = 0;
                        long end = 0;

                        try {
                            switch (method) {
                                case "push":
                                    start = System.nanoTime();
                                    stack.push(10);
                                    end = System.nanoTime();
                                    break;

                                case "pushLast":
                                    start = System.nanoTime();
                                    stack.pushLast(10);
                                    end = System.nanoTime();
                                    break;

                                case "pushIndex":
                                    start = System.nanoTime();
                                    stack.pushIndex(10, input.length / 2);
                                    end = System.nanoTime();
                                    break;

                                case "pop":
                                    start = System.nanoTime();
                                    stack.pop();
                                    end = System.nanoTime();
                                    break;

                                case "popLast":
                                    start = System.nanoTime();
                                    stack.popLast();
                                    end = System.nanoTime();
                                    break;

                                case "popIndex":
                                    start = System.nanoTime();
                                    stack.popIndex(input.length / 2);
                                    end = System.nanoTime();
                                    break;

                                case "peek":
                                    start = System.nanoTime();
                                    stack.peek();
                                    end = System.nanoTime();
                                    break;

                                case "peekLast":
                                    start = System.nanoTime();
                                    stack.peekLast();
                                    end = System.nanoTime();
                                    break;

                                case "peekIndex":
                                    start = System.nanoTime();
                                    stack.peekIndex(input.length / 2);
                                    end = System.nanoTime();
                                    break;
                            }
                        } catch (Exception e) {
                            end = start; // Se deu exceção, ignora tempo
                        }

                        results[i] = end - start;
                    }

                    Arrays.sort(results);
                    long median = results[14]; // valor mediano
                    String outputLine = "stack-java-memory " + median + " " + input.length;

                    // Define arquivo de saída
                    File file = new File(method + ".data");
                    boolean isNewFile = !file.exists() || file.length() == 0;

                    try (PrintWriter writer = new PrintWriter(new FileOutputStream(file, true))) {
                        if (isNewFile) {
                            writer.println("estrutura-linguagem tempo tamanho_da_entrada");
                        }
                        writer.println(outputLine);
                    }
                }
            }
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }
}

