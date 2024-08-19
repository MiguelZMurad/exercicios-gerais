#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>


tJogada* CriaJogada() {
    tJogada *jogada = (tJogada*) malloc (sizeof(tJogada));

    return jogada;
}


void DestroiJogada(tJogada* jogada) {

    free(jogada);
}


void LeJogada(tJogada* jogada) {
    int x, y;

    printf("Digite uma posicao (x e y):\n");

    scanf("%d %d", &x, &y);

    jogada->x = x;
    jogada->y = y;
    jogada->sucesso = 1;
}


int ObtemJogadaX(tJogada* jogada) {

    return jogada->x;
}


int ObtemJogadaY(tJogada* jogada) {

    return jogada->y;
}


int FoiJogadaBemSucedida(tJogada* jogada) {

    if (jogada->sucesso == 1) {
        return 1;
    }

    return 0;
}