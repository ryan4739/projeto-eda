# Projeto de Estrutura de Dados

## Equipe responsável pelo projeto

- **Ryan Vinnícius Tielles Almeida da Silva**, matrícula **123210289** e Githubs **@ryanvinnicius** e **@ryan4739**;
- **Matheus Leite Barbosa**, matrícula **123210878** e Github **@matheusleitebarbosasouza**;
- **Arthur Rodrigues Marinho da Silva**, matrícula **123210353** e Github **@Arthyp**;
- **Diogo Medeiros**, matrícula **123110779** e Github **@diogo-med**;
- **Arthur Correia Leite**, matrícula **123210547** e Github **@ArthurCorreiaa**.

## Resumo da proposta

Comparar a eficiência das estruturas de dados lineares **ArrayList, LinkedList, Stack, Queue e Deque**. Cada estrutura será implementada nas linguagens de programação **Python, Java e C++**. A comparação será de **eficiência de tempo, eficiência de memória e limites de tamanhos de entrada**. Os métodos executados serão de **inserção, remoção e busca**. Ao final, será gerado um relatório com os gráficos obtidos e explicações teóricas dos resultados.

## Desenvolvimento da proposta

### Ideia do projeto

A ideia do projeto é:

a) Implementar os algoritmos referentes às estruturas de dados [ArrayList](), [LinkedList](), [Stack](), [Queue](https://joaoarthurbm.github.io/eda/posts/fifoarray/) e [Deque]() nas linguagens de programação Python, Java e C++, com suas respectivas documentações e testes. Para os testes, usaremos: JUnit para Java; Unittest para Python; e, funções de assert da linguagem para C++;

b) Gerar os dados de entrada para testagens e comparações de eficiências de tempo, de memória e limites. Para isso, utilizaremos um script bash para gerar um documento simples de texto, com valores inteiros, que será a entrada de todas as estruturas de dados;

c) Executar os métodos de inserção, remoção e busca, no começo, meio e fim, nos algoritmos implementados, monitorando o desempenho de tempo, de memória e carga suportada, gerando um arquivo de saída de texto simples com esses dados;

d) A partir dos dados de saída gerados por cada um dos métodos, nas linguagens e estruturadas de dados implementados, gerar gráficos comparativos utilizando a linguagem R;

e) Com os gráficos e com a teoria a respeito das estruturas de dados, gerar um relatório, em linguagem de marcação Markdown, com os resultados obtidos e explicações relevantes.

### Divisão das tarefas

Após discussão, optamos por cada membro da equipe ficar responsável por: a) implementação e testagem de uma estrutura de dados nas três linguagens; b) testagem de tempo, memória e carga para cada combinação de método, estrutura e linguagem implementados e geração dos dados de saída; c) geração dos gráficos dos dados obtidos. As demais tarefas ficaram sem definição, para serem feitas em conjunto. No mais, também tentamos corrigir os algoritmos uns dos outros.

A divisão ficou a seguinte:

- Ryan: Queue;
- Arthur Rodrigues: Arraylist;
- Matheus: Stack;
- Arthur Correia: Linkedlist;
- Diogo: Deque.

### Motivação

As motivações do projeto são:

a) subsidiar a disciplina de Estrutura de Dados e Algoritmos com material complementar, em formato acessível e esquematizado, propiciando material de estudos detalhado e com vários exemplos;

b) fixar e expandir o conteúdo aprendido ao decorrer do curso pelos estudantes envolvidos no projeto.

### Entrega

A entrega do trabalho envolverá a disponibilização de código fonte completo do projeto, com estruturas de dados, testes, script Bash, script R, configuração Gradle e relatório em Markdown;

## Planejamento da proposta

### Etapa 1: estudar as estruturas e definir métodos (concluída)

Nesta etapa, estudamos algumas estruturas de dados e escolhemos as estruturas ArrayList, LinkedList, Deque, Stack e Queue para implementação e experimentação no projeto. Para métodos de cada estrutura, escolhemos inserções, remoções e buscas no começo, no fim e por índice, busca por elemento para primeiro e último elemento encontrado, além dos métodos construtor, de obtenção do tamanho e de verificação de vazio ou cheio.

### Etapa 2: implementar e testar as estruturas (concluída)

Nesta etapa, implementamos as estruturas escolhidas com os métodos escolhidos e testamos. Seguimos uma estrutura de diretórios dividida em implementações e testes, cada uma subdividida por estruturas de dados e, então, subdivididas por linguagens de programação. Optamos por testar as implementações em Java com a ferramenta JUnit, as implementações em Python com a ferramenta UnitTest e as implementações em C++ com os asserts da linguagem. Automatizamos a testagem utilizando a ferramenta Gradle, modularizando cada combinação de estrutura de dado e linguagem no padrão 'estruturaLinguagem'. Por exemplo: 'queueCpp', 'arraylistJava' e 'linkedlistPython'.

### Etapa 3: gerar os dados de entrada (em andamento)

Nesta etapa, estamos gerando os dados de entrada para testagem de eficiência de tempo, memória e carga suportada por cada combinação de estrutura e linguagem. Estamos iniciando com conjuntos de números inteiros de tamanho 10^6 e aumentaremos a potência em 1, gradualmente, até que nenhuma das combinações suporte o tamanho, com este valor responsável pela quebra generalizada incluso.

### Etapa 4: testar eficiência de tempo, de espaço e limites de carga das estruturas e gerar dados de saída (por fazer)

Nesta etapa, implementaremos os códigos, para cada combinação de método, estrutura e linguagem, responsáveis por monitorar os parâmetros estudados e gerar um arquivo de saída padronizado com estes dados. Para monitoramento da eficiência de tempo, utilizaremos algoritmos que contarão o tempo de execução do algoritmo monitorado. Para monitoramento da eficiência de memória, utilizaremos técnica de perfilamento de memória. E, para o monitoramento das cargas suportadas, analisaremos as quebras dos algoritmos para entradas de determinados tamanhos.

### Etapa 5: gerar gráficos comparativos entre as combinações de métodos, estruturas e linguagens (por fazer)

Nesta etapa, implementaremos um script na linguagem R responsável por gerar um gráfico a partir dos valores de saída. Geraremos os gráficos comparativos entre as combinações de métodos, estruturas e linguagens.

### Etapa 6: fazer relatório com resultados obtidos e explicações (por fazer)

Nesta etapa, realizaremos a relatoria dos resultados obtidos, contendo: a) explicação detalhada dos métodos seguidos; b) divulgação dos gráficos obtidos; c) explicações a respeito dos resultados obtidos.

