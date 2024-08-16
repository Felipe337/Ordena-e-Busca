#include "app.h"


void executarOperacao(int vetor[], int tamanho, int escolha) {
    switch (escolha) {
        case 1:
            ordenacaoPorTroca(vetor, tamanho);
                break;
        case 2:
            ordenacaoPorSelecao(vetor, tamanho);
                break;
        case 3:
            ordenacaoPorInsercao(vetor, tamanho);
                break;
        case 4:
            ordenacaoPorMesclagem(vetor, 0, tamanho - 1);
                break;
                    default:
                        printf("Escolha inválida.\n");
                            return;
    }
        printf("Vetor ordenado: ");
            imprimirVetor(vetor, tamanho);
}

int menu(){
    int tamanho, escolha, chaveBusca;

    printf("Digite o tamanho do vetor: "); scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Digite os elementos do vetor:\n"); for (int i = 0; i < tamanho; i++) { scanf("%d", &vetor[i]);
    }

    while (1) {
        printf("******************************\n");
        printf("Escolha a operacao:\n");
        printf("1. Ordenacao\n");
        printf("2. Busca\n");
        printf("3. Sair\n");
        scanf("%d", &escolha);
        printf("******************************\n");

        switch (escolha) {
            case 1:
                printf("Escolha o metodo de ordenacao:\n");
                printf("1. Ordenacao por troca (Bubble Sort)\n");
                printf("2. Ordenacao por selecao (Selection Sort)\n");
                printf("3. Ordenacao por insercao (Insertion Sort)\n");
                printf("4. Ordenacao por mesclagem (Merge Sort)\n");
                scanf("%d", &escolha);
                    executarOperacao(vetor, tamanho, escolha);
                        break;
            case 2:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &chaveBusca);
                int resultadoBusca = buscaBinaria(vetor, 0, tamanho - 1, chaveBusca);
                if (resultadoBusca != -1) {
                    printf("O valor %d foi encontrado na posicao %d do vetor ordenado.\n", chaveBusca, resultadoBusca);
                }       else {
                    printf("O valor %d nao foi encontrado no vetor ordenado.\n", chaveBusca);
                }
                break;
            case 3:
                return 0;
                    break;
                        default:
                            printf("Escolha invalida. Tente novamente.\n");
        }
    }
}

