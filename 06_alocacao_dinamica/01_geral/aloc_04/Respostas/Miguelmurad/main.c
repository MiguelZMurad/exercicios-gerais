#include "utils_char2.h"
#include <stdio.h>


int main () {
    char *v = CriaVetorTamPadrao();
    int tam = 10;
    
    v = LeVetor(v, &tam);

    ImprimeString(v);

    LiberaVetor(v);

    return 0;
}