#include "stdio.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	int n, soma, i;

	printf("Digite o valor de n:\n");
	scanf("%d", &n);


	if (n > 0)
	{
		soma = 0;
		for (i = 2; i < n; i++)
		{
			printf("%d\n", i);
			soma += i;
		}

		printf("A soma dos valores é: %d", soma);
	}
	else
		printf("O valor inserido não é válido!\n");

    return 0;
}
