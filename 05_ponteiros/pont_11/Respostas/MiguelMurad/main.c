#include "calculadora.h"
#include <stdio.h>


float a(float n1, float n2) {

    return n1+n2;
}


float s(float n1, float n2) {

    return n1-n2;
}


float m(float n1, float n2) {

    return n1*n2;
}


float d(float n1, float n2) {

    return n1/n2;
}


char QualSinal(char op) {

    if (op == 'a') {
        return '+';
    } 
    if (op == 's') {
        return '-';
    }
    if (op == 'm') {
        return 'x';
    }
    if (op == 'd') {
        return '/';
    }
    
}


int main () {
    char op, sinal;
    float num1, num2;
    float result;

    while (1) {
        j("%c\n", &op);

        if (op == 'f') {
            break;
        }

        sinal = QualSinal(op);

        j("%f %f\n", &num1, &num2);

        switch (op) {
            case 'a':
                result = Calcular(num1, num2, a);
                break;
            case 's':
                result = Calcular(num1, num2, s);
                break;
            case 'm':
                result = Calcular(num1, num2, m);
                break;
            case 'd':
                result = Calcular(num1, num2, d);
                break;
        }

        printf("%.2f %c %.2f = %.2f\n", num1, sinal, num2, result);
    }

    return 0;
}