#pragma once
#include "Pessoa.h"

class Funcionario: public Pessoa
{
private:
<<<<<<< HEAD
    static int quantidadeFuncionarios;
    int id;
=======
    static int id;
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d
    double salario;

public:
    Funcionario();
<<<<<<< HEAD
    Funcionario(string nome);
    Funcionario(string nome, string cpf, string telefone, Endereco endereco, double salario);
=======
    Funcionario(char* nome);
    Funcionario(int id, char* nome, char* cpf, char* telefone, Endereco endereco, double salario);
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d
    ~Funcionario();
    const int getId();
    const double getSalario();
};
