#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef enum {
    INT = 1,
    CHAR = 2
} Type;

typedef struct pacote tPacote;*/

struct pacote {
    Type tipo;
    int tam;
    int soma;
    void *dado;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem) {
    tPacote *p = (tPacote*) malloc (sizeof(tPacote));

    p->tam = numElem;
    p->tipo = type;
    p->soma = 0;

    switch (p->tipo) {

        case INT:
            p->dado = malloc (numElem * sizeof(int));
            break;

        case CHAR:
            p->dado = malloc (numElem * sizeof(char));
            break;
    }

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac) {

    free(pac->dado);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac) {
    int i;
    char c;

    printf("\nDigite o conteúdo do vetor/mensagem:\n");

    switch (pac->tipo) {
        case INT:
            int *intDado = (int*)pac->dado;
            for (i = 0; i < pac->tam; i++) {
                scanf("%d", &intDado[i]);
            }
            break;

        case CHAR:
            char *charDado = (char*)pac->dado;
            scanf("\n");
            for (i = 0; i < pac->tam; i++) {
                scanf("%c", &charDado[i]);
                //printf("i: %d -> %c ", i, charDado[i]);
            }
            //printf("\n");
            break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac) {
    int i;

    switch (pac->tipo) {
        case INT:
            int *intDado = (int*)pac->dado;
            CalculaSomaVerificacaoPacote(pac);
            printf("%d ", pac->soma);
            for (i = 0; i < pac->tam; i++) {
                printf("%d ", intDado[i]);
            }
            break;

        case CHAR:
            char *charDado = (char*)pac->dado;
            CalculaSomaVerificacaoPacote(pac);
            printf("%d ", pac->soma);
            for (i = 0; i < pac->tam; i++) {
                printf("%c", charDado[i]);
            }
            break;
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac) {
    int i, soma = 0;

    switch (pac->tipo) {
        case INT:
            int *intDado = (int*)pac->dado;
            for (i = 0; i < pac->tam; i++) {
                soma += intDado[i];
            }
            break;

        case CHAR:
            char *charDado = (char*)pac->dado;
            for (i = 0; i < pac->tam; i++) {
                soma += charDado[i];
            }
            break;
    }

    pac->soma = soma;
}
