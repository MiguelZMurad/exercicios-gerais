#include "vector.h"
#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos) {
    int totalAlunos = VectorSize(alunos);
    int aprovados = 0;
    int countM = 0, countF = 0, countO = 0;
    float somaNotas = 0;

    for (int i = 0; i < totalAlunos; i++) {
        tAluno *aluno = (tAluno *)VectorGet(alunos, i);
        somaNotas += GetNotaAluno(aluno);

        if (GetNotaAluno(aluno) >= 6.0) {
            aprovados++;
        }

        char genero = GetGeneroAluno(aluno);
        if (genero == 'M') {
            countM++;
        } else if (genero == 'F') {
            countF++;
        } else if (genero == 'O') {
            countO++;
        }
    }

    float media = somaNotas / totalAlunos;
    float apro = (float)aprovados / totalAlunos * 100;
    float masc = (float)countM / totalAlunos * 100;
    float fem = (float)countF / totalAlunos * 100;
    float outros = (float)countO / totalAlunos * 100;


    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", apro);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", masc);
    printf("Feminino: %.2f%%\n", fem);
    printf("Outro: %.2f%%\n", outros);
}

