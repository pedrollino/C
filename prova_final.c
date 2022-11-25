#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char titulo[30], autor[10];
    int n_paginas;
}livro;

void zerar(int tam, livro livros[tam]){
    
    for(int i=0; i<tam; i++) {
        strcpy(livros[i].titulo, "NULL");
        strcpy(livros[i].autor, "NULL");
        livros[i].n_paginas = 0;
    }        
}

int inserir(int tam, livro livros[tam], int posicao, livro novo){
        
    int status = 1;
    char nulo[5] = "NULL";
        
        for (int i=0; i<tam; i++){
            if (strcmp(livros[i].titulo, novo.titulo) == 0){
                status = 0;
            }
        }

        if (status == 1){
            for (int i=0; i<tam; i++){
                if (strcmp(nulo, livros[i].titulo) == 0){
                    posicao = i;
                    break;
                } 
            }
            livros[posicao] = novo;
        }
    return status;
}

int remover(int tam, livro livros[tam],  char titulo_remove[]){
    int status = 0, posicao;
   
    for (int i=0; i<tam; i++){
        if (strcmp(livros[i].titulo, titulo_remove) == 0){
            posicao = i;
            status = 1;
        } 
    }
    if (status == 1){
        strcpy(livros[posicao].titulo, "NULL");
        strcpy(livros[posicao].autor, "NULL");
        livros[posicao].n_paginas = 0; 
    }
    
    return status;
}

int buscar(int tam, livro livros[tam], char titulo_remove[]){
    int posicao = -1;
    for (int i=0; i<tam; i++){
        if (strcmp(livros[i].titulo, titulo_remove) == 0){
            posicao = i;
        } 
    }
    return posicao;
}


int main(){ 

  int tam = 10, choose, posicao, status;
  char titulo[10];
  livro livros[tam], novo;
  zerar(tam, livros);

do {
  printf("Digite o numero da opcao que deseja realizar: \n");
  printf("1 - Inserir.\n2 - Remover.\n3 - Buscar.\n");
  scanf("%i", &choose);

  switch (choose){
  // Inserir produto
  case 1:{
      printf("Digite o titulo do livro que deseja inserir: ");
      scanf("%s", novo.titulo);
      printf("Digite o autor do livro: ");
      scanf("%s", novo.autor);
      printf("Digite o número de páginas do livro: ");
      scanf("%i", &novo.n_paginas);
      
      status = inserir(tam, livros, posicao, novo);

      if (status == 1){
          printf("Livro adicionado com sucesso!\n\n");
          
      }
      else if (status == 0){
          printf("\nEste produto ja existe!\n");
          }
        }
      break;

  // Remover produto
  case 2:{
      printf("Digite o titulo do livro que deseja remover: ");
      scanf("%s", titulo);
      
      status = remover(tam, livros, titulo);

      if (status == 1){
          printf("Livro removido com sucesso!\n");
          
      }
      else if (status == 0){
          printf("Este produto nao existe!\n");
      }
      break;
  }
  // Buscar produto
  case 3:{
      printf("Digite o titulo do livro que deseja buscar: ");
      scanf("%s", titulo);
      posicao = buscar(tam, livros, titulo);
      if (posicao>=0 && posicao<=tam){
          printf("\nLivro encontrado!\n\n");
          printf("Título: %s\n", livros[posicao].titulo);
          printf("Autor: %s\n", livros[posicao].autor);
          printf("Número de páginas: %i\n", livros[posicao].n_paginas);
      }
      else{
          printf("\nLivro nao encontrado!\n\n");
      }
      system("pause");
      break;
      }
  }
    }while(choose != 10);

  return 0;
}