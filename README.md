#  Classificador de Consumo de Energia — Bubble Sort em C

**Disciplina:** Algoritmos e Pensamento Computacional — UDF (Centro Universitário do Distrito Federal)
**Professora:** Profa. Karla R. Sartin

##  Integrantes

| Nome | GitHub |
|------|--------|
| Gustavo | [@Guhzerad3v](https://github.com/Guhzerad3v) |

##  Descrição do problema

Uma família quer reduzir a conta de luz, mas não sabe quais aparelhos da casa mais consomem energia. Com os valores de consumo (em kWh) anotados fora de ordem, é difícil perceber onde está o maior gasto e por onde começar a economizar.

Ordenar esses dados resolve o problema: com os equipamentos classificados por consumo, fica evidente quais são os "vilões" da conta e quais quase não pesam.

##  Objetivo da aplicação

Desenvolver um programa em C que armazena o consumo mensal de **10 equipamentos** de uma residência e os ordena com o algoritmo **Bubble Sort**, permitindo ao usuário escolher o critério:

- **Decrescente** → do maior para o menor consumo, para identificar onde a economia terá mais efeito.
- **Crescente** → do menor para o maior consumo, para ver os aparelhos de menor impacto.

O programa mostra os dados antes e depois da ordenação, informa o critério adotado e apresenta um resumo (total, maior e menor consumo, número de trocas).

##  Funcionamento do Bubble Sort

O Bubble Sort percorre o array várias vezes comparando **elementos adjacentes** (`consumo[j]` e `consumo[j + 1]`). Quando o par está fora de ordem, os dois são **trocados** com o auxílio de uma variável temporária. A cada passada, o maior (ou menor) valor restante "sobe" para o final do array, como uma bolha.

```c
for (i = 0; i < tamanho - 1; i++) {            // passadas pelo array
    for (j = 0; j < tamanho - 1 - i; j++) {    // compara vizinhos
        if (consumo[j] > consumo[j + 1]) {     // fora de ordem? (crescente)
            aux = consumo[j];                  // troca
            consumo[j] = consumo[j + 1];
            consumo[j + 1] = aux;
        }
    }
}
```

Detalhes da implementação:

- O laço interno vai até `tamanho - 1 - i`, porque os últimos `i` elementos já estão na posição final.
- Para a ordem decrescente, a comparação é invertida (`<` em vez de `>`).
- O nome do equipamento é trocado junto com o consumo, mantendo cada valor ligado ao aparelho certo.
- Se uma passada inteira não faz nenhuma troca, o laço é interrompido, pois o array já está ordenado.
- Nenhuma função pronta de ordenação (como `qsort()`) é usada.

## Como compilar e executar

Requisito: um compilador C, como o GCC.

```bash
gcc consumo_energia.c -o consumo_energia
./consumo_energia          # Linux / macOS
consumo_energia.exe        # Windows
```

Também é possível executar copiando o código para o [OnlineGDB](https://www.onlinegdb.com/) e selecionando a linguagem C.

##  Exemplo de entrada e saída

**Dados de entrada (array no código):**

| Equipamento | Consumo (kWh) |
|---|---|
| Geladeira | 150.0 |
| Televisao | 45.5 |
| Chuveiro eletrico | 320.8 |
| Carregador celular | 12.3 |
| Maquina de lavar | 89.0 |
| Ar-condicionado | 210.4 |
| Roteador Wi-Fi | 5.6 |
| Computador | 64.2 |
| Ferro de passar | 180.9 |
| Micro-ondas | 27.1 |

**Entrada do usuário:**

```
Escolha o criterio de ordenacao:
  1 - Crescente   (menor consumo -> maior consumo)
  2 - Decrescente (maior consumo -> menor consumo)
Opcao: 2
```

**Saída:**

```
>> DADOS ORDENADOS - criterio: DECRESCENTE (maior -> menor)

  +-----+--------------------------+--------------+
  | No. | Equipamento              | Consumo      |
  +-----+--------------------------+--------------+
  |   1 | Chuveiro eletrico        |    320.8 kWh |
  |   2 | Ar-condicionado          |    210.4 kWh |
  |   3 | Ferro de passar          |    180.9 kWh |
  |   4 | Geladeira                |    150.0 kWh |
  |   5 | Maquina de lavar         |     89.0 kWh |
  |   6 | Computador               |     64.2 kWh |
  |   7 | Televisao                |     45.5 kWh |
  |   8 | Micro-ondas              |     27.1 kWh |
  |   9 | Carregador celular       |     12.3 kWh |
  |  10 | Roteador Wi-Fi           |      5.6 kWh |
  +-----+--------------------------+--------------+
  |     | TOTAL                    |   1105.8 kWh |
  +-----+--------------------------+--------------+

  Trocas realizadas pelo Bubble Sort: 19
  Maior consumo: Chuveiro eletrico (320.8 kWh)
  Menor consumo: Roteador Wi-Fi (5.6 kWh)
```

##  Tecnologias e ferramentas utilizadas

- **Linguagem C**
- **GCC** — compilação
- **Visual Studio Code** / **OnlineGDB** — edição e testes
- **Git** — controle de versão
- **GitHub** — hospedagem do repositório

##  Estrutura do repositório

```
.
├── consumo_energia.c   # código-fonte da aplicação
└── README.md           # documentação do projeto
```

## Considerações finais

O projeto foi desenvolvido em etapas, registradas no histórico de commits: primeiro a estrutura com o array, depois o Bubble Sort em ordem crescente, a escolha do critério pelo usuário e, por fim, a associação dos nomes dos equipamentos e a apresentação em tabela.

A principal dificuldade foi manter cada consumo ligado ao nome do seu equipamento durante a ordenação, resolvida trocando os dois arrays ao mesmo tempo. Também aprendemos que o Bubble Sort, apesar de simples, pode ser otimizado ao interromper o processo quando nenhuma troca acontece.

Além de praticar arrays, laços de repetição e estruturas condicionais, o trabalho mostrou como a ordenação transforma uma lista de números em uma informação útil para a tomada de decisão.
