#pragma once
#include <list>
#include "../Model/MFuncionarios.h"
#include "../Model/MFuncionario.h"

class CFuncionarios
{
private:
    static int ids;

private:
    CFuncionarios();
    ~CFuncionarios();

public:
    static CFuncionarios &getCFuncionarios();
    CFuncionarios(const CFuncionarios&) = delete;
    void operator = (const CFuncionarios&) = delete;

    bool adicionar(string nome, string cpf, string telefone, UEndereco endereco, string cargo, double salarioHora);
    void atualizar(MFuncionario* funcionario, string nome, string cpf, string telefone, UEndereco endereco, string cargo, double salarioHora);
    bool remover(const string nome, const int id);
    MFuncionario* pesquisar(const int id, const string cpf);
    list<MFuncionario*> pesquisarNomes(const string nome);
    list<MFuncionario*> listar();

    void salvarFuncionarios();
};
