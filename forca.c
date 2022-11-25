#include <stdio.h>
#include <string.h>

void forca(int try)
{
    if(try == 0)
    {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |         ");
    printf("\n |         ");
    printf("\n |         ");
    printf("\n |         ");           
    printf("\n |         ");             
    printf("\n_|___      ");        
    }
    if(try == 1)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |         ");
    printf("\n |         ");
    printf("\n |         ");           
    printf("\n |         ");  
    printf("\n_|___      ");        
        }
    if(try == 2)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |       | ");
    printf("\n |         ");
    printf("\n |         ");           
    printf("\n |         ");             
    printf("\n_|___      ");        
        }
    if(try == 3)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |       |/");
    printf("\n |         ");
    printf("\n |         ");           
    printf("\n |         ");             
    printf("\n_|___      ");        
        }
    if(try == 4)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |      \\|/");
    printf("\n |        ");
    printf("\n |         ");           
    printf("\n |         ");             
    printf("\n_|___      ");        
        }
    if(try == 5)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |      \\|/");
    printf("\n |       | ");
    printf("\n |         ");           
    printf("\n |         ");             
    printf("\n_|___      ");        
        }
    if(try == 6)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |      \\|/");
    printf("\n |       | ");
    printf("\n |      /  ");           
    printf("\n |         ");             
    printf("\n_|___      ");        
        }
    if(try == 7)
        {
    printf("\n  _______  ");      
    printf("\n |/      | ");      
    printf("\n |      (_)");
    printf("\n |      \\|/");
    printf("\n |       | ");
    printf("\n |      / \\");           
    printf("\n |   VOCÊ PERDEU!");             
    printf("\n_|___      ");     
        }

}

int main()
{
    char word[100];

    // enter the secret word 
    printf("Informe a palavra secreta: ");
    fgets(word, 100, stdin);
    printf("A palavra a ser adivinhada foi: %s .", word);

    // clear the terminal screen
    for (int i = 0; i < 250; i++)
    {
        printf("\n");
    }
    
    // underlines
    char screen[100];
    strcpy(screen, word);
    for (int i = 0; i < strlen(screen)-1; i++)
    {
        screen[i] = '_';
    }
    screen[strlen(word)-1] = '\n';

    int try = 0;
    
    while(1)
    {
        forca(try);

        printf("\nAdivinhe: ");
        for (int i = 0; i < strlen(screen); i++)
        {
            printf("%c ", screen[i]);
        }

        // enter the letter
        char letter;
        printf("\nLetra: ");
        scanf("%c", &letter);
        
        int doubt = 1;
        for (int i = 0; i < strlen(screen); i++)
        {
            if(letter == word[i]){      
                screen[i] = letter;     
                doubt = 0;              
            }
        }
        if(doubt == 1)
        {
            try++;    
        }

        if(strcmp(screen, word) == 0)
        {
            printf("\nAcertou: ");
            for (int i = 0; i < strlen(screen); i++)
            {
                printf("%c ", screen[i]);
            }
            printf("A palavra era %s", word);
            printf("Vence y Vence, Joga y Joga!");
            break;
        }

        if(try == 7)
        {
            forca(try);
            printf("A palavra era %s", word);
            break;
        }

    }

    return 0;
}