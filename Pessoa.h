#pragma once
#include <iostream>

#include "Identidade.h"
#include "Endereco.h"

class Pessoa
{
protected:
    Identidade id;
    Endereco endereco;

public:
    Pessoa();
    ~Pessoa();
};