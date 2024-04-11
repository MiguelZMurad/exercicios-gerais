#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro() {
    int i = 0, j = 0;
    tTabuleiro tabuleiro;

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; i < TAM_TABULEIRO; j++) {
            tabuleiro.posicoes[i][j] = '-';
        }
    }

    return tabuleiro;
}


tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    
    if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
        tabuleiro.posicoes[x][y] = peca;
    }

    return tabuleiro;
}


int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    int i = 0, j = 0;

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; i < TAM_TABULEIRO; j++) {
            if (tabuleiro.posicoes[i][j] = '-') {
                return 1;
            }
        }
    }

    return 0;
}


int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    
    if (tabuleiro.posicoes[x][y] == peca) {
        return 1;
    }

    return 0;
}


int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    
    if (tabuleiro.posicoes[x][y] == '-') {
        return 1;
    }

    return 0;
}


int EhPosicaoValidaTabuleiro(int x, int y) {

    if (x > 2 || x < 0 || y > 2 || y < 0) {
        return 0;
    }

    return 1;
}


void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    int i = 0, j = 0;


    for (i = 0; i < TAM_TABULEIRO; i++) {

        printf("\t");
        
        for (j = 0; i < TAM_TABULEIRO; j++) {
            if (tabuleiro.posicoes[i][j] == '1') {
                printf("X");
            }
            if (tabuleiro.posicoes[i][j] == '2') {
                printf("0");
            }
            if (tabuleiro.posicoes[i][j] == '-') {
                printf("-");
            }
        }
        printf("\n");
    }


}
