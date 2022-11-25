#include <stdio.h>

int main()
{
    float total, preco, gramas;
    int quantProdutos;

    printf("Digite a Quantidade de produtos: ");    
    scanf("%d", &quantProdutos);
    int matriz[quantProdutos][2];

    for (int i = 0; i < quantProdutos; i++)
        for (int j = 0; j < 2; j++){
            if (j == 0)
            {
                printf("Digite o preco de 100g do produto: ");
                scanf("%d", &matriz[i][j]); 
            }
            else
            {
                printf("Digite a quantidade em gramas que deseja levar: ");
                scanf("%d", &matriz[i][j]);
            }           
    }

    for (int i = 0; i < quantProdutos; i++){
        preco =  matriz[i][0];
        gramas =  matriz[i][1] / 100;
        total += preco * gramas;
    }
    if (quantProdutos < 1)
    {
        printf("Nenhum Produto cadastrado.\n");
    }
    else if (quantProdutos == 1)
    {
        printf("%i Produto cadastrado.\n", quantProdutos);
    }
    else
    printf("\n%i Produtos cadastrados.\n" ,quantProdutos);
    

    for (int i = 0; i < quantProdutos; i++)
    {
        printf("R$ %d o preço de 100g do produto %i.\n", matriz[i][0], i+1);
    }
    
    for (int i = 0; i < quantProdutos; i++)
    {
        printf("Você levará %.0f gramas do produto %i\n", gramas*100, i+1);
    }
    

    printf("\nO valor total é: %0.2f\n", total);
    return 0;
}