#pragma once
#include <iostream>
using namespace std;
#include "Membros.h"
#include "Funcionario.h"

class Testes
{
private:
    Membros listaFuncionarios;
public:
    Testes();
    ~Testes();

    void Executar();
    void cadastrarFuncionario();
};