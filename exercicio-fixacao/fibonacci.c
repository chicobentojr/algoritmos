/*
  Escreva uma função que retorne o n-ésimo número da Sequência Fibonacci utilizando o método recursivo.

  Ex: fibonacci(6) == 8
*/

#include "stdio.h"

int fibonacci(int n){
  return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {

  int x = fibonacci(6);

  printf("%d\n", x); // 8

  return 0;
}
