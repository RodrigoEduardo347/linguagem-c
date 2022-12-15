#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[100];
    
    printf("Digite uma palavra: ");
    fgets(palavra, 100, stdin);
   
    int contador = 0; 
    int quantidadePalavras = strlen(palavra) - 1;
    int segContador = quantidadePalavras;
    int quantidade = 0;
    while(contador < quantidadePalavras){
        if(palavra[contador]==palavra[segContador-1]){
            quantidade++;
        }
        --segContador;
        ++contador;
    }
    
    if(quantidade==quantidadePalavras){
        printf("É Palíndroma!");
    }else {
        printf("Não é Palíndroma!");
    }

    return 0;
}

