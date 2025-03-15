# Script responsável por gerar os valores amostrais para os testes
for i in `seq 100`; do
    # Faz a escolha de qual caso deve ser considerado para geração dos valores
    case $pot in
    4)
        # Define R como um valor e o resto da divsão por 10.001
        R=$(($RANDOM%10001));;

    5) 
        # Define R como um valor e o resto da divsão por 100.001
        R=$(($RANDOM * 4 % 100001));;

    6)
        # Define R como um valor e o resto da divsão por 1.000.001
        R=$(($RANDOM * 32 % 1000001));;
    *)
        echo "Valores válidos de potências para geração: 4, 5 e 6"
        exit 1;;    

    # Cria uma sequência de tamanho R na linha (de 0 até n, n ∈ {10^4, 10^5, 10^6})
    seq -s " " $R;

    # Imprime uma nova linha
    echo;
done 
