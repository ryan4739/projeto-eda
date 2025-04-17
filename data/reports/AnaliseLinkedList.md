# Análise de Comparação de Desempenho de Tempo de Execução e Uso de Memória Voltada para Diferentes Implementações de LinkedList (Java, Python, C++) e Entre Diferentes Estruturas 

Este relatório analisa o desempenho de diversas operações em diferentes estruturas de dados, com foco especial em listas encadeadas (Linked List) que contém head e tail implementadas em C++, Java e Python. A análise é baseada na visão teórica das implementações e resultados reais de tempo de execução e de uso de memória, e também faz comparações mais gerais entre as diferentes estruturas.

---

#### Tempo de Execução
- **Tempo médio de exeução dos métodos**: calculado a partir da mediana de repetidas execuções (para linkedlist sendo 101 execuções para tempo de execução) para 100 linhas com diferentes tamanhos. Apesar de diferentes tempos serem gerados, em alguns casos eles são tão pequenos devido a natureza dos métodos que chega a ser imperceptível.

- **C++**: Apresenta o menor tempo de execução em praticamente todas as operações. Isso se deve à alocação manual de memória (com `new/delete`) e ausência de coleta de lixo. Como não há sobrecarga de gerenciamento automático, o acesso aos ponteiros é imediato e otimizado em tempo de compilação.
- **Java**: Tempo é ligeiramente superior ao C++ devido à coleta de lixo (Garbage Collector) e à verificação de tipos em tempo de execução. No entanto, a JVM consegue otimizar muitas operações com JIT, fazendo com que o desempenho se mantenha próximo ao ideal para operações feitas em ponteiros que controlamos (`head` e `tail`), como `add_first`, `remove_first` e `get_first`[...].
- **Python**: É o mais lento. Isso ocorre devido à sua natureza interpretada, além da coleta de lixo automática baseada em contadores de referência e ciclos. Acessos a locais distantes de head, como em nos métodos de adição ou acesso ao meio da linkedlist são onde percebemos maior impacto no tempo, por terem que percorrer de head até o local desejado.

#### Uso de Memória
- **Picos de memória nas operações**: Calculados a partir da mediana de 5 execuções de dados 100 linhas com diferentes tamanhos.

- **C++**: Tem o uso de memória mais controlado e previsível. Cada nó contém apenas os campos necessários (valor e ponteiro), e não há overhead de estruturas internas de runtime. É possível otimizar ainda mais a memória com técnicas como alocação em bloco ou reutilização de nós.
- **Java**: O uso de memória é razoável, mas inclui sobrecarga de objetos, alinhamento de bytes, e metadados para a JVM. Cada nó tem mais overhead que em C++, mas o gerenciamento automático evita vazamentos.
- **Python**:  É a linguagem com maior consumo de memória entre as três implementações analisadas. Cada instância de nó é um objeto completo, com cabeçalhos adicionais do interpretador. Além disso, o uso dinâmico de tipos e dicionários internos (em alguns casos) agrava o consumo por elemento.

#### Exemplo Comparativo Entre as Implementações (para 1 milhão de elementos)
| Linguagem | Tempo total (`add_first`) | Memória estimada total |
|----------|----------------------------|-------------------------|
| C++      | ~20ms                      | ~40–60 MB               |
| Java     | ~50ms                      | ~80–100 MB              |
| Python   | ~150ms                     | ~130–180 MB             |

#### Conclusão 
- **Java** se vê mais adequado quando buscamos um equilíbrio e estabilidade no desempenho, sendo apenas ligeiramente inferior a C++; 
- **C++** quando temos mais restrições de controle de recursos e uso de memória;
- **Python** apenas para usos mais pontuais, já que sofre tanto em tempo quanto em memória devido a sua natureza interpretada. Essas diferenças de tempo e memória observadas entre as linguagens se dão principalmente pela forma como cada uma lida com alocação de memória, coleta de lixo, e desempenho bruto do ambiente de execução:

### Comparação geral entre estruturas para cada operação

#### add_first
- **Tempo**: LinkedList é a melhor estrutura para esta operação, pois realiza inserção no início diretamente com tempo constante. ArrayList é a pior, pois desloca todos os elementos.
- **Memória**: ArrayList é a melhor em uso de memória com vetor contínuo e sem ponteiros extras. LinkedList consome mais memória por nó, devido ao armazenamento de ponteiros e sobrecarga de linguagem.

#### add_last
- **Tempo**: LinkedList e Deque são as melhores com inserção em O(1). ArrayList é eficiente com O(1) amortizado e Stack e Queue também são rápida. Nenhuma estrutura tem desempenho ruim aqui.
- **Memória**: Deque é a mais econômica. LinkedList apresenta maior consumo por nó, enquanto ArrayList pode desperdiçar memória por alocação antecipada.

#### add_middle
- **Tempo**: ArrayList é mais eficiente em listas pequenas devido ao acesso direto e deslocamento simples. LinkedList é pior, pois precisa percorrer até o ponto de inserção.
- **Memória**: ArrayList é mais compacta. LinkedList consome mais memória por nó.

#### get_first, get_last
- **Tempo**: Todas as estruturas (exceto implementações não otimizadas de Queue) são eficientes, com LinkedList, Deque, ArrayList, Stack e Queue alcançando O(1).
- **Memória**: ArrayList, Deque, Queue e Stack são mais enxutas. LinkedList consome mais memória por nó.

#### get_middle
- **Tempo**: ArrayList é a melhor com acesso direto em O(1). LinkedList é a pior, pois exige travessia.
- **Memória**: Todas as estruturas apresentam uso de memória constante esperado. As variações vistas nos gráficos podem ser causadas por coleta de lixo ou ruídos na medição

#### remove_first / remove_last
- **Tempo**: LinkedList e Deque são as melhores com acesso direto aos extremos. ArrayList é a pior para remove_first devido ao deslocamento. Queue e Stack também são eficientes nas extremidades.
- **Memória**: Deque e Stack são mais econômicas. LinkedList consome mais por ponteiros.

#### remove_middle
- **Tempo**: ArrayList tem melhor desempenho em listas pequenas com acesso por índice. LinkedList é a pior, por exigir travessia e ajuste de ponteiros.
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
