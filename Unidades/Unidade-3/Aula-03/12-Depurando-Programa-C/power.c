/* Esse programa lê dois números inteiros e calcula a potência do primeiro número elevado ao segundo. */

/* O cálculo da potência é realizado em um laço que multiplica o primeiro número por ele mesmo repetidas vezes. Por fim, o valor é impresso na tela. */

#include "stdio.h"

int main() {
    int a, b, pow = 1;  // Inicializando as variáveis

    printf("Digite o primeiro número: ");   // Leitura do número
    scanf("%d", &a);

    printf("Digite o segundo número: ");    // Leitura do número
    scanf("%d", &b);

    for (int i = 1; i <= b; i++) {
        pow = pow * a;  // Soma os números digitados
    }

    printf("%d", a);    // Impressão
    //  printf("%d elevado a %d é %d\n", a, b, result); // Impressão do resultado  
    // return 0;  
}

/* Para iniciar o ambiente de depuração, basta usar o atalho F5 e selecionar o depurador instalado. */

