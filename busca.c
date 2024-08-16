#include "busca.h"

int buscaBinaria(int vetor[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == chave)
            return meio;

        if (vetor[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; 
}
