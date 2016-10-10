/*
  Escreva uma função que retorne a soma dos elementos de um array utilizando o método recursivo.

  Ex: array_soma({ 1, 2, 3}, 3) == 6
*/

#include "stdio.h"

int array_soma(int *array, int tamanho){
  return tamanho == 0 ? 0 : tamanho == 1 ? array[0] : array[tamanho - 1] + array_soma(array, tamanho - 1);
}

int main(void) {

  int elementos[3] = { 1, 2, 3 };
  int x = array_soma(elementos, 3);

  printf("%d\n", x); // 6

  return 0;
}
