#pragma once
#include "Pessoa.h"

class Funcionario: public Pessoa
{
private:
    double salario;

public:
    Funcionario();
    Funcionario(int id, char* nome, long int cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento, double salario);
    ~Funcionario();
};