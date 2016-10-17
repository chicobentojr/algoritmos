/*
  Escreva uma função que criptografe um texto usando
  o sistema Zenit Polar. A função mostra o resultado
  na tela.
*/

#include "stdio.h"

int main(void) {

  char frase[9999];
  char novaFrase[9999];

  int i;

  printf("Digite uma frase:\n");
  gets(frase);


  for (i = 0; i < strlen(frase); i++)
  {
  	switch(frase[i])
  	{
  		case 'Z':
  			novaFrase[i] = 'P';
  			break;
  		case 'E':
  			novaFrase[i] = 'O';
  			break;
  		case 'N':
    		novaFrase[i] = 'L';
    		break;
    	case 'I':
    		novaFrase[i] = 'A';
    		break;
    	case 'T':
    		novaFrase[i] = 'R';
    		break;
    	case 'z':
    		novaFrase[i] = 'p';
    		break;
    	case 'e':
    		novaFrase[i] = 'o';
    		break;
    	case 'n':
    		novaFrase[i] = 'l';
    		break;
    	case 'i':
    		novaFrase[i] = 'a';
    		break;
  		case 't':
    		novaFrase[i] = 'r';
    		break;
  		case 'P':
  			novaFrase[i] = 'Z';
  			break;
  		case 'O':
  			novaFrase[i] = 'E';
  			break;
  		case 'L':
    		novaFrase[i] = 'N';
    		break;
    	case 'A':
    		novaFrase[i] = 'I';
    		break;
    	case 'R':
    		novaFrase[i] = 'T';
    		break;
    	case 'p':
    		novaFrase[i] = 'z';
    		break;
    	case 'o':
    		novaFrase[i] = 'e';
    		break;
    	case 'l':
    		novaFrase[i] = 'n';
    		break;
    	case 'a':
    		novaFrase[i] = 'i';
    		break;
  		case 'r':
    		novaFrase[i] = 't';
    		break;
  		default:
  			novaFrase[i] = frase[i];
  	}
  }

  printf("%s\n", novaFrase);

  return 0;
}
