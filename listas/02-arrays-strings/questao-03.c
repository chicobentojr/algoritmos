/*
  Escreva um programa que os dados de uma eleição
  na cidade de Natal para prefeito e vereador e
  mostre o resultado geral e por zona. Natal possui
  5 zonas eleitorais: 1, 2, 3, 4 e 69. O programa
  deve pedir a zona eleitoral e o número do candidato
  para prefeito e o número do candidato para vereador.
  Todos os valores lidos são inteiros.
  *Considere que o programa sabe a quantidade de eleitores
  de cada zona. Todos os dados dos votos devem ficar
  armazenados em um array.
*/

#include "stdio.h"

int main(void) {

    int eleitores_quantidade = 5;
    int eleitores[eleitores_quantidade * 3];
    int prefeitos[eleitores_quantidade * 2];
    int vereadores[eleitores_quantidade * 2];
    int i;

    for (i = 0; i < eleitores_quantidade; i++)
    {
    	scanf("%d\n", &eleitores[i, 0]);
    	scanf("%d\n", &eleitores[i, 1]);
    	scanf("%d\n", &eleitores[i, 2]);
    }








    return 0;
}
