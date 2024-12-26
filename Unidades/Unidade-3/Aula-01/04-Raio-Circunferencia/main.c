// * Calcular a área de uma circunferência (área = PI*R²)

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    double raio, area;

    printf("Digite o valor do raio da circunferencia: ");
    scanf("%lf", &raio);

    area = PI * pow(raio, 2);

    printf("A area da circunferencia e: %.2lf\n", area);
}