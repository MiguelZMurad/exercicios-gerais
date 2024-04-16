#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>


tJogo CriaJogo() {
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);

    return jogo;
}


void ComecaJogo(tJogo jogo) {
    int continua = 1, acabou = 0;

    while (1) {

        if (continua == 1) {
            jogo = CriaJogo();
        }
        continua = 0;

        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        
        if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
            acabou = 1;
            printf("JOGADOR 1 Venceu!\n");
            printf("Jogar novamente? (s,n)\n");
        }

        if (acabou == 0) {
            if (AcabouJogo(jogo)) {
                acabou = 1;
                printf("Sem vencedor!\n");
                printf("Jogar novamente? (s,n)\n");
            }
        }

        if (acabou == 0) {
            
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            
            if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
                acabou = 1;
                printf("JOGADOR 2 Venceu!\n");
                printf("Jogar novamente? (s,n)\n");

            }
            if (AcabouJogo(jogo)) {
                acabou = 1;
                printf("Sem vencedor!\n");
                printf("Jogar novamente? (s,n)\n");

            }
        }

        if (acabou == 1) {
            continua = ContinuaJogo();
            if (continua == 1) {
                acabou = 0;
            }
            else {
                break;
            }
        }
    }
    exit(0);
}


int AcabouJogo(tJogo jogo) {
    
    if (TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        return 0;
    }

    return 1;
}

int ContinuaJogo() {
    char resp, mantem = 1;

    while (mantem == 1) {
        scanf("\n%c", &resp);
        
        if (resp == 's' || resp == 'n') {
            mantem = 0;
        }
    }

    if (resp == 's') {
        return 1;
    }
    if (resp == 'n') {
        return 0;
    }
}