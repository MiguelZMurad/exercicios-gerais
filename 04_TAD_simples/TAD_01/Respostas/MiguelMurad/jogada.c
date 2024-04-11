#include <stdio.h>
#include "jogada.h"



tJogada LeJogada() {
    tJogada jogada;

    scanf("%d %d", &jogada.x, &jogada.y);

    if (jogada.x < 0 || jogada.x > 2 || jogada.y > 2 || jogada.y < 0) {
        jogada.sucesso = 0;
    }
    else {
        jogada.sucesso = 1;
    }

    return jogada;
}


int ObtemJogadaX(tJogada jogada) {

    return jogada.x;
}


int ObtemJogadaY(tJogada jogada) {

    return jogada.y;
}


int FoiJogadaBemSucedida(tJogada jogada) {

    return jogada.sucesso;
}
