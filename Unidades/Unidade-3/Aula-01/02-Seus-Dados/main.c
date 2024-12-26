#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    int idade;
    float altura;

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua idade: ");
    scanf("%f", &altura);

    printf("\n== Seus dados ==\n");
    printf("Nome: %-20s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f metros\n", altura);
}