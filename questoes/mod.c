#include "stdio.h"

int mod(int a, int b){
  return a >= b ? mod(a - b, b) : a;
}

int main(void) {
  int x = mod(7,4);

  printf("%d\n", x); // 3

  return 0;
}
