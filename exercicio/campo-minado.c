#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOMB '*'

void initBoard(int boardSide, char board[][boardSide])
{
  for (int i = 0; i < boardSide; i++)
    for (int j = 0; j < boardSide; j++)
      board[i][j] = 0;
}

void setBombs(int boardSide, char board[][boardSide], int quantity)
{
  int bombs = 0;

  do {
    int x = rand() % boardSide;
    int y = rand() % boardSide;

    if (!board[x][y])
    {
      board[x][y] = BOMB;
      bombs++;
    }

  } while(bombs < quantity);
}

void showBoard(int boardSide, char board[][boardSide])
{
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

      if (board[currentX][currentY] == BOMB)
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
      if (board[i][j] != BOMB)
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

  int boardSide = argc > 1 ? (int)*argv[1] - 48 : 3;
  int bombsAmount = argc > 2 ? (int)*argv[2] - 48 : 3;

  char board[boardSide][boardSide];

  initBoard(boardSide, board);
  setBombs(boardSide, board, bombsAmount);

  showBoard(boardSide, board);

  checkBoard(boardSide, board);

  showBoard(boardSide, board);

  return 0;
}
