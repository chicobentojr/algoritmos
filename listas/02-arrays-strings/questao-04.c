/*
  Escreva uma função que receba uma String e retorne quantas
  palavras tem a string. A função deve desconsiderar espaços
  extras na string.
*/

#include "stdio.h"

int quantasPalavras(char *texto)
{
  int espacos = 0;
  char eEspaco = 0;
  int i;

  for (i = 0; i < strlen(texto); i++)
  {
    if (texto[i] == ' ')
    {
      if (!eEspaco)
      {
        espacos++;
      }
      eEspaco = 1;
    }
    else
    {
      eEspaco = 0;
    }
  }

  return espacos + 1;
}

int main(void) {

  char texto[9999];
  int palavras = 0;

  gets(texto);

 	palavras = quantasPalavras(texto);

 	printf("%d\n", palavras);


  return 0;
}
