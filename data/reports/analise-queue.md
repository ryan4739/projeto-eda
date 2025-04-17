# Análise de comparação de desempenhos de tempo e memória de execução para implementações de Queue em Java, Python e C++

O objetivo deste documento é relatorizar a análise de comparação de desempenhos dos aspectos tempo e memória de execução para implementações de Queue nas linguagens Java, Python e C++. A análise é feita através da comparação entre os métodos, estruturas e linguagens distintos, baseado nos experimentos realizados e na análise teórica dos resultados obtidos.

---

#### Tempo de Execução
- **Tempo médio de excução dos métodos**: este aspecto foi calculado a partir da mediana de 30 execuções. Ou seja, cada método foi executado e teve seu tempo de execução armazenado 30 vezes. A listagem dessas 30 execuções foi ordenada, para remover valores dos extremos e evitar flutuações, e o ponto médio foi considerado para efeito de tempo de execução do método em questão. Além disso, os métodos foram intercalados na execução, então um foi executado em seguida do outro, respeitando o ciclo de 30 vezes, tornando a execução mais sortida. Os valores que alimentaram cada fila testada foram obtidos de um total de 400 linhas de números inteiros de diferentes tamanhos e valores.

- **C++**: apresentou o menor tempo de execução na maioria das operações, com tempos em O(1) para os métodos add_last, get_first e remove_first e O(N) nos métodos restantes, com variações entre acessos com e sem índice, gastando mais tempo naqueles e menos nestes. Nas execuções em que não apresentou tal resultado, esteve muito próximo da linguagem mais rápida (normalmente Java). Algumas das explicações são a alocação manual de memória e a ausência da coleta de lixo (garbage collector).
- **Java**: apresentou o segundo menor tempo de execução na maioria das operações, com tempos em O(1) para os métodos add_last, get_first e remove_first e O(N) nos métodos restantes, com variações entre acessos com e sem índice, gastando mais tempo naqueles e menos nestes. Nas execuções em que não esteve como a segunda linguagem mais veloz, esteve em primeiro lugar. Alguma das explicações da eficiência de tempo ligeiramente inferior ao da linguagem C++ está na coleta de lixo e na verificações de tipos em tempo de execução.
- **Python**: apresentou os piores resultados em termos de eficiência de tempo. Algumas das explicações para o resultado são a sua natureza interpretada (diferente das demais linguagens analisadas) e a coleta automática de lixo.

#### Uso de Memória
- **Picos de memória nas operações**: este aspecto foi calculado a partir da mediana de 5 execuções. O número menor de execuções, em relação à análise de tempo de execução, deve-se ao caráter mais estável na análise de memória, confirmado pelos números obtidos. Além disso, cada método foi executado para 400 linhas de números inteiros de diferentes tamanhos e valores e o método utilizado para obter a mediana foi o mesmo do usado na análise do tempo de execução.

- **C++**: apresentou bons usos de memória para os métodos testados, obtendo eficiência O(1) para os métodos add_last, remove_first, get_first, remove_last e add_first e O(N) para os métodos restantes (ou seja, aqueles envolvendo índices), pois envolviam uso de memória auxiliar diretamente proporcional ao tamanho da entrada. Além disso, teve um uso de memória bem controlado e previsível, devido às especificidades da linguagem.
- **Java**: apresentou bons usos de memória para os métodos testados, obtendo eficiência O(1) para os métodos add_last, remove_first, get_first, remove_last e add_first e O(N) para os métodos restantes, pois envolviam o uso de memória auxiliar crescente em relação ao tamanho da entrada. Obteve uso de memória bem próximo ao do C++.
- **Python**: apresentou bons resultados (próximos aos das demais linguagens) para os métodos que não envolviam índices, porém resultados ruins (mesma classe de eficiência O(N), porém muito maiores) nos métodos que envolveram índices.

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
