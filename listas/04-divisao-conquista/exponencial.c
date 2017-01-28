#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

double expLinear(double a, int n);
double expDivisaoConquista(double a, int n);

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

  printf("Função Exponencial\n");

  for (i = 1; i <= exponent; i++) {

    int number = pow(2, i);

    for (j = 0; j < executions; j++) {

      QueryPerformanceFrequency(&freq);
      QueryPerformanceCounter(&begin);

      double result = expLinear(2, number);

      QueryPerformanceCounter(&end);

      ms = (double) (end.QuadPart - begin.QuadPart) / freq.QuadPart;
      time_sum[0] += ms * 1000;

      QueryPerformanceFrequency(&freq);
      QueryPerformanceCounter(&begin);

      result = expDivisaoConquista(2, number);

      QueryPerformanceCounter(&end);

      ms = (double) (end.QuadPart - begin.QuadPart) / freq.QuadPart;
      time_sum[1] += ms * 1000;

    }

    printf("Expoente: %02d | Entradas: %03d | Linear: %f | Divisão e Conquista: %f\n", i, (int)pow(2, i), (time_sum[0] / executions), (time_sum[1] / executions));
  }

  return 0;
}

double expLinear(double a, int n) {
  int i;
  double r = 1;

  for (i = 0; i < n; i++) {
    r *= a;
  }

  return r;
}

double expDivisaoConquista(double a, int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return a;
  double p = 1;
  if (n % 2 == 1) {
    p = a;
    n = n - 1;
  }
  double r = expDivisaoConquista(a, n/2);
  return p * r * r;
}
