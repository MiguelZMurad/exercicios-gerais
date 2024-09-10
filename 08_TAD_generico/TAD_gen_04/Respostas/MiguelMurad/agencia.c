#include "conta.h"
#include "vector.h"
#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * @brief Estrutura para representar uma agência bancária.
 
typedef struct Agencia tAgencia;*/

struct Agencia {
    int num;
    char nome[20];
    int qtdConta;
    tConta **c;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia() {
    tAgencia *a = (tAgencia*) malloc (sizeof(tAgencia));

    a->c = (tConta**) malloc (sizeof(tConta*));
    a->qtdConta = 0;

    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia) {
    int i;

    tAgencia *a = (tAgencia*) agencia;

    for (i = 0; i < a->qtdConta; i++) {
        DestroiConta(a->c[i]);
    }
    free(a->c);
    free(a);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia) {
    scanf("%d;%[^\n]", &agencia->num, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta) {
    agencia->qtdConta++;

    agencia->c = realloc (agencia->c, agencia->qtdConta * sizeof(tConta*));
    agencia->c[agencia->qtdConta-1] = conta;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    if (numAgencia == agencia2->num) {
        return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia) {
    int i;
    float soma = 0;

    for (i = 0; i < agencia->qtdConta; i++) {
        soma += GetSaldoConta(agencia->c[i]);
    }
    soma /= agencia->qtdConta;
    return soma;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("    Nome: %s\n    Numero: %d\n    Numero de contas cadastradas: %d\n    Saldo médio: R$%.2f\n\n", agencia->nome, agencia->num, agencia->qtdConta, GetSaldoMedioAgencia(agencia));
}