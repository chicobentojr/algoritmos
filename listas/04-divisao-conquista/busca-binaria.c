#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  double executions = 1000;
  int exponent = 7;
  LARGE_INTEGER begin, end;
  LARGE_INTEGER freq;
  double ms;
  double time_sum[2];
  int i, j;

  if (argc > 1){
    exponent = atoi(argv[1]);
  }

  printf("Busca Binária\n");

  for (i = 1; i <= exponent; i++) {

    int numbers_size = pow(2, i);
    int numbers[numbers_size];
    int number = numbers_size - 1;
    int number_index;

    time_sum[0];
    time_sum[1];

    for (j = 0; j < numbers_size; j++) {
      numbers[j] = j;
    }

    for (j = 0; j < executions; j++) {

      QueryPerformanceFrequency(&freq);
      QueryPerformanceCounter(&begin);

      number_index = buscaLinear(numbers, numbers_size, number);

      QueryPerformanceCounter(&end);

      ms = (double) (end.QuadPart - begin.QuadPart) / freq.QuadPart;
      time_sum[0] += ms * 1000;

      QueryPerformanceFrequency(&freq);
      QueryPerformanceCounter(&begin);

      number_index = busca(numbers, numbers_size, number);

      QueryPerformanceCounter(&end);

      ms = (double) (end.QuadPart - begin.QuadPart) / freq.QuadPart;
      time_sum[1] += ms * 1000;

    }

    printf("Expoente: %02d | Entradas: %03d | Linear: %f | Divisão e Conquista: %f\n", i, (int)pow(2, i), (time_sum[0] / executions), (time_sum[1] / executions));
  }

  return 0;
}

int buscaLinear(int *a, int size, int x) {
  int indice = -1;
  int i;
  for
  (i=0 ; i < size ; i++){
    if (a[i]==x){
      indice = i;
      break;
    }
  }
  return indice;
}

int buscaRec(int *a, int x, int inicio, int fim) {
  int meio = 0;
  if (inicio > fim) {
    return 0;
  }
  else
  {
    meio = (inicio + fim) / 2;
  }
  if (x == a[meio]) {
    return meio;
  }
  else
  {
    if (x < a[meio]) {
      return buscaRec(a, x, inicio, meio - 1);
    }
    else
    {
      return buscaRec(a, x, meio + 1, fim);
    }
  }
}

int busca(int *a, int size, int x) {
  return buscaRec(a, x, 0, size - 1);
}
