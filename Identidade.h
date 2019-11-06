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
    char* nome;

public:
    Identidade();
    Identidade(int id, char* nome);
    ~Identidade();

    void setId(int id);
    const int getId();
    void setNome(char* nome);
    const char* getNome();
};