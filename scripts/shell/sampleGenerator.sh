#!/bin/bash
# Script shell que gera 100 linhas de números inteiros. Cada linha possui
# tamanho e números aleatórios entre 10^n e 10^m, para n e m valores mínimo
# e máximo, respectivamente, indicados na invocação do programa.

if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <tamanho_min> <tamanho_max>"
    exit 1
fi

MIN_SIZE=10**$1
MAX_SIZE=10**$2
OUTPUT_FILE="data/samples/samples-10-$1-to-10-$2.txt"

rm -f "$OUTPUT_FILE"

for i in {1..100}; do
    LINE_LENGTH=$(( (RANDOM * 32768 + RANDOM) % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE ))
    seq 1 "$LINE_LENGTH" | tr '\n' ' ' | sed 's/ $//' >> "$OUTPUT_FILE"
    echo >> "$OUTPUT_FILE"
done

echo "Arquivo gerado: $OUTPUT_FILE"
