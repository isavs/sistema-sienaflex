#pragma once
#include <iostream>

#include "Identidade.h"
#include "Endereco.h"

class Pessoa
{
protected:
    //Identidade id;
    char* nome;
    char* cpf;
    char* telefone;
    Endereco endereco;

public:
    Pessoa();
    Pessoa(char* nome, char* cpf, char* telefone);
    Pessoa(char* nome, Endereco endereco);
    ~Pessoa();
};