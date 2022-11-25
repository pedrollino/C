#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    char nome[60];
    struct pessoas * proximoNome;
}n_ponto;


typedef struct ponto{
    int num;
    struct ponto * proximoNumero; //PONTEIRO PARA O PRÓXIMO ELEMENTO
}t_ponto; //QUANDO FOR DECLARAR UMA VARIÁVEL NÃO SERÁ PRECISO DECLARAR TODO O "STRUCT", BASTA DECLARAR O t_ponto

int main (){
    n_ponto * ini_pessoa;
    n_ponto * proximo_nome;

    t_ponto * ini_ponto; //PONTEIRO QUE MARCA O INÍCIO DA LISTA
    t_ponto * proximo_ponto; //PONTEIRO QUE MARCA O PRÓXIMO PONTEIRO DA LISTA
    
    int resp; //VARIÁVEL PARA COLETAR A RESPOSTA DO USUÁRIO
    ini_pessoa = (n_ponto*) malloc(sizeof(n_ponto));
    ini_ponto = (t_ponto *) malloc(sizeof(t_ponto)); //ALOCANDO A MEMÓRIA
    
    if (ini_pessoa == NULL){
        exit(1);
    }
    

    if(ini_ponto == NULL){ //TESTANDO SE A LISTA ESTÁ VAZIA
        exit(1);
    };
    
    proximo_nome = ini_pessoa;
    proximo_ponto = ini_ponto; //PRÓXIMO PONTO ESTÁ AGORA APONTANDO PARA O INÍCIO DA LISTA
    
    scanf("%i", &resp);

    for(int i = 0; i<resp; i++){
        
        printf("nome e numero: ");
        scanf("%c %d", &proximo_nome->nome, &proximo_ponto->num); //A VARIÁVEL DE UMA STRUCT É ACESSADA ATRAVÉS DA "->" 
        
        if(resp != 0){
            proximo_nome->proximoNome = (n_ponto*)malloc(sizeof(n_ponto));
            proximo_nome = proximo_nome->proximoNome;

            proximo_ponto->proximoNumero = (t_ponto *)malloc(sizeof(t_ponto)); //AQUI ESTAMOS ALOCANDO A MEMÓRIA PARA O PRÓXIMO ELEMENTO
            proximo_ponto = proximo_ponto->proximoNumero;
        } else
            break;
        
    }

    
    printf("\n");
    
    proximo_nome->proximoNome = NULL;
    proximo_nome = ini_pessoa;
    proximo_ponto->proximoNumero = NULL; //DIZENDO QUE A LISTA CHEGOU AO FIM, CASO O USUÁRIO NÃO QUEIRA MAIS INSERIR NÚMEROS
    proximo_ponto = ini_ponto; //APONTANDO PARA O INÍCIO DA LISTA PARA COMEÇAR A LISTÁ-LA.
    

    while(proximo_ponto != NULL){
        printf("%c %d ", proximo_nome->nome, proximo_ponto->num);
        proximo_nome = proximo_nome->proximoNome;
        proximo_ponto = proximo_ponto->proximoNumero;
    }
    
    return 0;
}
