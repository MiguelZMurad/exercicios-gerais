#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define INITIAL_CAPACITY 4

struct Vector {
    DataType *data;
    int size;
    int capacity;
};

// Função para criar um vetor vazio
Vector *VectorConstruct() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    if (v == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o vetor.\n");
        exit(EXIT_FAILURE);
    }
    v->data = (DataType *)malloc(INITIAL_CAPACITY * sizeof(DataType));
    if (v->data == NULL) {
        free(v);
        fprintf(stderr, "Erro ao alocar memória para os dados do vetor.\n");
        exit(EXIT_FAILURE);
    }
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
    return v;
}

// Função para adicionar um elemento no final do vetor
void VectorPushBack(Vector *v, DataType val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (DataType *)realloc(v->data, v->capacity * sizeof(DataType));
        if (v->data == NULL) {
            fprintf(stderr, "Erro ao realocar memória para o vetor.\n");
            exit(EXIT_FAILURE);
        }
    }
    v->data[v->size++] = val;
}

// Função para retornar o i-ésimo elemento do vetor
DataType VectorGet(Vector *v, int i) {
    if (i < 0 || i >= v->size) {
        fprintf(stderr, "Índice fora dos limites do vetor.\n");
        exit(EXIT_FAILURE);
    }
    return v->data[i];
}

// Função para retornar o tamanho do vetor
int VectorSize(Vector *v) {
    return v->size;
}

// Função para liberar a memória alocada para o vetor
void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    for (int i = 0; i < v->size; i++) {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}
