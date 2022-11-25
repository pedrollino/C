#include <stdio.h>

int soma(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else{
        return (n * 2) + soma(n-1);
    }
}

int main()
{

    return 0;
}