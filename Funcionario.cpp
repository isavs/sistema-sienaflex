#include "Funcionario.h"

Funcionario::Funcionario()
{
    salario = 0.0;
}

Funcionario::Funcionario(int i, char* nome, long int cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento, double salario):
id(i, nome),
endereco(cep, rua, numero, bairro, cidade, estado, pais, complemento)
{
    this->salario = salario;
}

Funcionario::~Funcionario()
{

}