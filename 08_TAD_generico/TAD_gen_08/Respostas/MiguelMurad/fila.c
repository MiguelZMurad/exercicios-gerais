#include "vector.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef struct Fila Fila;*/
struct Fila {
    int tam;
    DataType *p;
    //Vector *v;
};
/**
 * @brief Cria uma fila vazia
 * 
 * @return A estrutura Fila inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Fila *FilaConstruct() {
    Fila *f = (Fila*) malloc (sizeof(Fila));

    //f->v = VectorConstruct();
    f->p = (DataType*) malloc (sizeof(DataType));
    f->tam = 0;

    return f;
}

/**
 * @brief Desaloca a memória alocada para a fila
 * 
 * @param f Ponteiro para a fila
 * @param destroy Função que desaloca a memória alocada para cada elemento da fila
*/
void FilaDestroy(Fila *f, void (*destroy)(DataType)) {
    for (int i = 0; i < f->tam; i++) {
        destroy(f->p[i]);
    }
    free(f->p);
    free(f);
}

/**
 * @brief Retorna o tamanho da fila
 * 
 * @param f Ponteiro para a fila
 * @return int Tamanho da fila
*/
int FilaSize(Fila *f) {
    return f->tam;
}

/**
 * @brief Remove o primeiro elemento da fila
 * OBS: Note que a fila é uma estrutura FIFO (First In, First Out), ou seja, o primeiro elemento a ser adicionado é o primeiro a ser removido.
 * Portanto, apesar da fila estar implementada com um vector, ele não é adequado para implementar uma fila, pois a remoção de um elemento do início do vetor é uma operação custosa.
 * @param f Ponteiro para a fila
 * @return DataType Elemento removido
*/
DataType FilaPop(Fila *f) {
    DataType fi = f->p[0];

    for (int i = 1; i < f->tam; i++) {
        f->p[i - 1] = f->p[i];
    }

    f->tam--;

    return fi;
}

/**
 * @brief Adiciona um elemento no final da fila
 * 
 * @param f Ponteiro para a fila
 * @param val Valor a ser adicionado
*/
void FilaPush(Fila *f, DataType val) {
    f->tam++;

    f->p = realloc (f->p, f->tam * sizeof(DataType));

    f->p[f->tam-1] = val;
}