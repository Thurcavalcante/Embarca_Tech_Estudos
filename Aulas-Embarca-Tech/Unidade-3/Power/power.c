#include <stdio.h>

int main() {
    int a, b, pow = 1;  // Inicializando as variáveis

    printf("Digite o primeiro número: ");   // Leitura do número
    scanf("%d", &a);

    printf("Digite o segundo número: ");    // Leitura do número
    scanf("%d", &b);

    for (int i = 1; i <= b; i++) {  // Enquanto o valor for diferente de 0
        pow = pow * a;  // Soma os números digitados
    }

    printf("%d", a);    // Impressão
}