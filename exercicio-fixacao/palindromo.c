/*
  Escreva um programa que receba uma frase e verifique se é um Palíndromo.
*/

#include "stdio.h"

int main(void) {

  char frase[9999];
  char palindromo = 1;
  int i, j;

  printf("Digite uma frase:\n");
  gets(frase);

  j = strlen(frase) - 1;

  for (i = 0; i <= j; i++, j--)
  {
    if (frase[i] != frase[j])
    {
      palindromo = 0;
      break;
    }
  }

  if (palindromo){
    printf("É palíndromo\n");
  } else {
    printf("Não é palíndromo\n");
  }

  return 0;
}
