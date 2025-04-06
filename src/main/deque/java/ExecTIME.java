import java.io.*;
import java.util.Arrays;

public class Exec {
    public static void main(String[] args) {
        try {
            // Definir os métodos a serem testados
            String[] methods = { "addFirst", "add", "addLast",
                                  "getFirst", "get", "getLast",
                                  "removeFirst", "remove", "removeLast" };

            // Lendo o arquivo de entrada
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line;

            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) continue;

                int[] input = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();

                for (String method : methods) {
                    long[] results = new long[30];

                    for (int i = 0; i < 30; i++) {    
                        Deque dq = new Deque();

                        // Adicionando os valores na Deque
                        for (String num: line.split(" "))
                            dq.addLast(Integer.parseInt(num));

                        long start = 0;
                        long end = 0;

                        switch (method) {
                            case "addFirst":
                                start = System.nanoTime();
                                dq.addFirst(10);
                                end = System.nanoTime();
                                break;

                            case "add":
                                start = System.nanoTime();
                                dq.add(10, input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "addLast":
                                start = System.nanoTime();
                                dq.addLast(10);
                                end = System.nanoTime();
                                break;

                            case "getFirst":
                                start = System.nanoTime();
                                dq.getFirst();
                                end = System.nanoTime();
                                break;

                            case "get":
                                start = System.nanoTime();
                                dq.get(input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "getLast":
                                start = System.nanoTime();
                                dq.getLast();
                                end = System.nanoTime();
                                break;

                            case "removeFirst":
                                start = System.nanoTime();
                                dq.removeFirst();
                                end = System.nanoTime();
                                break;

                            case "remove":
                                start = System.nanoTime();
                                dq.removeByIndex(input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "removeLast":
                                start = System.nanoTime();
                                dq.removeLast();
                                end = System.nanoTime();
                                break;
                        }

                        results[i] = (end - start);
                    }

                    Arrays.sort(results); // Ordena para buscar a mediana
                    String outputLine = "Deque-java " + results[14] + " " + input.length;

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
