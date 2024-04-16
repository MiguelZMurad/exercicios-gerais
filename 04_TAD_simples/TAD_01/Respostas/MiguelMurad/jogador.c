#include <stdio.h>
#include "jogador.h"
#include "jogada.h"


tJogador CriaJogador(int idJogador) {
    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}


tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int peca, flag = 0;;
    tJogada jogada;

    while (flag == 0) {
        if (jogador.id == ID_JOGADOR_1) {
            peca = 1;
            printf("Jogador 1\n");
        }
        else {
            peca = 2;
            printf("Jogador 2\n");
        }

        jogada = LeJogada();

        if (!FoiJogadaBemSucedida(jogada)) {
            printf("JOGADA INVALIDA\n");
        } 
        else {
            if (EhPosicaoValidaTabuleiro(jogada.x, jogada.y)) {
                if (EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y)) {
                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, jogada.x, jogada.y);
                    printf("Jogada [%d,%d]!\n", jogada.x, jogada.y);
                    flag = 1;
                }
                else {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
                }
            }
            else {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada.x, jogada.y);
            }
        }
    }

    return tabuleiro;
}


int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int i = 0, j = 0;

    if (jogador.id == ID_JOGADOR_1) {
        for (i = 0; i < TAM_TABULEIRO; i++) {
            for (j = 0; j < TAM_TABULEIRO; j++) {
                if (tabuleiro.posicoes[i][j] == tabuleiro.peca1) {

                    if (i == 0) {
                        if (j == 0) {
                            if (tabuleiro.posicoes[1][0] == tabuleiro.peca1 && tabuleiro.posicoes[2][0] == tabuleiro.peca1) {
                                return 1;
                            }
                            if (tabuleiro.posicoes[0][1] == tabuleiro.peca1 && tabuleiro.posicoes[0][2] == tabuleiro.peca1) {
                                return 1;
                            }
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca1 && tabuleiro.posicoes[2][2] == tabuleiro.peca1) {
                                return 1;
                            }
                        }
                        if (j == 1) {
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca1 && tabuleiro.posicoes[2][1] == tabuleiro.peca1) {
                                return 1;
                            }
                        }
                        if (j == 2) {
                            if (tabuleiro.posicoes[1][2] == tabuleiro.peca1 && tabuleiro.posicoes[2][2] == tabuleiro.peca1) {
                                return 1;
                            }
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca1 && tabuleiro.posicoes[2][0] == tabuleiro.peca1) {
                                return 1;
                            }
                        }
                    }

                    if (i == 1) {
                        if (j == 0) {
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca1 && tabuleiro.posicoes[1][2] == tabuleiro.peca1) {
                                return 1;
                            }
                        }
                    }

                    if (i == 2) {
                        if (j == 0) {
                            if (tabuleiro.posicoes[2][1] == tabuleiro.peca1 && tabuleiro.posicoes[2][2] == tabuleiro.peca1) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }


    if (jogador.id == ID_JOGADOR_2) {
        for (i = 0; i < TAM_TABULEIRO; i++) {
            for (j = 0; j < TAM_TABULEIRO; j++) {
                if (tabuleiro.posicoes[i][j] == tabuleiro.peca2) {

                    if (i == 0) {
                        if (j == 0) {
                            if (tabuleiro.posicoes[1][0] == tabuleiro.peca2 && tabuleiro.posicoes[2][0] == tabuleiro.peca2) {
                                return 1;
                            }
                            if (tabuleiro.posicoes[0][1] == tabuleiro.peca2 && tabuleiro.posicoes[0][2] == tabuleiro.peca2) {
                                return 1;
                            }
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca2 && tabuleiro.posicoes[2][2] == tabuleiro.peca2) {
                                return 1;
                            }
                        }
                        if (j == 1) {
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca2 && tabuleiro.posicoes[2][1] == tabuleiro.peca2) {
                                return 1;
                            }
                        }
                        if (j == 2) {
                            if (tabuleiro.posicoes[1][2] == tabuleiro.peca2 && tabuleiro.posicoes[2][2] == tabuleiro.peca2) {
                                return 1;
                            }
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca2 && tabuleiro.posicoes[2][0] == tabuleiro.peca2) {
                                return 1;
                            }
                        }
                    }

                    if (i == 1) {
                        if (j == 0) {
                            if (tabuleiro.posicoes[1][1] == tabuleiro.peca2 && tabuleiro.posicoes[1][2] == tabuleiro.peca2) {
                                return 1;
                            }
                        }
                    }

                    if (i == 2) {
                        if (j == 0) {
                            if (tabuleiro.posicoes[2][1] == tabuleiro.peca2 && tabuleiro.posicoes[2][2] == tabuleiro.peca2) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}


    