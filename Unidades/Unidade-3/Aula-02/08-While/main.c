#include <stdio.h>

int main() {
    int numero, soma = 0; // Inicializando as variáveis

    printf("Digite números. Digite 0 para parar.\n");

    while (numero != 0) { // Enquanto o valor for diferente de 0
        printf("Digite um número: ");
        scanf("%d", &numero);
        
        soma += numero; // Soma os números digitados
    }

    printf("A soma dos números digitados é: %d\n", soma);

    return 0;
}