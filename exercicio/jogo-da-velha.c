#include <stdio.h>
#include <locale.h>

void showBoard(char board[3][3])
{
  printf("\n");
  printf(" %c || %c || %c \n", board[0][0], board[0][1], board[0][2]);
  printf("=============\n");
  printf(" %c || %c || %c \n", board[1][0], board[1][1], board[1][2]);
  printf("=============\n");
  printf(" %c || %c || %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

int main(int argc, char const *argv[]) {

  setlocale(LC_ALL,"Portuguese");

  char board[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };
  char symbols[2] = {'X', 'O'};
  char currentPlayer = 0;
  char playing = 1;
  int x, y;

  printf("\nBem vindo ao jogo da velha!\n");

  while (playing)
  {
    showBoard(board);

    printf("É a vez do jogador %d:\n", currentPlayer + 1);
    printf("Digite a linha e a coluna em que você deseja realizar sua jogada\n");
    printf("separadas por um espaço. (ex.: 1 1 | 1 2 | 3 2)\n");

    scanf("%d %d", &x, &y);

    if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
    {
      x--;
      y--;
      if (!board[x][y])
      {
        board[x][y] = symbols[currentPlayer];
        currentPlayer = currentPlayer ? 0 : 1;
      }
      else
      {
        printf("As coordenadas informadas já foram preenchidas, por favor, refaça sua jogada!\n");
      }
    }
    else
    {
      printf("As coordenadas informadas não são válidas, por favor, refaça sua jogada!\n");
    }
  }

  return 0;
}
