#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "Data.h"

class Identidade
{
private:
    int id;
    char *nome;

    Data data;

public:
    Identidade();
    ~Identidade();

    void setId(int id);
    int getId();
    void setNome(char* nome);
    const char* getNome();
    void setDataCadastro(int dia, int mes, int ano);
};