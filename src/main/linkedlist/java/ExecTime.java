import java.io.*;
import java.util.*;

public class ExecTime {
    public static void main(String[] args) {
        try {
            String[] methods = {
                "add_first", "add_middle", "add_last",
                "get_first", "get_middle", "get_last",
                "remove_first", "remove_middle", "remove_last"
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
            case "add_first":
                start = System.nanoTime();
                ll.addFirst(10);
                end = System.nanoTime();
                ll.removeFirst();
                break;

            case "add_middle":
                start = System.nanoTime();
                ll.add(10, index);
                end = System.nanoTime();
                ll.removeByIndex(index);
                break;

            case "add_last":
                start = System.nanoTime();
                ll.addLast(10);
                end = System.nanoTime();
                ll.removeLast();
                break;

            case "get_first":
                start = System.nanoTime();
                ll.getFirst();
                end = System.nanoTime();
                break;

            case "get_middle":
                start = System.nanoTime();
                ll.get(index);
                end = System.nanoTime();
                break;

            case "get_last":
                start = System.nanoTime();
                ll.getLast();
                end = System.nanoTime();
                break;

            case "remove_first":
                int first = ll.getFirst();
                start = System.nanoTime();
                ll.removeFirst();
                end = System.nanoTime();
                ll.addFirst(first);
                break;

            case "remove_middle":
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
        String outputLine = "linkedlist_java " + tempo + " " + tamanhoEntrada;
        File file = new File(method + ".data");
        boolean isNewFile = !file.exists() || file.length() == 0;

        try (PrintWriter writer = new PrintWriter(new FileOutputStream(file, true))) {
            if (isNewFile) {
                writer.println("estrutura_linguagem tempo tamanho");
            }
            writer.println(outputLine);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
