/*
  Escreva um programa que leia 1000 elementos e mostre a maior diferença
  entre dois elementos consecutivos desse array e em que indices eles estão.
 */

 #include "stdio.h"

 int main(void) {

   int quantidade = 1000, diferenca, indice_um, indice_dois, i, maior_diferenca = 0;
   int elementos[quantidade];

   scanf("%d\n", &elementos[0]);

   for(i = 1; i < quantidade; i++)
   {
   	 i == quantidade - 1 ? scanf("%d", &elementos[i]) : scanf("%d\n", &elementos[i]);
   	 diferenca = elementos[i] - elementos[i - 1];

   	 if (diferenca > maior_diferenca)
   	 {
   	   indice_um = i;
   	   indice_dois = i - 1;
   	   maior_diferenca = diferenca;
   	 }
   }

   printf("Maior Diferença => %d\n", maior_diferenca);
   printf("Índice do número maior => %d\n", indice_um);
   printf("Índice do número menor => %d\n", indice_dois);

   return 0;
 }
