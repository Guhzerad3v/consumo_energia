#include <stdio.h>

#define TAMANHO 10

int main() {
    // Array com o consumo mensal (kWh) de 10 equipamentos de uma casa
    float consumo[TAMANHO] = {150.0, 45.5, 320.8, 12.3, 89.0,
                              210.4, 5.6, 64.2, 180.9, 27.1};

    int i;

    printf("Consumo de energia - dados originais:\n");

    // Percorre o array e mostra cada valor
    for (i = 0; i < TAMANHO; i++) {
        printf("%.1f kWh\n", consumo[i]);
    }

    // TODO: implementar o Bubble Sort
    // TODO: mostrar os dados ordenados

    return 0;
}
