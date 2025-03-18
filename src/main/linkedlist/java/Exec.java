import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Exec {
    public static void main(String[] args) {
        try {
            // Lendo o arquivo
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line = "";
            
            // Header
            System.out.println("language time sampleSize");
            // Iterando pelas linhas do arquivo
            while ((line = reader.readLine()) != null) {
                LinkedList ll = new LinkedList();
                // Adicionando os valores na LinkedList
                for (String num: line.split(" "))
                    ll.addLast(Integer.parseInt(num));
               
                long start = System.nanoTime(); // Iniciando a medição do tempo de execução 
                
                // Método sendo analisado  
                // ll.[...]

                long end = System.nanoTime(); // Finalizando a medição do tempo de execução
                long time = end - start; // Calculando a duração da execução
                
                // saída: {método tempo tamanho_da_entrada}
                System.out.println("linkedList " + (time) + " " + ll.sizeLL());
            }
        } catch (IOException ioe) {}
    }
}
    


