/*
  Escreva uma função que realize uma divisão de utilizando o método recursivo.

  Ex: div(10, 2) == 5
*/

#include "stdio.h"

int div(int a, int b){
  return a >= b ? div(a - b, b) + 1 : 0;
}

int main(void) {

  int d = div(10, 2);

  printf("%d\n", d); // 5

  return 0;
}
