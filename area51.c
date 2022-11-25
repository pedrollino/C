#include <stdio.h>
#include <string.h>

int main()
{
    int n_pessoas, num;
    char nome[30];
    int *ptr;

    scanf("%i", &n_pessoas);
    for (int i = 0; i < n_pessoas; i++)
    {
        scanf("%s %i\n", nome, &num);
        ptr = &num;

    }
    printf("%s %d", nome, num);

    
    return 0;
}