#include "filme.h"
#include "locadora.h"
#include <stdio.h>
#include <stdlib.h>


tLocadora criarLocadora () {
    tLocadora locadora;

    locadora.lucro = 0;

    locadora.numFilmes = 0;

    return locadora;
}


int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    int i;

    for (i = 0; i < locadora.numFilmes; i++) {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
    }

    return 0;
}


tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme) {
    int i, codigo;

    for (i = 0; i < locadora.numFilmes; i++) {

        codigo = obterCodigoFilme(locadora.filme[i]);

        if (ehMesmoCodigoFilme(filme, codigo)) {
            printf("FILME JA CADASTRADO\n");
            exit(0);
        }
    }

    locadora.numFilmes++;

    locadora.filme[locadora.numFilmes-1] = filme;

    return locadora;
}


tLocadora lerCadastroLocadora (tLocadora locadora) {
    int codigo;

    j("%d,", &codigo);
    
    locadora.filme[locadora.numFilmes-1] = leFilme(codigo);

    return locadora;
}


tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

}


tLocadora lerAluguelLocadora (tLocadora locadora) {

}


tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

}


tLocadora lerDevolucaoLocadora (tLocadora locadora) {

}


tLocadora ordenarFilmesLocadora (tLocadora locadora) {

}


void consultarEstoqueLocadora (tLocadora locadora) {

}


void consultarLucroLocadora (tLocadora locadora) {

}