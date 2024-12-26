//* Estrutura basica de uma aplicação em C

#include <stdio.h>      // Standard Input-output (biblioteca padrao de entrada/saída)
#include <stdlib.h>     // Standard Library (biblioteca de propósito geral)

int valor;              // Declaração de variavel global

void funcao_teste(){    // Declaração de função
    printf("teste");
}

int main() {
    printf("Hello World \n");
    funcao_teste();
}