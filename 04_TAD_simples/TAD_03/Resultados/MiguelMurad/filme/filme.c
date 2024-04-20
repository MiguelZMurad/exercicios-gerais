#include "filme.h"
#include <string.h>
#include <stdio.h>


tFilme criarFilme (char* nome, int codigo, int valor, int quantidade) {
    tFilme filme;

    strcpy(filme.nome, nome);

    filme.codigo = codigo;

    filme.qtdAlugada = 0;

    filme.qtdEstoque = quantidade;

    filme.valor = valor;

    return filme;
}


tFilme leFilme(int codigo) {
    char nome[20];
    int qtd, valor;
    tFilme filme;

    scanf("%[^,],%d,%d\n", nome, &valor, &qtd);

    filme = criarFilme(nome, codigo, valor, qtd);

    return filme;
}


int obterCodigoFilme (tFilme filme) {

    return filme.codigo;
}


void imprimirNomeFilme (tFilme filme) {

    printf("%s", filme.nome);
}


int obterValorFilme (tFilme filme) {

    return filme.valor;
}


int obterQtdEstoqueFilme (tFilme filme) {

    return filme.qtdEstoque;
}


int obterQtdAlugadaFilme (tFilme filme) {

    return filme.qtdAlugada;
}


int ehMesmoCodigoFilme (tFilme filme, int codigo) {

    if (filme.codigo == codigo) {
        return 1;
    }

    return 0;
}


tFilme alugarFilme (tFilme filme) {

    filme.qtdAlugada++;
    filme.qtdEstoque--;

    return filme;
}


tFilme devolverFilme (tFilme filme) {

    filme.qtdAlugada--;
    filme.qtdEstoque++;

    return filme;
}


int compararNomesFilmes (tFilme filme1, tFilme filme2) {

    return strcmp(filme1.nome, filme2.nome);
}