#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int casos;
    
    j("%d", &casos);
    
    while(casos){
        int tam;
        
        j("%d", &tam);
        int vet[tam];
        
        LeDadosParaVetor(vet, tam);
        OrdeneCrescente(vet, tam);
        ImprimeDadosDoVetor(vet, tam);
        
        casos--;
    }
    
    return 0;
}