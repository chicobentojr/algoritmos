#include <stdio.h>
#include "divisores.h"

int gera_divisores(unsigned long int num, FILE * arquivo) {

  long int divisor = 1;


  while (divisor <= num){
    if (num % divisor == 0){
      fprintf(arquivo, "%ld\n",divisor);
    }
    divisor++;
  }

  return 0;
}
