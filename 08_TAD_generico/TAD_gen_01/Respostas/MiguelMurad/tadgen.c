#include "tadgen.h"
#include <stdio.h>

/*typedef enum {
    FLOAT = 0,
    INT = 1
} Type;*/

struct generic {
    void *dado;
    int tam;
    Type tipo;
};


/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric *g = (tGeneric*) malloc (sizeof(tGeneric));

    g->tam = numElem;
    g->tipo = type;

    switch (type) {
        case INT:
            g->dado = malloc (numElem * sizeof(int));
            break;

        case FLOAT:
            g->dado = malloc (numElem * sizeof(float));
            break;
    }

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen) {

    free(gen->dado);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen) {
    int i;
    
    switch (gen->tipo) {
        case INT:
            int *intData = (int*)gen->dado;
            for (i = 0; i < gen->tam; i++) {
                scanf("%d", &intData[i]);
            }
            break;

        case FLOAT: 
        float *floatData = (float*)gen->dado;
            for (i = 0; i < gen->tam; i++) {
                scanf("%f", &floatData[i]);
            }
            break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen) {
    int i;

    switch (gen->tipo) {
        case INT:
            int *intData = (int*)gen->dado;
            for (i = 0; i < gen->tam; i++) {
                printf("%d ", intData[i]);
            }
            break;

        case FLOAT: 
            float *floatData = (float*)gen->dado;
            for (i = 0; i < gen->tam; i++) {
                printf("%.2f ", floatData[i]);
            }
            break;
    }
    printf("\n");

}

