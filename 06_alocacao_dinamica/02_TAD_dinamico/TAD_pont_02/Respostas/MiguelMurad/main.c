#include "eleicao.h"
#include <stdio.h>


int main () {
    tEleicao *eleicao = InicializaEleicao();

    RealizaEleicao(eleicao);

    ImprimeResultadoEleicao(eleicao);

    ApagaEleicao(eleicao);

    return 0;
}