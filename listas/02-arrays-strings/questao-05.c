/*
  Escreva um programa que receba uma frase e verifique se é um Palíndromo.
*/

#include "stdio.h"

int main(void) {

  char frase[9999];
  char novaFrase[9999];
  char palindromo = 1;
  int i, j, indice = 0;

  printf("Digite uma frase:\n");
  gets(frase);

  j = strlen(frase) - 1;

  for (i = 0; i <= j; i++)
  {
    if ((frase[i] >= 65 && frase[i] <= 90  ) || (frase[i] >= 97 && frase[i] <= 122))
    {
      novaFrase[indice++] = frase[i];
    }
  }

  strcpy(&frase, &novaFrase);
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
