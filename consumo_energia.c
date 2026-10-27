#include <stdio.h>

#define TAMANHO 10

// Mostra os valores do array na tela
void exibirConsumo(float consumo[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("  %2d) %.1f kWh\n", i + 1, consumo[i]);
    }
}

// Bubble Sort
// crescente = 1 -> do menor para o maior
// crescente = 0 -> do maior para o menor
void bubbleSort(float consumo[], int tamanho, int crescente) {
    int i, j;
    float aux;

    // Laço externo: cada passada leva um valor para sua posição final
    for (i = 0; i < tamanho - 1; i++) {
        // Laço interno: compara elementos vizinhos
        for (j = 0; j < tamanho - 1 - i; j++) {
            int foraDeOrdem;

            // Comparação muda de acordo com o critério escolhido
            if (crescente) {
                foraDeOrdem = consumo[j] > consumo[j + 1];
            } else {
                foraDeOrdem = consumo[j] < consumo[j + 1];
            }

            // Troca usando variável auxiliar
            if (foraDeOrdem) {
                aux = consumo[j];
                consumo[j] = consumo[j + 1];
                consumo[j + 1] = aux;
            }
        }
    }
}

int main() {
    float consumo[TAMANHO] = {150.0, 45.5, 320.8, 12.3, 89.0,
                              210.4, 5.6, 64.2, 180.9, 27.1};
    int opcao;

    printf("=== CONSUMO DE ENERGIA ===\n\n");

    printf("Antes da ordenacao:\n");
    exibirConsumo(consumo, TAMANHO);

    // Repete a pergunta enquanto a opção for inválida
    do {
        printf("\nEscolha o criterio:\n");
        printf("  1 - Crescente\n");
        printf("  2 - Decrescente\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); // limpa entrada que não é número
            opcao = 0;
        }

        if (opcao != 1 && opcao != 2) {
            printf("Opcao invalida! Digite 1 ou 2.\n");
        }
    } while (opcao != 1 && opcao != 2);

    bubbleSort(consumo, TAMANHO, opcao == 1);

    printf("\nDepois da ordenacao (%s):\n", opcao == 1 ? "crescente" : "decrescente");
    exibirConsumo(consumo, TAMANHO);

    // TODO: mostrar o nome de cada equipamento junto com o consumo

    return 0;
}
