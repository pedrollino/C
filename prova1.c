#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int tam, int k, char cenario[tam][tam], char letra)
{
  int valor = 0;
  int matriz = (tam*2)-1;
  for (int l = 0; l < matriz; l++)
  {
      for (int c = 0; c < matriz; c++)
      {
        if(letra == 'a' && k == 1)
        {
          valor = 97;
          cenario[l][c] = valor+1;
          cenario[0][c] = valor; // teto da borda
          cenario[l][0] = valor; // parede esquerda da borda
          cenario[l][matriz-1] = valor; // parede direita da borda
          cenario[matriz-1][c] = valor; // chão da borda
          printf("%c", cenario[l][c]);
        }
        else if (letra == 'a' && k == -1)
        {
          valor = 97;
          cenario[l][c] = valor;
          cenario[0][c] = valor+1; // teto da borda
          cenario[l][0] = valor+1; // parede esquerda da borda
          cenario[l][matriz-1] = valor+1; // parede direita da borda
          cenario[matriz-1][c] = valor+1; // chão da borda
          printf("%c", cenario[l][c]);
        }
        else if (letra == 'y' && k == 1)
        {
          valor = 121;
          cenario[l][c] = valor+1;
          cenario[0][c] = valor; // teto da borda
          cenario[l][0] = valor; // parede esquerda da borda
          cenario[l][matriz-1] = valor; // parede direita da borda
          cenario[matriz-1][c] = valor; // chão da borda
          
          printf("%c", cenario[l][c]);
        }
        else if (letra == 'y' && k == -1)
        {
          valor = 121;
          cenario[l][c] = valor;
          cenario[0][c] = valor+1; // teto da borda
          cenario[l][0] = valor+1; // parede esquerda da borda
          cenario[l][matriz-1] = valor+1; // parede direita da borda
          cenario[matriz-1][c] = valor+1; // chão da borda
          printf("%c", cenario[l][c]);
        }

      }
      printf("\n");
  }
}



int main()
{
  int tam, k;
  char letra;

  scanf("%i %i %c", &tam, &k, &letra);
  char cenario[tam][tam];
    

  imprimir(tam, k, cenario, letra);

    return 0;
}