/*
  Escreva uma função que retorne o valor de x elevado a y-ésima potência utilizando o método recursivo.

  Ex: potencia(5, 3) == 125
*/

#include "stdio.h"

int potencia(int x, int y){
  return y == 0 ? 1 : y == 1 ? x : x * potencia(x, y - 1);
}

int main(void) {

  int x = potencia(5,3);

  printf("%d\n", x); // 125

  return 0;
}
