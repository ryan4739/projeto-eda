    C++: Apresentou o melhor desempenho em praticamente todas as operações com deque. Isso ocorre devido ao controle direto de memória com new/delete e à ausência de coleta de lixo, o que elimina a sobrecarga associada ao gerenciamento automático. O uso de ponteiros e estruturas internas otimizadas permite um acesso extremamente eficiente às extremidades.

    Java: O tempo de execução é um pouco maior que em C++, principalmente por conta da coleta de lixo e da checagem de segurança em tempo de execução. No entanto, a JVM consegue mitigar esse impacto com o compilador JIT. Em operações típicas de deque, como addFirst, removeLast e peekFirst, o desempenho se mantém competitivo graças ao gerenciamento eficiente das referências head e tail.

    Python: Apresenta os maiores tempos de execução. Isso se deve à natureza interpretada da linguagem, além do gerenciamento automático de memória por contadores de referência e ciclos. Nas operações com deque, o tempo cresce consideravelmente ao acessar ou modificar posições intermediárias, pois essas ações exigem percorrer a estrutura até o ponto desejado.

Uso de Memória

    Picos de memória nas operações: Foram medidos como a mediana de cinco execuções com 100 linhas de dados, usando diferentes tamanhos de entrada.

    C++: O uso de memória é o mais enxuto e previsível. A estrutura de deque é construída de forma eficiente, com baixa sobrecarga por nó. Técnicas como alocação em blocos e reuso de buffers ajudam a manter o consumo de memória sob controle.

    Java: Possui um consumo moderado, mas com certa sobrecarga por objeto e metadados da JVM. A implementação de Deque na linguagem é robusta, mas cada elemento ainda carrega metainformações adicionais que elevam o uso total de memória em relação ao C++.

    Python: Tem o maior consumo de memória entre as três linguagens. Cada item no deque é representado como um objeto completo, com headers internos do interpretador. Além disso, o uso dinâmico de tipos e dicionários internos em algumas operações eleva ainda mais o custo por elemento.
