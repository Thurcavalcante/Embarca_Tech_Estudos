//* Operadores 

/* === Aritmétricos ===
? Adição: + 
? Subtração: -
? Multiplicação: *
? Divisão: /
? Módulo ou Resto de Divisão: %
*/

#include <stdio.h>

int main() {
    // int valor_ = 5 + 5; //10
    int valor1 = 5;
    int valor2 = 5;

    int adicao = valor1 + valor2;
    int subtracao = valor1 - valor2;
    int multiplicacao = valor1 * valor2;
    int divisao = valor1 / valor2;
    int modulo = valor1 % valor2;

    /* === Aritmétricos ===
    ? Adição: + 
    ? Subtração: -
    ? Multiplicação: *
    ? Divisão: /
    ? Módulo ou Resto de Divisão: %
    */

    printf("\n=== Aritmeticos ===\n");
    printf("- Adicao: 5 + 5 = %d\n", adicao);
    printf("- Subtracao: 5 - 5 = %d\n", subtracao);
    printf("- Multiplicacao: 5 * 5 = %d\n", multiplicacao);
    printf("- Divisao: 5 / 5 = %d\n", divisao);
    printf("- Modulo: 5 %% 5 = %d\n", modulo);
    
    /* === Atribuicao ===
    ?  
    */

    printf("\n=== Atribuicao ===\n");
    printf("- Atribuicao simples: valor1 = %d\n", valor1);
    
    printf("\n=== Logicos ===\n");
    printf("- And: && = %d\n", valor1);
}