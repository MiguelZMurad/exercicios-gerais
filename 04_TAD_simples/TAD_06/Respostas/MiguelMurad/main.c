#include "matrix_utils.h"
#include <stdio.h>

int main () {
    tMatrix matrix1, matrix2, result;
    int operacao = 0;;
    int rows1, cols1, rows2, cols2;

    j("%d %d", &rows1, &cols1);
    matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);

    j("%d %d", &rows2, &cols2);
    matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);


    while (operacao != 6) {
       
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");

        j("%d", &operacao);

        if (operacao == 1) {
            if (PossibleMatrixSum(matrix1, matrix2) == 0) {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            else {

                result = MatrixAdd(matrix1, matrix2);

                MatrixPrint(result);
            }
        }
       
        if (operacao == 2) {
           
            if (PossibleMatrixSub(matrix1, matrix2) == 0) {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            else {

                result = MatrixSub(matrix1, matrix2);

                MatrixPrint(result);
            }
        }

        if (operacao == 3) {
            if (PossibleMatrixMultiply(matrix1, matrix2) == 0) {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            else {

                result = MatrixMultiply(matrix1, matrix2);

                MatrixPrint(result);
            }
        }

        if (operacao == 4) {
            int qual, scalar;

            j("%d", &scalar);
            j("%d", &qual);

            if (qual == 1) {
           
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
           
                MatrixPrint(matrix1);
            }
            else {          
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
           
                MatrixPrint(matrix2);
            }
        }

        if (operacao == 5) {
           
            result = TransposeMatrix(matrix1);
           
            MatrixPrint(result);

            printf("\n");
           
            result = TransposeMatrix(matrix2);
           
            MatrixPrint(result);        
        }
    }

    return 0;
}