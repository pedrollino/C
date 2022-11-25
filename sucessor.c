#include <stdio.h>

int main()
{
    int n, x, numero;
    int sucessor, predecessor;

    scanf("%i %i", &n, &x);

    while(n!=0)
        {
        numero = n%10;
        n = n/10;
        predecessor = numero - 1;
        sucessor = numero +1;
        if (x == sucessor)
        {
            printf("sim");
            return 0;
        }
        else if (x == predecessor)
        {
            printf("sim");
            return 0;
        }
    }
    printf("nao");
    return 0;
}