#pragma once
#include <iostream>
using namespace std;
#include "GerenciadorDePessoal.h"

class Menu
{
private:
    GerenciadorDePessoal gerenciadorDePessoal;

public:
    Menu();
    ~Menu();
    void menuPessoal();
};
