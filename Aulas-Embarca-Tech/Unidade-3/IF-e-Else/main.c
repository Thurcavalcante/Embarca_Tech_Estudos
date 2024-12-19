#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media;

    // Lendo as notas do aluno
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    // Calculando a média
    media = (nota1 + nota2 + nota3) / 3;

    // Verificando se o aluno foi aprovado ou reprovado
    if (media >= 7) {
        printf("Aprovado! Média: %.2f\n", media);
    } else if (media >= 5) {
        printf("Recuperação! Média: %.2f\n", media);
    } else {
        printf("Reprovado! Média: %.2f\n", media);
    }

    return 0;
}