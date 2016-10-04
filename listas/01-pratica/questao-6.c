#include "stdio.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	int n1, n2, menor, mdc, i;



	printf("Digite o primeiro valor:\n");
	scanf("%d", &n1);
	printf("Digite o segundo valor:\n");
	scanf("%d", &n2);

	menor = n1 < n2 ? n1 : n2;

	for (i = menor; i > 0; i--)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			mdc = i;
			break;
		}
	}

	printf("O MDC dos números { %d, %d } é: { %d }", n1, n2, mdc);

    return 0;
}
