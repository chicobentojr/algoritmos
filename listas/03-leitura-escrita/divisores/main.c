#include <stdio.h>
#include "divisores.h"

void usage(){
  printf("\n\n Uso do programa gera_divisores:\n\n");
  printf("  ./gera_divisores NUM ARQ\n\n");
  printf("  onde NUM é um inteiro com o número cujo divisores se deseja gerar\n");
  printf("  e ARQ é o nome do arquivo a ser criado com os divisores de NUM.");
  printf("TODOS os parâmetros são obrigatórios\n\n");
}

int check_parameters(int argc, char **argv){
  if (argc == 3){
    return 1;
  }
  return 0;
}

unsigned long int converte(char *num) {
  unsigned long int n;
  n = atoi(num);
  return n;
}

int main(int argc, char *argv[]) {
  FILE * arq_divisores;

  if (!check_parameters(argc, argv)){
    usage();
    return 1;
  }

  arq_divisores = fopen(argv[2], "w");

  if (arq_divisores == NULL){
    printf("ERRO: Não foi possível abrir o arquivo %s.\n", argv[2]);
    return 2;
  }

  if (gera_divisores(converte(argv[1]), arq_divisores) != 0) {
    printf("ERRO: Problemas ao escrever dados no arquivo %s.\n", argv[2]);
    return 3;
  }

  fclose(arq_divisores);

  return 0;
}
