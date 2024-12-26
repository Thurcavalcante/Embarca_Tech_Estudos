#include <stdio.h>

int main() {
    float nota1, nota2, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    // Calculando a média
    media = (nota1 + nota2) / 2;

    // Verificando se o aluno foi aprovado ou reprovado
    if (media >= 7.0) {
        printf("Aluno aprovado! Média: %.2f\n", media);
    } else {
        printf("Aluno reprovado! Média: %.2f\n", media);
    }

    return 0;
}