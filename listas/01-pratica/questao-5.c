#include "stdio.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	int n, i;
	char primo = 1;

	printf("Digite o valor de n:\n");
	scanf("%d", &n);


	if (n > 0)
	{
		for (i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				primo = 0;
				break;
			}
		}
		if (primo)
		{
			printf("O número %d é primo!\n", n);
		}
		else
		{
			printf("O número %d não é primo!\n", n);
		}
	}
	else
		printf("O valor inserido não é válido!\n");

    return 0;
}
