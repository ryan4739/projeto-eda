import java.io.*;
import java.util.*;

public class ExecTime {
    public static void main(String[] args) {
        try {
            String[] methods = {
                "addFirst", "add", "addLast",
                "getFirst", "get", "getLast",
                "removeFirst", "remove", "removeLast"
            };

            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line;

            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) continue;

                int[] input = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();

                LinkedList ll = new LinkedList();
                for (int value : input) {
                    ll.addLast(value);
                }

                for (String method : methods) {
                    long[] results = new long[101];
                    for (int i = 0; i < 101; i++) {
                        results[i] = medeTempo(ll, method, input);
                    }
                    Arrays.sort(results);
                    long median = results[50];
                    salvaResultado(method, median, input.length);
                }
            }
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }

    private static long medeTempo(LinkedList ll, String method, int[] input) {
        int index = input.length / 2;
        long start = 0;
        long end = 0;

        switch (method) {
            case "addFirst":
                start = System.nanoTime();
                ll.addFirst(10);
                end = System.nanoTime();
                ll.removeFirst();
                break;

            case "add":
                start = System.nanoTime();
                ll.add(10, index);
                end = System.nanoTime();
                ll.removeByIndex(index);
                break;

            case "addLast":
                start = System.nanoTime();
                ll.addLast(10);
                end = System.nanoTime();
                ll.removeLast();
                break;

            case "getFirst":
                start = System.nanoTime();
                ll.getFirst();
                end = System.nanoTime();
                break;

            case "get":
                start = System.nanoTime();
                ll.get(index);
                end = System.nanoTime();
                break;

            case "getLast":
                start = System.nanoTime();
                ll.getLast();
                end = System.nanoTime();
                break;

            case "removeFirst":
                int first = ll.getFirst();
                start = System.nanoTime();
                ll.removeFirst();
                end = System.nanoTime();
                ll.addFirst(first);
                break;

            case "remove":
                int valueAtIndex = ll.get(index);
                start = System.nanoTime();
                ll.removeByIndex(index);
                end = System.nanoTime();
                ll.add(valueAtIndex, index);
                break;

            case "removeLast":
                int last = ll.getLast();
                start = System.nanoTime();
                ll.removeLast();
                end = System.nanoTime();
                ll.addLast(last);
                break;
        }

        return end - start;
    }

    private static void salvaResultado(String method, long tempo, int tamanhoEntrada) {
        String outputLine = "linkedlist-java " + tempo + " " + tamanhoEntrada;
        File file = new File(method + ".data");
        boolean isNewFile = !file.exists() || file.length() == 0;

        try (PrintWriter writer = new PrintWriter(new FileOutputStream(file, true))) {
            if (isNewFile) {
                writer.println("estrutura-linguagem tempo tamanho_da_entrada");
            }
            writer.println(outputLine);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
