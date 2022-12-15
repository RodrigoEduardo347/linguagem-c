#include <stdio.h>

#define TAM 5

void ordenacao(int numero[]) {
    int aux;
    for(int i=1; i<TAM; i++) {
        aux = numero[i];
        int j = i - 1;

        while(j >= 0 && aux < numero[j]) {
            numero[j + 1] = numero[j];

            j--;
        }
        numero[j + 1] = aux;
    }
}

int main() {
    int numeros[TAM] = {8, 6, 4, 2, 0};
    
    ordenacao(numeros);

    printf("\nNumeros em ordem: { ");
    for(int k = 0; k < TAM; k++) {
        printf("%d ", numeros[k]);
    }
    printf("}\n");
    
    return 0;
}