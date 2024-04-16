#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include "stdio.h"

int main () {
    tJogo jogo;

    jogo = CriaJogo();

    while (ContinuaJogo()) {
        ComecaJogo(jogo);
    }

    return 0;
}