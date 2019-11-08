#include "Data.h"

Data::Data()
{
    dia = 0;
    mes = 0;
    ano = 0;
}

Data::Data(int dia, int mes, int ano)
{
    setData(dia, mes, ano);
}

Data::~Data()
{

}

void Data::setData(int dia, int mes, int ano)
{
    
    if (mes > 12 || mes < 1 || dia < 0 || ano < 0) {
        /*Função de Controle*/
        return;
    }
    else if ((mes < 8 && mes % 2 != 0) || (mes > 7 && mes % 2 == 0)) {
        if (dia > 31) {
            /*Função de Controle*/
            return;
        }
    }
    else if (dia > 30) {
        /*Função de Controle*/
        return;
    }   
    
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;

}

const int Data::getDia()
{
    return dia;
}

const int Data::getMes()
{
    return mes;
}

const int Data::getAno()
{
    return ano;
}
