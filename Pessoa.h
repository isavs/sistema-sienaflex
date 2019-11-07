#pragma once
#include <iostream>
#include "Endereco.h"

class Pessoa
{
protected:
    //Identidade id;
    char* nome;
    char* cpf;
    char* telefone;
    //char* email;
    Endereco endereco;

public:
    Pessoa();
    Pessoa(char* nome, char* cpf, char* telefone, Endereco endereco);
    ~Pessoa();
    const char* getNome();
    const char* getCpf();
    const char* getTelefone();
};