#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int chute;
    int numTentavivas;
    int dificuldade;
    int segundos = time(0);
    srand(segundos);
    int numSorteado = rand() % 100;

    printf("Seja bem-vindo ao jogo de Advinhacao!\n");

    printf("Escolha a dificuldade do jogo: ");
    printf("(1) Facil   (2) Medio   (3)Dificil\n");
    while(dificuldade!=1 && dificuldade!=2 && dificuldade!= 3)
    {
        scanf("%d", &dificuldade);
    }

    switch(dificuldade)
    {
        case 1:
            numTentavivas = 20;
            break;
        
        case 2:
            numTentavivas = 10;
            break;

        case 3:
            numTentavivas = 6;
            break;
    }

    for(int i=0; i < numTentavivas; i++)
    {
        printf("Chute um numero entre 1 e 100: ");
        scanf("%d", &chute);

        int acertou = chute == numSorteado;
        int maior = chute > numSorteado;
        if(chute < 1 || chute > 100)
        {
            printf("\nDigite um valor maior ou igual 1 e menor ou igual a 100\n");

            continue;
        }
        else if(acertou)
        {
            printf("\n\nParabens! Você acertou o numero escolhido!\n");
            break;
        }
        else if(maior)
        {
            printf("\nO numero que voce chutou eh maior que o sorteado!\n\n");
            if(i == numTentavivas - 1)
            {
                printf("O numero escolhido era %d\n", numSorteado);
            }
        }
        else
        {
            printf("\nO numero que voce chutou eh menor que o sorteado!\n\n");
            if(i == numTentavivas - 1)
            {
                printf("O numero escolhido era %d\n", numSorteado);
            }
        }
    }
}