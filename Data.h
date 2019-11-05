#pragma once

class Data
{
public:
    int dia, mes, ano;
public:
    Data();
    Data(int dia, int mes, int ano);
    ~Data();
    void setData(int dia, int mes, int ano);
};