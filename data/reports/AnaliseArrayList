# Análise de Comparação de Desempenho de Tempo de Execução e Uso de Memória Voltada para Diferentes Implementações de ArrayList (Java, Python, C++) e Entre Diferentes Estruturas 

Este relatório analisa o desempenho de diversas operações com o foco em ArrayList que funciona como um array maleável que pode aumentar o seu tamanho dinamicaamente a medida que mais elementos são adicionados, mas também irei pincelar sobre as outras diferentes estruturas. Tudo aqui falado foram baseadas nas aulas do nosso orientador João Arthur e também baseadas dos testes em tempo de execução e memória em tempo real. 
---

#### Tempo de Execução
- **Tempo médio de exeução dos métodos**: calculado a partir da mediana de repetidas execuções (para ArrayList sendo 101 execuções para tempo de execução) para 100 linhas com diferentes tamanhos. Apesar de diferentes tempos serem gerados, em alguns casos eles são tão pequenos devido a natureza dos métodos que chega a ser imperceptível.

- **C++**: A que tem o melhor tempo de execução em maioria dos casos de tempo de execução devido as suas otimizações por debaixo dos panos.
- **Java**: Tempo é ligeiramente inferior ao de C++ em alguns casos específicos. Ademais, ela é extremamente similar c++ em diversas de suas operações. 
- **Python**: É o mais lento. porém isso ocorre por conta da forma que foi implementada, como o maix próximo de arrays em Python são tuplas, todas as vezes que qualquer elemento novo fosse adicionado ou removido da lista eu teria que criar uma nova tupla para armazenar os elementos infelizmente não serveria alocar espaços livres dinamicamente aqui por que tuplas não permitem colocar elementos em espaços vazios.

#### Uso de Memória
- **Picos de memória nas operações**: Calculados a partir da mediana de 5 execuções de dados 100 linhas com diferentes tamanhos.
ps: infelizmente não consegui rodar a tempo do prazo da entrega final em java mas ele funcionaria bem similar a como c++ funciona

- **C++**:  Como muito dos casos de ArrayList não precisamos de muito consumo de memória (com exceção do resize() que é amortizado) se torna equivalente a java e extremamente superior a implemetnação de tuplas em Python
- **Java**: (não concluido).
- **Python**:  Como sempre estamos criando uma tupla auxiliar para armazenar elementos seja adicionando ou removendo elementos, essa vira (de longe a pior opção)

#### Conclusão 
- **Java** Ambas as implementações de Java e C++ são bem similares mas java ainda é inferior em alguns casos específicos.
- **C++** Dentre Java que é sua semelhante, ela é melhor em alguns casos aspectos o que torna a melhor opção de uso.
- **Python** como foi feita com tuplas que não gosta de ter seus elementos alterados, torna-se a pior opção dentre as 3

### Comparação geral entre estruturas para cada operação

#### add_first
- **Tempo**: LinkedList é a melhor estrutura em tempo para esta operação, pois realiza inserção no início diretamente com tempo constante. Deque também é eficiente. ArrayList é a pior, pois desloca todos os elementos. Queue e Stack não são indicadas.
- **Memória**: ArrayList é a melhor em uso de memória com vetor contínuo e sem ponteiros extras. LinkedList consome mais memória por nó, devido ao armazenamento de ponteiros e overhead de linguagem.

#### add_last
- **Tempo**: LinkedList e Deque são as melhores com inserção em O(1). ArrayList é eficiente com O(1) amortizado. Stack e Queue também são rápidas, mas dependem da semântica da aplicação. Nenhuma estrutura tem desempenho ruim aqui.
- **Memória**: Deque é a mais econômica. LinkedList apresenta maior consumo por nó, enquanto ArrayList pode desperdiçar memória por alocação antecipada.

#### add_middle
- **Tempo**: ArrayList é mais eficiente em listas pequenas devido ao acesso direto e deslocamento simples. LinkedList é pior, pois precisa percorrer até o ponto de inserção. Deque, Queue e Stack não são recomendadas.
- **Memória**: ArrayList é mais compacta. LinkedList consome mais memória por nó.

#### get_first, get_last
- **Tempo**: Todas as estruturas (exceto implementações não otimizadas de Queue) são eficientes, com LinkedList, Deque, ArrayList, Stack e Queue alcançando O(1).
- **Memória**: ArrayList, Deque, Queue e Stack são mais enxutas. LinkedList consome mais memória por nó.

#### get_middle
- **Tempo**: ArrayList é a melhor com acesso direto em O(1). LinkedList é a pior, pois exige travessia.
- **Memória**: ArrayList usa menos memória. LinkedList consome mais por nó.

#### remove_first / remove_last
- **Tempo**: LinkedList e Deque são as melhores com acesso direto aos extremos. ArrayList é a pior para remove_first devido ao deslocamento. Queue e Stack também são eficientes nas extremidades.
- **Memória**: Deque e Stack são mais econômicas. LinkedList consome mais por ponteiros.

#### remove_middle
- **Tempo**: ArrayList tem melhor desempenho em listas pequenas com acesso por índice. LinkedList é a pior, por exigir travessia e ajuste de ponteiros. Deque, Queue e Stack não suportam essa operação.
- **Memória**: ArrayList continua mais eficiente. LinkedList mantém maior uso por ponteiros e objetos separados.

---

## Análise Assintótica Resumida por Estrutura

| Estrutura     | Inserção Início | Inserção Fim | Inserção Meio | Acesso Extremidades | Acesso Meio | Remoção Início/Fim | Remoção Meio | Memória |
|---------------|------------------|--------------|----------------|----------------------|-------------|----------------------|---------------|---------|
| LinkedList    | O(1)             | O(1)         | O(n)           | O(1)                 | O(n)        | O(1)/O(n)            | O(n)          | Alta    |
| ArrayList     | O(n)             | O(1)*        | O(n)           | O(1)                 | O(1)        | O(n)                | O(n)          | Baixa   |
| Deque         | O(1)             | O(1)         | O(n)           | O(1)                 | O(n)        | O(1)                | O(n)          | Média   |
| Stack         | O(1)             | O(1)         | O(n)           | O(1) (topo)          | O(n)        | O(1)                | O(n)          | Média   |
| Queue         | O(1)             | O(1)         | O(n)           | O(1)                 | O(n)        | O(1)                | O(n)          | Média   |


\* Amortizado
