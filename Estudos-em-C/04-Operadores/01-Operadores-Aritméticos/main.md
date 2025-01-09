## Operadores

Os operadores são símbolos especiais utilizados para realizar
operações matemáticas e lógicas.

### Operadores Aritméticos

Os operadores aritméticos são usados para realizar operações matemáticas básicas em C, como adição, subtração, multiplicação e divisão.

| Operador | Operação        |
| -------- | --------------- |
| +        | Soma            |
| -        | Subtração       |
| *       | Multiplicação   |
| /        | Divisão Interia |
| %        | Módulo          |
| ++       | Incremento      |
| --       | Decremento      |

```c
#include <stdio.h>

int main(void) {
    int a = 5, b = 3;
    
    int soma = a + b;
    printf("soma de %d e %d é %d\n", a, b, soma);
    
    int subtracao = a - b;
    printf("subtracao de %d e %d é %d\n", a, b, subtracao);
    
    int mult = a * b;
    printf("multiplicação de %d e %d é %d\n", a, b, mult);
    
    int divisao = a / b;
    printf("divisao de %d e %d é %d\n", a, b, divisao);
    
    int mod = a % b;
    printf("resto da divisão de %d e %d é %d\n", a, b, mod);
    
    a++;
    printf("incremento: %d\n", a);
    
    b--;
    printf("decremento: %d\n", b);
    
    return 0;
}
```
```c
// Resultado
soma de 5 e 3 é 8
subtracao de 5 e 3 é 
multiplivacao de 5 e 3 é 
divisao de 5 e 3 é 
resto da divisao de 5 e 3 é 
incremento de 5 e 3 é 
decremento de 5 e 3 é 
```
