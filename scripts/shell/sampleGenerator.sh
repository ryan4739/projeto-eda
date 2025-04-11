#!/bin/bash
# Script shell que gera 100 linhas de números inteiros. Cada linha possui
# tamanho e números aleatórios entre 10^n e 10^m, para n e m valores mínimo
# e máximo, respectivamente, indicados na invocação do programa.
# Uso: sh {caminho}/sampleGenerator.sh {potencia_minima} {potencia_maxima}
#
# Exemplo:
#   sh scripts/shell/sampleGenerator.sh 0 4
#
# O sample gerado será salvo em:
#   data/samples/samples-10-0-to-10-4.txt

# Verifica se o número de argumentos está correto
if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <tamanho_min> <tamanho_max>"
    exit 1
fi

# Define os tamanhos mínimo e máximo baseados nos argumentos recebidos
MIN_SIZE=10**$1
MAX_SIZE=10**$2
OUTPUT_DIR="data/samples"
OUTPUT_FILE="$OUTPUT_DIR/samples-10-$1-to-10-$2.txt"

# Cria o diretório de saída se não existir
mkdir -p "$OUTPUT_DIR"

# Remove o arquivo de saída se ele já existir para começar do zero
rm -f "$OUTPUT_FILE"

# Loop para gerar 100 linhas de números
for i in {1..100}; do
    # Gera um comprimento de linha aleatório entre MIN_SIZE e MAX_SIZE
    # Usa dois geradores RANDOM para aumentar a aleatoriedade em sistemas onde
    # RANDOM tem limite de 32767
    # 1. seq gera números de 1 até LINE_LENGTH
    # 2. tr substitui as quebras de linha por espaços
    # 3. sed remove o espaço final da linha
    # 4. >> adiciona a linha ao arquivo de saída
    LINE_LENGTH=$(( (RANDOM * 32768 + RANDOM) % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE ))
    # Gera a sequência de números
    seq 1 "$LINE_LENGTH" | tr '\n' ' ' | sed 's/ $//' >> "$OUTPUT_FILE"
    # Adiciona uma quebra de linha no final de cada linha de números
    echo >> "$OUTPUT_FILE"
done

# Informa ao usuário que o arquivo foi gerado com sucesso
echo "Arquivo gerado: $OUTPUT_FILE"
