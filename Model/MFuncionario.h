#pragma once
#include "MPessoa.h"

class MFuncionario: public MPessoa
{
protected:
    int id;
    string cargo;
    double salario;

public:
    MFuncionario();
    MFuncionario(int id, string nome);
    MFuncionario(int id, string nome, string cpf, string telefone, UEndereco endereco, string cargo, double salario);
    ~MFuncionario();
    void setId(int id);
    void setCargo(string cargo);
    void setSalario(double salario);
    const int getId();
    const string getCargo();
    const double getSalario();
};
