

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class ExecTime {
    public static void main(String[] args) {
        try {
            // Criar a pasta de saída, se não existir
            new File("data/results/time").mkdirs();

            // Definir os métodos a serem testados
            String[] methods = { "add_first", "add_middle", "add_last",
                                  "get_first", "get", "get_last",
                                  "remove_first", "remove_middle", "remove_last" };

            // Lendo o arquivo de entrada
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line;

            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) continue;

                int[] input = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();

                //começa aqui a processar os dados
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
                            case "add_first":
                                start = System.nanoTime();
                                dq.addFirst(10);
                                end = System.nanoTime();
                                break;

                            case "add_middle":
                                start = System.nanoTime();
                                dq.add(10, input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "add_last":
                                start = System.nanoTime();
                                dq.addLast(10);
                                end = System.nanoTime();
                                break;

                            case "get_first":
                                start = System.nanoTime();
                                dq.getFirst();
                                end = System.nanoTime();
                                break;

                            case "get":
                                start = System.nanoTime();
                                dq.get(input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "get_last":
                                start = System.nanoTime();
                                dq.getLast();
                                end = System.nanoTime();
                                break;

                            case "remove_first":
                                start = System.nanoTime();
                                dq.removeFirst();
                                end = System.nanoTime();
                                break;

                            case "remove_middle":
                                start = System.nanoTime();
                                dq.remove(input.length / 2);
                                end = System.nanoTime();
                                break;

                            case "remove_last":
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
                    File file = new File("data/results/time/" + method + ".data");
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
