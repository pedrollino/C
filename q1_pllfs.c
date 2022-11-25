#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int valor;
  struct Node* proximo;
}No;

No* inserir(int valor, No* no)
{
  if(no == NULL)
  {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    return novo;
  }
  else
  {
    no->proximo = inserir(valor, no->proximo);
    return no;
  }
}

int somaElementos(int valor, No* fila)
{
    No *proximo = NULL;  
    int soma = 0;
    for (No *n = fila->proximo; n != NULL; n = proximo)
    {
        soma += n->valor;
    }
    return soma;
}

void imprimir(No* no)
{
  if(no != NULL)
  {
    printf("%i ", no->valor);
    imprimir(no->proximo);
  }
}



int main()
{
    int media = 0, idia, seguidores, minimo, soma = 0, mes = 5;

    No* fila = NULL;

    scanf("%i", &seguidores);
    scanf("%i", &minimo);

    for (int i = 0; i < mes; i++)
    {
        scanf("%i", &idia);
        fila = inserir(idia, fila);
        soma = somaElementos(idia, fila);
    }

    imprimir(fila);
    printf("%i", soma);


    return 0;
}