#!/bin/bash

# Script shell que gera  um conjunto de números inteiros aleatórios separados
# por espaço. O tamanho do conjunto é definido por 10^n. O conjunto é
# armazenado em um arquivo de texto simples.
#
# Para utilizar o script:
#
# sh {caminho}/samplesGenerator.sh {n}

n=$((10 ** $1))

output_dir="data/inputs"
output_file="$output_dir/random_numbers-size-10-$1.data"

mkdir -p "$output_dir"

> "$output_file"

for ((i=0; i<n; i++)); do
    R=$((RANDOM % n))
    echo -n "$R " >> "$output_file"
done

echo >> "$output_file"
echo "Sequência de 10^$1 números aleatórios gerada e salva em: $output_file"

