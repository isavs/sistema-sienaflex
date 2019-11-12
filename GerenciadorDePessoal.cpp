#include "GerenciadorDePessoal.h"

GerenciadorDePessoal* GerenciadorDePessoal::gerenciadorDePessoal = 0;

GerenciadorDePessoal::GerenciadorDePessoal()
{

}

GerenciadorDePessoal::~GerenciadorDePessoal()
{
    delete gerenciadorDePessoal;
}

GerenciadorDePessoal* GerenciadorDePessoal::getGerenciadorDePessoal()
{
    if (gerenciadorDePessoal == 0){
        gerenciadorDePessoal = new GerenciadorDePessoal();
    }
    return gerenciadorDePessoal;
}

void GerenciadorDePessoal::cadastrarFuncionario()
{
    string nome;

    cout << endl << "\tDados do funcionário:\n\tNome completo: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);

    Funcionario* funcionario = new Funcionario(nome);
    listaFuncionarios.adicionarFuncionario(funcionario);
}

void GerenciadorDePessoal::desligarFuncionario()
{
    string nome;
    int id;

    cout << "\n\tNome completo: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "\tId: ";
    cin >> id;

    listaFuncionarios.removerFuncionario(nome, id);
}

void GerenciadorDePessoal::pesquisarFuncionario()
{
    string nome;

    cout << "\n\tNome: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);

    listaFuncionarios.pesquisarFuncionario(nome);
}

void GerenciadorDePessoal::listarFuncionarios()
{
    listaFuncionarios.listarFuncionarios();
}
