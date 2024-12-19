//* Saída
//? printf(formato, argumentos);

// Exemplos:
#include <stdio.h>

int main() {
    int idade = 26;
    float altura = 1.72;
    char nome[]="Arthur";

    printf("Olá, meu nome é %s e tenho %d anos. \n", nome, idade);
    printf("Minha altura é: %.2f metros. \n", altura);

    return 0;
}