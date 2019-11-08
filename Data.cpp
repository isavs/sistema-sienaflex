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
    if (dia > 0){
        if (mes == 2){
            if (dia < 29){
                setDataVerificada(dia, mes, ano);
            }
            else {
                /* code */
            }
        }
        else if (mes < 8){
            if (mes % 2 == 1){
                if (dia < 32){
                    setDataVerificada(dia, mes, ano);
                }
                else {
                    //funcoes de controle
                }
            }
            else {
                if (dia < 31){
                    setDataVerificada(dia, mes, ano);
                }
                else {
                    //funcoes de controle
                }
            }
        }
        else if (mes >= 8){
            if (mes % 2 == 0){
                if (dia < 32){
                    setDataVerificada(dia, mes, ano);
                }
                else {
                    //funcoes de controle
                }
            }

        }
    }
}

void Data::setDataVerificada(int dia, int mes, int ano)
{
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
