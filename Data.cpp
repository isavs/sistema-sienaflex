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
    if (dia > 0)
    {
        if (mes == 2)
        {
            if (dia < 29)
            {
                this->dia = dia;
                this->mes = mes;
                this->ano = ano;
            }
            else
            {
                /* code */
            }
        }
        else if (mes < 8)
        {
            if (mes % 2 == 1)
            {
                if (dia < 32)
                {
                    this->dia = dia;
                    this->mes = mes;
                    this->ano = ano;
                }
                else {
                    //funcoes de controle
                }
            }
            else
            {
                if (dia < 31)
                {
                    this->dia = dia;
                    this->mes = mes;
                    this->ano = ano;
                }
                else {
                    //funcoes de controle
                }
            }
        }
        else if (mes >= 8)
        {
            if (mes % 2 == 0)
            {
                if (dia < 32)
                {
                    this->dia = dia;
                    this->mes = mes;
                    this->ano = ano;
                }
                else {
                    //funcoes de controle
                }
            }

        }
    }
    //this->dia = dia;
    //this->mes = mes;
    t//his->ano = ano;
}