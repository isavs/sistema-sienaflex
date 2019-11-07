#include "Testes.h"

Testes::Testes()
{
    Executar();
}

Testes::~Testes()
{

}

void Testes::Executar()
{
    cadastrarFuncionario();
    listaFuncionarios.listarFuncionarios();
}

void Testes::cadastrarFuncionario()
{
    int id;
    char nome[150];

    cout << "\n\tDados do funcionário:\n\tNome: ";
    cin >> nome;

    cout << "\tId (para fim de TESTES gente dps deixamos automatico: ";
    cin >> id;
    Funcionario* funcionario = new Funcionario(id, nome);
    //printf ("\noi\n");
    listaFuncionarios.adicionarFuncionario(funcionario);
}