#include <stdio.h>

int main() {
    int valor = 2;

    switch (valor) {
        case 1:
            printf("Um\n");
            break;
        case 2:
            printf("Dois\n");
            break;
        case 3: 
            printf("Três\n");
            break;
        default:
            printf("Valor inválido\n");
    }

    return 0;
}