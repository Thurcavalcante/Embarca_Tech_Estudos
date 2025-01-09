#include <stdio.h>

int main(void) {
    int a = 5, b = 3;

    int soma = a + b;
    printf("Soma de %d + %d = %d\n", a, b, soma);

    int subtracao = a - b;
    printf("Subtracao de %d - %d = %d\n", a, b, subtracao);

    int multiplicacao = a * b;
    printf("Multiplicacao de %d * %d = %d\n", a, b, multiplicacao);

    int divisao = a / b;
    printf("Divisao de %d / %d = %d\n", a, b, divisao);

    int modulo = a % b;
    printf("Resto da divisao de %d %% %d = %d\n", a, b, modulo);

    a++;
    printf("Incremento de a = %d\n", a);

    b--;
    printf("Decremento de b = %d\n", b);

    return 0;
}