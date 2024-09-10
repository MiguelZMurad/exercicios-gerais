#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief Estrutura representando um Movel.
 
typedef struct Movel tMovel;*/

struct Movel {
    char *nome;
};

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome) {
    tMovel *m = (tMovel*) malloc (sizeof(tMovel));

    m->nome = malloc (strlen(nome)+1 * sizeof(char));

    strcpy(m->nome, nome);

    return m;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m) {
    free(m->nome);
    free(m);
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel() {
    char nome[30];

    scanf("%[^\n]", nome);

    tMovel *m = CriaMovel(nome);

    return m;
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m) {
    printf("%s\n", m->nome);
}