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


void imprimir(No* no)
{
  if(no != NULL)
  {
    printf("%i ", no->valor);
    imprimir(no->proximo);
  }
}


int main(void) {

  No* lista = NULL;

  lista = inserir(3, lista);
  lista = inserir(4, lista);
  lista = inserir(5, lista);
  lista = inserir(6, lista);

  imprimir(lista);
  
  return 0;
}