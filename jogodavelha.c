#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int conditions(int size, char game[size][size])
{
    // lines
    for (int l = 0; l < size; l++)
    {
        if(game[l][0] == 'X' && game[l][1] == 'X' && game[l][2] == 'X')
        {
            return 1;
        }
        if(game[l][0] == 'O' && game[l][1] == 'O' && game[l][2] == 'O')
        {
            return 2;
        }
    }
    // columns
    for (int c = 0; c < size; c++)
    {
        if(game[0][c] == 'X' && game[1][c] == 'X' && game[2][c] == 'X')
        {
            return 1;
        }
        if(game[0][c] == 'O' && game[1][c] == 'O' && game[2][c] == 'O')
        {
            return 2;
        }
    }
    
    // main diagonal
    if(game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X')
    {
        return 1;
    }
    if(game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O')
    {
        return 2;
    }
    
    // second diagonal
    if(game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X')
    {
        return 1;
    }
    if(game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O')
    {
        return 2;
    }
    
    for(int l = 0; l < size; l++)
    {
      for(int c = 0; c < size; c++)
        {
          if(game[l][c] == '_')
          {
            return -1;
          }
        }
    }


    return 0;
}

void zerar(int size, char game[size][size])
{
  for(int l = 0; l < size; l++)
    {
      for(int c = 0; c < size; c++)
        {
          game[l][c] = '_';
        }
    }
}

void print(int size, char game[size][size])
{
  for(int l = 0; l < size; l++)
    {
      for(int c = 0; c < size; c++)
        {
          printf("%c ", game[l][c]);
        }
      printf("\n");
    }
}


int main()  
{
    int size = 3;
    char game[size][size];
    int line, column;
    int status = -1;
    
    zerar(3, game);

    srand(time(NULL));
    int player = 1+rand()%2;

while (status == -1)
{
    print(3, game);

    printf("Jogador %i, informe as coordenadas, linha e coluna: ", player);
    scanf("%i %i", &line, &column);

    if(player == 1)
    {
        if (game[line][column] == '_')
        {
            game[line][column] = 'X';
            player = 2;
        }
        else
        {
            printf("You can't play here.");
        }
    }
    
    else
    {
        if (player == 2)
        {
            if (game[line][column] == '_')
            {
                game[line][column] = 'O';
                player = 1;
            }
            else
            {
                printf("You can't play here.");
            }
        }
    }
    status = conditions(3, game);
    if(status == 1)
    {
      printf("Jogador %i venceu", player);
    }
    else if(status == 2)
    {
      printf("Jogador %i venceu!", player);
    }
    else if(status == 0)
    {
      printf("Empate!");
    }
    system("@cls||clear"); 
}

    return 0;
}