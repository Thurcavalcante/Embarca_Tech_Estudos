#include <stdio.h>

int main() {
    int numero, soma = 0; // Inicializando as variáveis

    printf("Digite o número limite: "); // Leitura do número
    scanf("%d", &numero);               // Leitura do número

    for (int i =1; i <= numero; i++) {  // Enquanto o valor for diferente de 0
        soma += i;                      // Soma os números digitados
    }

    printf("A soma dos números de 1 até %d é: %d\n", numero, soma); // Impressão

    return 0;
}