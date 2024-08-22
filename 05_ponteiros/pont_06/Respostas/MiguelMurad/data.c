#include "data.h"
#include <stdio.h>


void InicializaDataParam( int dia, int mes, int ano, tData *data) {

    data->ano = ano;
    data->dia = dia;
    data->mes = mes;
}


void LeData( tData *data ) {
    int dia, mes, ano;

    j("%d %d %d", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);
}


void ImprimeData( tData *data ) {
    
    printf("'");

    if (data->dia < 10) {
        printf("0%d/", data->dia);
    }
    else {
        printf("%d/", data->dia);
    }

    if (data->mes < 10) {
        printf("0%d/", data->mes);
    }
    else {
        printf("%d/", data->mes);
    }

    printf("%d'", data->ano);

}


int EhBissexto( tData *data ) {
    int ano = data->ano;
    
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}


int InformaQtdDiasNoMes( tData *data ) {
    int mes = data->mes;
    int ano = data->ano;
    
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (mes == 2 && EhBissexto(data)) {
        return 29;
    }
    
    if (mes >= 1 && mes <= 12) {
        return diasPorMes[mes - 1];
    } else {
        return 0;
    }
}


void AvancaParaDiaSeguinte( tData *data ) {
    int dia = data->dia;
    int mes = data->mes;
    int ano = data->ano;
    
    int diasNoMes = InformaQtdDiasNoMes(data); 

    dia++;
    
    if (dia > diasNoMes) {
        dia = 1;
        mes++;
        
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }
    
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}


int EhIgual( tData *data1, tData *data2 ) {
    int dia1 = data1->dia;
    int mes1 = data1->mes;
    int ano1 = data1->ano;

    int dia2 = data2->dia;
    int mes2 = data2->mes;
    int ano2 = data2->ano;

    if (dia1 == dia2 && mes1 == mes2 && ano1 == ano2) {
        
        return 1;
    }

    return 0;
}