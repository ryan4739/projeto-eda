#!/bin/bash

# Script shell que gera 100 linhas quantidade variada de números inteiros separados por espaço.
#
# Para utilizar o script:
#
# sh {caminho}/samplesGenerator.sh {valor mínimo} {valor máximo}

if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <tamanho_min> <tamanho_max>"
    exit 1
fi

MIN_SIZE=$1
MAX_SIZE=$2
OUTPUT_FILE="samples.data"

# Gera 100 linhas de tamanhos variados entre MIN_SIZE e MAX_SIZE
for i in {1..100}; do
    LINE_LENGTH=$(( (RANDOM * 32768 + RANDOM) % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE ))  # Gera tamanho entre MIN_SIZE e MAX_SIZE
    seq 1 "$LINE_LENGTH" | tr '\n' ' ' >> "$OUTPUT_FILE"
    echo -e "\n" >> "$OUTPUT_FILE"
done

echo "Arquivo gerado: $OUTPUT_FILE"