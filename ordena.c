#include "ordena.h"

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; }
    
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void ordenacaoPorTroca(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}


void ordenacaoPorSelecao(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        trocar(&vetor[i], &vetor[indiceMenor]);
    }
}

void ordenacaoPorInsercao(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void mesclar(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int subvetorEsquerdo[n1], subvetorDireito[n2];

    for (i = 0; i < n1; i++)
        subvetorEsquerdo[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        subvetorDireito[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (subvetorEsquerdo[i] <= subvetorDireito[j]) {
            vetor[k] = subvetorEsquerdo[i];
            i++;
        } else {
            vetor[k] = subvetorDireito[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = subvetorEsquerdo[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = subvetorDireito[j];
        j++;
        k++;
    }
}

void ordenacaoPorMesclagem(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        ordenacaoPorMesclagem(vetor, inicio, meio);
        ordenacaoPorMesclagem(vetor, meio + 1, fim);

        mesclar(vetor, inicio, meio, fim);
    }
}

