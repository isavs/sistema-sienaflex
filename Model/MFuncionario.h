#pragma once
#include "MPessoa.h"

class MFuncionario: public MPessoa
{
protected:
    int id;
    double salario;
    bool ativo;

public:
    MFuncionario();
    MFuncionario(int id, string nome);
    MFuncionario(int id, string nome, string cpf, string telefone, UEndereco endereco, double salario);
    ~MFuncionario();
    void setId(int id);
    void setSalario(double salario);
    void setStatus(bool ativo);
    const int getId();
    const double getSalario();
    const bool getStatus();
};
