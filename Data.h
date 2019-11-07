#pragma once

class Data
{
public:
    int dia;
    int mes;
    int ano;

public:
    Data();
    Data(int dia, int mes, int ano);
    ~Data();
    void setData(int dia, int mes, int ano);
    void setDataVerificada(int dia, int mes, int ano);
    int getDia();
    int getMes();
    int getAno();
};