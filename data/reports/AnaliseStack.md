# Análise de Comparação de Desempenho de Tempo de Execução e Uso de Memória para Implementações de Stack (Java, Python, C++)

Este relatório analisa o desempenho de diferentes implementações de Stack (Pilha) em C++, Java e Python, considerando tempo de execução e consumo de memória. Além disso, compara a Stack com outras estruturas de dados (LinkedList, ArrayList, Deque, Queue) para operações típicas.

---

### Tempo de Execução
- **Tempo médio de execução dos métodos**: calculado a partir da mediana de repetidas execuções (para Stack sendo 101 execuções por operação) em estruturas com 100 elementos de tamanhos variados. Apesar das variações em alguns ambientes, os métodos são geralmente rápidos por atuarem apenas em uma extremidade da estrutura.

- **C++**: Apresenta o menor tempo de execução nas operações típicas de stack, como push, pop, peek e variações como push_first, push_last, pop_first, etc. Isso se deve à sua compilação direta, à ausência de coletor de lixo e à manipulação direta de memória, o que reduz o overhead. A estrutura de Stack geralmente é implementada com std::vector ou std::deque, ambos altamente otimizados.
- **Java**: Possui desempenho competitivo, com tempo apenas ligeiramente maior que o C++ devido ao Garbage Collector e ao uso da JVM. A classe Stack em Java é baseada em Vector, o que garante sincronização (thread safety), mas adiciona leve overhead. Já Deque (como ArrayDeque) oferece desempenho melhor e é preferível em novas implementações. Métodos como push, pop, e peek são executados em tempo constante (O(1)).
- **Python**: É o mais lento entre os três, devido à sua natureza interpretada e ao gerenciamento automático de memória. Em Python, a estrutura de Stack geralmente é implementada com list ou collections.deque. Ambas fornecem desempenho aceitável em operações de topo (append/pop), mas ainda assim sofrem com overhead de alto nível do interpretador. Em geral, as operações são rápidas, mas não tão consistentes em grandes volumes como nas linguagens compiladas.

---

#### Uso de Memória
- **Picos de memória nas operações**: Calculados a partir da mediana de 5 execuções de dados 100 linhas com diferentes tamanhos.

- **C++**: A mais eficiente em questão de memória.Existe pouca alocação de memória e por não ter overhead de estruturas internas de runtime seus picos não são tão altos.
- **Java**: O uso de memória é meio-termo, mas inclui sobrecarga de objetos, alinhamento de bytes, e tipos generics. O gabager Colletion é um dos principais motivos para ocasionais picos e o alinhamento de bytes padding.
- **Python**:  Está linguagem consome mais espaço. .Ele possui um Overhead de dicionário para objetos (caso usado) que ocasiona muitos picos, list realoca memoria dinamicamente e GC por contagem de referências.

#### Comparativo Numérico Estimado (para 1 milhão de elementos)
| Linguagem | Tempo total (`add_first`) | Memória estimada total |
|----------|----------------------------|-------------------------|
| C++      | ~20ms                      | ~20–35 MB               |
| Java     | ~50ms                      | ~50–70 MB              |
| Python   | ~150ms                     | ~80–110 MB             |

#### Conclusão 
- **Java** se vê mais adequado quando buscamos um equilíbrio e estabilidade no desempenho, sendo apenas ligeiramente inferior a C++; 
- **C++** quando temos mais restrições de controle de recursos e uso de memória;
- **Python** apenas para usos mais pontuais, já que sofre tanto em tempo quanto em memória devido a sua natureza interpretada. Essas diferenças de tempo e memória observadas entre as linguagens se dão principalmente pela forma como cada uma lida com alocação de memória, coleta de lixo, e desempenho bruto do ambiente de execução:

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
