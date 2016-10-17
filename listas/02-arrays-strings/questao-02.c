/*
  Escreva um programa que leia um array de n números reais
  e calcule a média dos números. O programa deve mostrar
  quantos são e quais são os valores acima da média e
  quantos são e quais são os valores abaixo da média.
*/

#include "stdio.h"

int main(void) {

  int n;

  scanf("%d\n", &n);

  float valores[n], acima[n], abaixo[n], soma = 0, media = 0;
  int i;

  for (i = 0; i < n; i++)
  {
  	i == n - 1 ? scanf("%f", &valores[i]) : scanf("%f\n", &valores[i]);
  	soma += valores[i];
  }

  media = soma / n;
  int acima_i = 0, abaixo_i = 0;

  for (i = 0; i < n; i++)
  {
  	if (valores[i] > media)
  	{
  		acima[acima_i++] = valores[i];
  	}
  	else
  	{
  		abaixo[abaixo_i++] = valores[i];
  	}
  }

  printf("%d\n", acima_i);

  for (i = 0; i < acima_i; i++)
  {
  	printf("%f\n", acima[i]);
  }

  printf("%d\n", abaixo_i);

  for (i = 0; i < abaixo_i; i++)
  {
  	printf("%f\n", abaixo[i]);
  }

  return 0;
}
