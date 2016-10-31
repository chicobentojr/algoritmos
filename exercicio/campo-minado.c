#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FIELD_BOMB            '*'
#define DEFAULT_BOARD_SIDE    3
#define DEFAULT_BOMBS_AMOUNT  3

void initBoard(int boardSide, char board[][boardSide])
{
  for (int i = 0; i < boardSide; i++)
    for (int j = 0; j < boardSide; j++)
      board[i][j] = 0;
}

void setBombs(int boardSide, char board[][boardSide], int quantity)
{
  int bombs = 0;

  while(bombs < quantity) {
    int x = rand() % boardSide;
    int y = rand() % boardSide;

    if (!board[x][y])
    {
      board[x][y] = FIELD_BOMB;
      bombs++;
    }

  }
}

void showBoard(int boardSide, char board[][boardSide])
{
  printf("\n");

  for (int j = 0; j < boardSide; j++)
  {
    printf("=====");
  }

  printf("\n");

  for (int i = 0; i < boardSide; i++)
  {
    for (int j = 0; j < boardSide; j++)
    {
        printf("| %c |", board[i][j]);
    }

    printf("\n");

    for (int j = 0; j < boardSide; j++)
    {
      printf("=====");
    }

    printf("\n");
  }

  printf("\n");
}

int checkField(int boardSide, char board[][boardSide], int x, int y)
{
  int bombsFounded = 0;
  int currentX, currentY;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      currentX = x + i;
      currentY = y + j;

      if (currentX < 0 || currentX >= boardSide)
        break;

      if ((i == 0 && j == 0) || currentY < 0 || currentY >= boardSide)
        continue;

      if (board[currentX][currentY] == FIELD_BOMB)
      {
        bombsFounded++;
      }
    }
  }
  return bombsFounded;
}

void checkBoard(int boardSide, char board[][boardSide])
{
  for (int i = 0; i < boardSide; i++)
  {
    for (int j = 0; j < boardSide; j++)
    {
      if (board[i][j] != FIELD_BOMB)
      {
        int bombsFounded = checkField(boardSide, board, i, j);
        board[i][j] =  bombsFounded ? bombsFounded + '0' : 0;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  int boardSide = argc > 1 ? atoi(argv[1]): DEFAULT_BOARD_SIDE;
  int bombsAmount = argc > 2 ? atoi(argv[2]): DEFAULT_BOMBS_AMOUNT;
  char board[boardSide][boardSide];

  if (boardSide * boardSide < bombsAmount)
  {
    printf("O campo com dimensão %dx%d é insuficiente para %d bombas.\n", boardSide, boardSide, bombsAmount);
    return 0;
  }

  printf("\nPronto! Aqui está o seu campo minado tamanho %dx%d e com %d bombas!!!\n", boardSide, boardSide, bombsAmount);

  initBoard(boardSide, board);

  setBombs(boardSide, board, bombsAmount);

  checkBoard(boardSide, board);

  showBoard(boardSide, board);

  return 0;
}
