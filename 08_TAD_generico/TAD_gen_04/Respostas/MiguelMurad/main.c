#include "banco.h"
#include <stdio.h>
#include <stdlib.h>


int main () {
    tBanco *b = CriaBanco();

    LeBanco(b);

    while (1) {
        char com;
        
        scanf("\n%c", &com);

        if (com == 'A') {
            tAgencia *a = CriaAgencia();
            LeAgencia(a);
            AdicionaAgencia(b, a);
        }

        if (com == 'C') {
            int numConta;
            tConta *c = CriaConta();
            LeConta(c);
            scanf("%d", &numConta);
            InsereContaBanco(b, numConta, c);
        }

        if (com == 'F') {
            break;
        }
    }

    ImprimeRelatorioBanco(b);
    
    DestroiBanco(b);

    return 0;
}