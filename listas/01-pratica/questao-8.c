#include "stdio.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	float massa_inicial;
	int x, tempo;


	printf("Digite o valor da massa inicial:\n");
	scanf("%f", &massa_inicial);
	printf("Digite o valor de x:\n");
	scanf("%d", &x);

	tempo = 0;

	while (massa_inicial > 1)
	{
		massa_inicial /= 2;
		tempo += x;
	}

	printf("O material demorou %d segundos para se tornar %.5f gramas", tempo, massa_inicial);

    return 0;
}
