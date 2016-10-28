#include <stdio.h>

char checkIsBoardComplete(char board[3][3])
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ')
      {
        return 0;
      }
    }
  }

  return 1;
}

char checkBoardIncreasingDiagonal(char board[3][3], char x, char y)
{
  char move = board[x][y];

  if ((board[2][0] == move && board[1][1] == move && board[0][2] == move))
  {
    return 1;
  }

  return 0;
}

char checkBoardDownwardDiagonal(char board[3][3], char x, char y)
{
  char move = board[x][y];

  if ((board[0][0] == move && board[1][1] == move && board[2][2] == move))
  {
    return 1;
  }

  return 0;
}


char checkBoardLine(char board[3][3], char x, char y)
{
  char move = board[x][y];

  if ((board[x][0] == move && board[x][1] == move && board[x][2] == move) ||
      (board[0][y] == move && board[1][y] == move && board[2][y] == move))
  {
    return 1;
  }

  return 0;
}


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

  char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char symbols[2] = {'X', 'O'};
  char currentPlayer = 0;
  char playing = 1;
  char hasWinner;
  int x, y;

  printf("\nBem vindo ao jogo da velha!\n");

  while (playing)
  {
    showBoard(board);

    printf("É a vez do jogador %d [%c]:\n", currentPlayer + 1, symbols[currentPlayer]);
    printf("Digite a linha e a coluna em que você deseja realizar sua jogada\n");
    printf("separadas por um espaço. (ex.: 1 1 | 1 2 | 3 2)\n");

    scanf("%d %d", &x, &y);

    if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
    {
      x--;
      y--;
      if (board[x][y] == ' ')
      {
        board[x][y] = symbols[currentPlayer];

        hasWinner = checkBoardLine(board, x, y) || checkBoardIncreasingDiagonal(board, x, y) || checkBoardDownwardDiagonal(board, x, y);

        if (hasWinner || checkIsBoardComplete(board))
        {
          playing = 0;
        }
        else
        {
          currentPlayer = currentPlayer ? 0 : 1;
        }
      }
      else
      {
        printf("As coordenadas informadas já foram preenchidas. Por favor, refaça sua jogada!\n");
      }
    }
    else
    {
      printf("As coordenadas informadas não são válidas. Por favor, refaça sua jogada!\n");
    }
  }

  showBoard(board);

  if (hasWinner)
  {
    printf("Parabéns!!! O jogo terminou e o jogador %d venceu!!!\n", currentPlayer + 1);
  }
  else
  {
    printf("Que pena! O jogo terminou e ninguém venceu a partida!\n");
  }

  return 0;
}
