#include <stdio.h>

// Função para calcular a média de duas notas
float calcular_media(float nota1, float nota2) {
    return (nota1 + nota2) / 2;
}

// Função para verificar se o aluno foi aprovado ou reprovado
void verificar_aprovacao(float media) {
    if (media >= 7.0) {
        printf("Aprovador! Média: %.2f\n", media);
    } else {
        printf("Reprovador! Média: %.2f\n", media);
    }
}

int main() {
    float nota1, nota2, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    // Chamando a função para calculando a média
    media = calcular_media(nota1, nota2);

    // Chamando a função para verificar se o aluno foi aprovado ou reprovado
    verificar_aprovacao(media);

    return 0;
}