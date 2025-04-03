import java.io.*;
import java.util.Arrays;

public class Exec {
    public static void main(String[] args) {
        try {
            // Definir os métodos a serem testados
            String[] methods = { "pushIndex", "push", "pushLast",
                                  "popIndex", "pop", "popLast",
                                  "peekIndex", "peek", "peekLast" };

            // Lendo o arquivo de entrada
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line;

            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) continue;

                int[] input = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();

                for (String method : methods) {
                    long[] results = new long[30];

                    for (int i = 0; i < 30; i++) {    
                        Stack ck = new Stack();

                        // Adicionando os valores na LinkedList
                        for (String num: line.split(" "))
                            ck.push(Integer.parseInt(num));

                        long start = 0;
                        long end = 0;

                        switch (method) {
                            case "pushIndex":
                                start = System.nanoTime();
                                ck.pushLast(10);
                                end = System.nanoTime();
                                break;

                            case "push":
                                start = System.nanoTime();
                                ck.add(10, input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "pushLast":
                                start = System.nanoTime();
                                ck.pushLast(10);
                                end = System.nanoTime();
                                break;

                            case "popIndex":
                                start = System.nanoTime();
                                ck.popIndex(10);
                                end = System.nanoTime();
                                break;

                            case "pop":
                                start = System.nanoTime();
                                ck.pop();
                                end = System.nanoTime();
                                break;

                            case "popLast":
                                start = System.nanoTime();
                                ck.popLast();
                                end = System.nanoTime();
                                break;

                            case "peekIndex":
                                start = System.nanoTime();
                                ck.peekIndex(10);
                                end = System.nanoTime();
                                break;

                            case "peek":
                                start = System.nanoTime();
                                ck.peek();
                                end = System.nanoTime();
                                break;

                            case "peekLast":
                                start = System.nanoTime();
                                ck.peekLast();
                                end = System.nanoTime();
                                break;
                        }

                        results[i] = (end - start);
                    }

                    Arrays.sort(results); // Ordena para buscar a mediana
                    String outputLine = "stack-java " + results[14] + " " + input.length;

                    // Define o arquivo de saída baseado no método
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
