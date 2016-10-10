/*
  Escreva uma função que retorne o fatorial de um número utilizando o método recursivo.

  Ex: fatorial(5) == 120
*/

#include "stdio.h"

int fatorial(int a){
  return a == 1 ? 1 : a * fatorial(a - 1);
}

int main(void) {

  int x = fatorial(5);

  printf("%d\n", x); // 120

  return 0;
}
