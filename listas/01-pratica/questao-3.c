#include "stdio.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	int dia, mes, ano;
	char valido = 0;

	printf("Digite o dia:\n");
	scanf("%d", &dia);
	printf("Digite o mês:\n");
	scanf("%d", &mes);
	printf("Digite o ano:\n");
	scanf("%d", &ano);


	if (ano >= 0)
	{
		if (mes == 1 ||
		    mes == 3 ||
		    mes == 5 ||
		    mes == 7 ||
		    mes == 8 ||
		    mes == 10 ||
		    mes == 12)
	    {
	    	if (dia > 0 && dia <= 31)
	    		valido = 1;
	    }
	    else if (mes == 4 ||
			     mes == 6 ||
			     mes == 9 ||
			     mes == 11)
		{
		    if (dia > 0 && dia <= 30)
		    	valido = 1;
	    }
	    else if (mes == 2)
	    {
	    	if (dia > 0 && dia <= 28)
		    	valido = 1;
	    }
	}
	if (valido)
		printf("A data é válida!\n");
	else
		printf("A data não é válida!\n");

    return 0;
}
