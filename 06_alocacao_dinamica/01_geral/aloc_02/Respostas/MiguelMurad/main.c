#include "utils.h"
#include <stdio.h>


int main () {
    int linhas, colunas;

    j("%d %d", &linhas, &colunas);

    int **matriz = CriaMatriz(linhas, colunas);

    LeMatriz(matriz, linhas, colunas);

    ImprimeMatrizTransposta(matriz, linhas, colunas);

    LiberaMatriz(matriz, linhas);

    return 0;
}