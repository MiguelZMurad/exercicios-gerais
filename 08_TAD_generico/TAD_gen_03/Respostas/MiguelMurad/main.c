#include <stdio.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main() {
    int n;
    scanf("%d", &n);

    Vector *alunos = VectorConstruct();

    for (int i = 0; i < n; i++) {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(alunos, (data_type)aluno);
    }

    ImprimeRelatorio(alunos);

    VectorDestroy(alunos, DestroiAluno);

    return 0;
}
