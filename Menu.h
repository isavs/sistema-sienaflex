#pragma once
#include <iostream>
using namespace std;
#include "./View/VMercadoria.h"
#include "./View/VFuncionario.h"

class Menu
{
private:
    VMercadoria* vMercadoria;
    VFuncionario* vFuncionario;

public:
    Menu();
    ~Menu();
    void menu();
};
