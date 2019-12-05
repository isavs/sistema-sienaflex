#pragma once

class UData
{
public:
    int dia;
    int mes;
    int ano;

public:
    UData();
    UData(int dia, int mes, int ano);
    ~UData();
    void setData(int dia, int mes, int ano);
    const int getDia();
    const int getMes();
    const int getAno();
};
