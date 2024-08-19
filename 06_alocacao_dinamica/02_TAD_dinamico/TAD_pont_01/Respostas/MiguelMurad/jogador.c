#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>


tJogador* CriaJogador(int idJogador) {
    tJogador *jogador = (tJogador*) malloc (sizeof(tJogador));

    if (idJogador == ID_JOGADOR_1) {
        jogador->id = ID_JOGADOR_1;
    }
    else {
        jogador->id = ID_JOGADOR_2;
    }

    return jogador;
}


void DestroiJogador(tJogador* jogador) {
    free(jogador);
}


void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro) {
    tJogada *jogada = CriaJogada();

    LeJogada(jogada);

    
}