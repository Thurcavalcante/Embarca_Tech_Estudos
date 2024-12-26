#include <stdio.h>

int main() {
    int numero, soma = 0;

    do {
        printf("Digite um número (0 para parar): ");
        scanf("%d", &numero); // Leitura do número
        soma += numero;       // Soma os números digitados
    } while (numero != 0);    // Enquanto o valor for diferente de 0

    printf("A soma dos números digitados é: %d\n", soma);
    
    return 0;
}