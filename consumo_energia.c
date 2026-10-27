#include <stdio.h>

#define TAMANHO 10

// Mostra os valores do array na tela
void exibirConsumo(float consumo[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("  %2d) %.1f kWh\n", i + 1, consumo[i]);
    }
}

// Bubble Sort em ordem crescente
void bubbleSort(float consumo[], int tamanho) {
    int i, j;
    float aux;

    // Laço externo: cada passada leva o maior valor para o final
    for (i = 0; i < tamanho - 1; i++) {
        // Laço interno: compara elementos vizinhos
        for (j = 0; j < tamanho - 1 - i; j++) {
            // Se o da esquerda for maior, troca
            if (consumo[j] > consumo[j + 1]) {
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

    printf("=== CONSUMO DE ENERGIA ===\n\n");

    printf("Antes da ordenacao:\n");
    exibirConsumo(consumo, TAMANHO);

    bubbleSort(consumo, TAMANHO);

    printf("\nDepois da ordenacao (crescente):\n");
    exibirConsumo(consumo, TAMANHO);

    // TODO: permitir escolher crescente/decrescente e mostrar nomes dos equipamentos

    return 0;
}
