#include <stdio.h>
#include <string.h>
 
#define TAMANHO 10      /* quantidade de equipamentos (minimo exigido: 10) */
#define TAM_NOME 30     /* tamanho maximo do nome de cada equipamento     */
 
/* ------------------------------------------------------------
 * Exibe a tabela de equipamentos e seus consumos.
 * Usa um laco for para percorrer os dois arrays em paralelo.
 * ------------------------------------------------------------ */
void exibirTabela(char nomes[][TAM_NOME], float consumo[], int tamanho) {
    int i;
    float total = 0;
 
    printf("  +-----+--------------------------+--------------+\n");
    printf("  | No. | Equipamento              | Consumo      |\n");
    printf("  +-----+--------------------------+--------------+\n");
 
    for (i = 0; i < tamanho; i++) {
        printf("  | %3d | %-24s | %8.1f kWh |\n", i + 1, nomes[i], consumo[i]);
        total += consumo[i];
    }
 
    printf("  +-----+--------------------------+--------------+\n");
    printf("  |     | TOTAL                    | %8.1f kWh |\n", total);
    printf("  +-----+--------------------------+--------------+\n");
}
 
/* ------------------------------------------------------------
 * Bubble Sort
 * crescente = 1 -> menor para o maior
 * crescente = 0 -> maior para o menor
 * Retorna a quantidade de trocas realizadas.
 * ------------------------------------------------------------ */
int bubbleSort(char nomes[][TAM_NOME], float consumo[], int tamanho, int crescente) {
    int i, j;
    int trocou;              /* indica se houve troca na passada atual */
    int totalTrocas = 0;
    float auxConsumo;
    char auxNome[TAM_NOME];
 
    /* LACO EXTERNO: controla as passadas pelo array.
     * Ao fim de cada passada, o elemento "mais pesado" (de acordo
     * com o criterio) ja esta na sua posicao final no fim do array. */
    for (i = 0; i < tamanho - 1; i++) {
        trocou = 0;
 
        /* LACO INTERNO: compara pares de elementos ADJACENTES.
         * Vai ate (tamanho - 1 - i) porque os ultimos i elementos
         * ja estao ordenados e nao precisam ser comparados de novo. */
        for (j = 0; j < tamanho - 1 - i; j++) {
 
            /* COMPARACAO: decide se o par esta fora de ordem.
             * Crescente: troca se o da esquerda for MAIOR.
             * Decrescente: troca se o da esquerda for MENOR. */
            int foraDeOrdem;
            if (crescente) {
                foraDeOrdem = consumo[j] > consumo[j + 1];
            } else {
                foraDeOrdem = consumo[j] < consumo[j + 1];
            }
 
            if (foraDeOrdem) {
                /* TROCA: usa variavel auxiliar para nao perder o valor.
                 * O nome do equipamento e trocado junto para que cada
                 * consumo continue ligado ao aparelho correto. */
                auxConsumo     = consumo[j];
                consumo[j]     = consumo[j + 1];
                consumo[j + 1] = auxConsumo;
 
                strcpy(auxNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], auxNome);
 
                trocou = 1;
                totalTrocas++;
            }
        }
 
        /* OTIMIZACAO: se nenhuma troca ocorreu nesta passada,
         * o array ja esta ordenado e podemos parar mais cedo. */
        if (!trocou) {
            break;
        }
    }
 
    return totalTrocas;
}
 
int main() {
    /* Arrays paralelos: nomes[i] corresponde a consumo[i] */
    char nomes[TAMANHO][TAM_NOME] = {
        "Geladeira", "Televisao", "Chuveiro eletrico", "Carregador celular",
        "Maquina de lavar", "Ar-condicionado", "Roteador Wi-Fi",
        "Computador", "Ferro de passar", "Micro-ondas"
    };
 
    float consumo[TAMANHO] = {
        150.0, 45.5, 320.8, 12.3, 89.0,
        210.4, 5.6, 64.2, 180.9, 27.1
    };
 
    int opcao;
    int trocas;
 
    printf("\n============================================================\n");
    printf("   CLASSIFICADOR DE CONSUMO DE ENERGIA - BUBBLE SORT\n");
    printf("============================================================\n");
    printf("  Consumo mensal estimado dos equipamentos da residencia.\n\n");
 
    /* 1) Dados ANTES da ordenacao */
    printf(">> DADOS ORIGINAIS (antes da ordenacao):\n\n");
    exibirTabela(nomes, consumo, TAMANHO);
 
    /* 2) Usuario escolhe o criterio. O do-while repete
     *    enquanto a opcao digitada for invalida. */
    do {
        printf("\nEscolha o criterio de ordenacao:\n");
        printf("  1 - Crescente   (menor consumo -> maior consumo)\n");
        printf("  2 - Decrescente (maior consumo -> menor consumo)\n");
        printf("Opcao: ");
 
        if (scanf("%d", &opcao) != 1) {
            /* limpa a entrada se o usuario digitou algo que nao e numero */
            while (getchar() != '\n');
            opcao = 0;
        }
 
        if (opcao != 1 && opcao != 2) {
            printf("  [!] Opcao invalida. Digite 1 ou 2.\n");
        }
    } while (opcao != 1 && opcao != 2);
 
    /* 3) Ordenacao com Bubble Sort */
    trocas = bubbleSort(nomes, consumo, TAMANHO, opcao == 1);
 
    /* 4) Dados DEPOIS da ordenacao, informando o criterio */
    printf("\n>> DADOS ORDENADOS - criterio: %s\n\n",
           opcao == 1 ? "CRESCENTE (menor -> maior)" : "DECRESCENTE (maior -> menor)");
    exibirTabela(nomes, consumo, TAMANHO);
 
    printf("\n  Trocas realizadas pelo Bubble Sort: %d\n", trocas);
 
    /* 5) Resumo para tomada de decisao */
    if (opcao == 1) {
        printf("  Menor consumo: %s (%.1f kWh)\n", nomes[0], consumo[0]);
        printf("  Maior consumo: %s (%.1f kWh)\n", nomes[TAMANHO - 1], consumo[TAMANHO - 1]);
    } else {
        printf("  Maior consumo: %s (%.1f kWh)\n", nomes[0], consumo[0]);
        printf("  Menor consumo: %s (%.1f kWh)\n", nomes[TAMANHO - 1], consumo[TAMANHO - 1]);
    }
    printf("\n  Dica: comece a economizar pelos aparelhos do topo do ranking\n");
    printf("  de maior consumo.\n\n");
 
    return 0;
}
 
