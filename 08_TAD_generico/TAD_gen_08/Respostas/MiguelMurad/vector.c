#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


/*typedef void *DataType; // void pointer
typedef struct Vector Vector;*/

struct Vector {
    DataType *p;
    int qtd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {
    Vector *v = (Vector*) malloc (sizeof(Vector));

    v->p = (DataType*) malloc (sizeof(DataType));
    v->qtd = 0;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val) {
    v->qtd++;

    v->p = realloc (v->p, v->qtd * sizeof(DataType));

    v->p[v->qtd-1] = val;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v) {
    DataType p = v->p[0];

    for (int i = 1; i < v->qtd; i++) {
        v->p[i - 1] = v->p[i];
    }

    v->qtd--;

    return p;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i) {

    return v->p[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {

    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    for (int i = 0; i < v->qtd; i++) {
        destroy(v->p[i]);
    }
    free(v->p);
    free(v);
}