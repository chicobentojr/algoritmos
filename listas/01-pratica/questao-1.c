#include "stdio.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	float n1, n2, media;

	printf("Digite o valor da nota do primeiro bimestre:\n");
	scanf("%f", &n1);
	printf("Digite o valor da nota do segundo bimestre:\n");
	scanf("%f", &n2);

	media = (n1 * 2 + n2 * 3) / 5;

	if (media >= 6)
		printf("O aluno está APROVADO!\n");
    else if (media >= 2)
		printf("O aluno está EM RECUPERAÇÂO!\n");
	else
		printf("O aluno está REPROVADO!\n");

    return 0;
}
