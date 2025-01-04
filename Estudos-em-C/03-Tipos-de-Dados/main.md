## Tipos de dados

A linguagem C possui vários tipos de dados, como inteiros, ponto flutuante, caracteres e booleanos.

### Veja como usar diferentes tipos de dados em C:

```js
#include <stdio.h>

int main(void) {
// Declara uma variável inteira chamada "idade" e atribui o valor 25
int idade = 25;

// Declara uma variável de ponto flutuante chamada "altura" e atribui o valor 1.80
float altura = 1.80;

// Declara uma variável de caractere chamada "sexo" e atribui o valor 'M'
char sexo = 'M';

// Declara uma variável booleana chamada "casado" e atribui o valor verdadeiro
_Bool casado = 1;

printf("Idade: %d\nAltura: %f\nSexo: %c\nCasado: %d\n", idade,
altura, sexo, casado);

return 0;
}
```

Neste exemplo, são declaradas quatro variáveis de diferentes tipos: inteiro, ponto flutuante, caractere e booleano. Cada uma delas é atribuída um valor apropriado e, em seguida, é exibida na tela através da função **printf()**.

O resultado da execução deste programa:

```md
Idade: 26
Altura: 1.72
Sexo: M
Casado: 1
```


