/*
  Escreva uma função que retorne o resto de uma divisão de dois números utilizando o método recursivo.

  Ex: mod(7,4) == 3
*/

#include "stdio.h"

int mod(int a, int b){
  return a >= b ? mod(a - b, b) : a;
}

int main(void) {
  int x = mod(7,4);

  printf("%d\n", x); // 3

  return 0;
}
