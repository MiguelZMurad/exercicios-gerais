#include <stdio.h>
#include "tabuleiro.h"
#include "string.h"

tTabuleiro CriaTabuleiro() {
    int i = 0, j = 0;
    tTabuleiro tabuleiro; 

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    
    for (i = 0; i < TAM_TABULEIRO ; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro.posicoes[i][j] = '-';
        }
    }
    return tabuleiro;
}


tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    
    if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
        if (peca == PECA_1) {
            tabuleiro.posicoes[y][x] = 'X';
        }
        else {
            tabuleiro.posicoes[y][x] = '0';

        }
    }

    return tabuleiro;
}


int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    int i = 0, j = 0;

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro.posicoes[i][j] == '-') {
                return 1;
            }
        }
    }

    return 0;
}


int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    
    if (peca == PECA_1) { 
        if (tabuleiro.posicoes[y][x] == 'X') {
            return 1;
        }
    }
    else {
        if (tabuleiro.posicoes[y][x] == '0') {
            return 1;
        }
    }

    return 0;
}


int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    
    if (tabuleiro.posicoes[y][x] == '-') {
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

        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}
