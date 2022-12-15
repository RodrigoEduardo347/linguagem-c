#include <stdio.h>
#include <stdlib.h>

#define M 'm'
#define N 'n'
#define P 'p'
#define A 'A'
#define B 'B'
#define C 'C'

void validavalores(char aux_nome, int paramenter)
{
    if (paramenter < -10)
    {
        printf("\nERRO! O parametro %c eh menor que -10\n", aux_nome);
        exit(0);
    }
    else if (paramenter > 10)
    {
        printf("\nERRO! O parametro %c eh maior que 10\n", aux_nome);
        exit(0);
    }
}

int leValores(char aux_nome, int paramenter)
{
    printf("\nMe informa o valor do parametro %c: ", aux_nome);
    scanf("%i", &paramenter);
    validavalores(aux_nome, paramenter);
    return paramenter;
}

float lematrizes(char nomeVar, int linha, int coluna, float matriz[linha][coluna])
{
    printf("\n\n\n");
    printf("Preencha os valores da matriz %c:\n", nomeVar);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("\nValor na linha %d e coluna %d: ", i + 1, j + 1);
            scanf(" %f", &matriz[i][j]);
        }
    }
    return matriz[linha][coluna];
}

void imprimeMatriz(char nome, int linha, int coluna, float matriz[linha][coluna])
{
    printf("\n\n\n\n");
    printf("Matriz %c:\n\n", nome);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("| %0.2f | ", matriz[i][j]);
            if (j == (coluna - 1))
            {
                printf("\n");
            }
        }
    }
}

float calculaMatrizC(int m, int n, int p, float matrizUm[m][n], float matrizDois[n][p], float matrizTres[m][p])
{
    int resultado;
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < p; y++)
        {
            resultado = 0;
            for (int z = 0; z < m; z++)
            {
                resultado += matrizUm[x][z] * matrizDois[z][y]; // realiza a soma e a multiplicação dos termos
            }
            matrizTres[x][y] = resultado; // atribui o valor da operação anterior a uma posição da matriz C
        }
    }

    return matrizTres[m][p];
}

int main()
{
    int m = 0, n = 0, p = 0;

    m = leValores(M, m);
    n = leValores(N, n);
    p = leValores(P, p);

    float matrizA[m][n];
    matrizA[m][n] = lematrizes(A, m, n, matrizA);
    imprimeMatriz(A, m, n, matrizA);

    float matrizB[n][p];
    matrizB[n][p] = lematrizes('B', n, p, matrizB);
    imprimeMatriz(B, n, p, matrizB);

    float matrizC[n][p];
    matrizC[n][p] = calculaMatrizC(m, n, p, matrizA, matrizB, matrizC);
    imprimeMatriz(C, m, p, matrizC);

    return 0;
}