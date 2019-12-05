#pragma once
#include <iostream>
#include "Endereco.h"
#include <string>
using namespace std;

class Pessoa
{
protected:
    string nome;
    string cpf;
    string telefone;
    Endereco endereco;

public:
    Pessoa();
    Pessoa(string nome);
    Pessoa(string nome, string cpf, string telefone, Endereco endereco);
    ~Pessoa();
    const string getNome();
    const string getCpf();
    const string getTelefone();
    Endereco getEndereco();
};
