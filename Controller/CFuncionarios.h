#pragma once
#include <list>
#include "../Model/MFuncionarios.h"
#include "../Model/MFuncionario.h"

class CFuncionarios
{
private:
    static int ids;
    int id;
    MFuncionarios* funcionarios;

public:
    CFuncionarios();
    ~CFuncionarios();
    bool adicionar(string nome, string cpf, string telefone, double salario);
    bool remover(const string nome, const int id);
    list<MFuncionario*> pesquisar(const string nome);
    list<MFuncionario*> listar();
};
