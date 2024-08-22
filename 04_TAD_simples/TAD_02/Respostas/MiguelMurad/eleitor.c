#include "eleitor.h"
#include <stdio.h>


tEleitor CriaEleitor(int id, int votoP, int votoG) {
    tEleitor eleitor;

    eleitor.id = id;

    eleitor.votoG = votoG;

    eleitor.votoP = votoP;

    return eleitor;
}


tEleitor LeEleitor() {
    int id, votog, votop;
    tEleitor eleitor;

    j("%d %d %d", &id, &votop, &votog);

    eleitor = CriaEleitor(id, votop, votog);

    return eleitor;
}


int ObtemVotoPresidente(tEleitor eleitor) {

    return eleitor.votoP;
}


int ObtemVotoGovernador(tEleitor eleitor) {

    return eleitor.votoG;
}


int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2) {

    if (eleitor1.id == eleitor2.id) {
        if (eleitor1.votoG == eleitor2.votoG) {
            if (eleitor1.votoP == eleitor2.votoP) {
                return 1;
            }
        }
    }

    return 0;
}