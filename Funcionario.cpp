#include "Funcionario.h"

<<<<<<< HEAD
int Funcionario::quantidadeFuncionarios = 0;
=======
int Funcionario::id = 0;
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d

Funcionario::Funcionario()
: Pessoa()
{
<<<<<<< HEAD
    id = ++quantidadeFuncionarios;
=======
    id++;
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d
    salario = 0.0;
}

/* Para testes */
<<<<<<< HEAD
Funcionario::Funcionario(string nome)
: Pessoa(nome)
{
    id = ++quantidadeFuncionarios;
=======
Funcionario::Funcionario(char* nome)
: Pessoa(nome)
{
    id++;
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d
}

Funcionario::Funcionario(string nome, string cpf, string telefone, Endereco endereco, double salario)
: Pessoa(nome, cpf, telefone, endereco)
{
    id = ++quantidadeFuncionarios;
    this->salario = salario;
}

Funcionario::~Funcionario()
{

}

const int Funcionario::getId()
{
    return id;
}

const double Funcionario::getSalario()
{
    return salario;
}
