#include "GerenciadorDePessoal.h"

int GerenciadorDePessoal::id = 0;

GerenciadorDePessoal::GerenciadorDePessoal()
{

}

GerenciadorDePessoal::~GerenciadorDePessoal()
{

}

void GerenciadorDePessoal::cadastrarFuncionario()
{
    id++;
    char nome[300];

    cout << "\n\tDados do funcionário:\n\tNome completo: ";
    cin >> nome;

    Funcionario* funcionario = new Funcionario(id, nome);
    //printf ("\noi\n");
    listaFuncionarios.adicionarFuncionario(funcionario);
}

void GerenciadorDePessoal::desligarFuncionario()
{
    int id;

    cout << "\n\tId: ";
    cin >> id;

    listaFuncionarios.removerFuncionario(id);
}

void GerenciadorDePessoal::pesquisarFuncionario()
{
    int id;

    cout << "\n\tId: ";
    cin >> id;

    Funcionario* funcionario = listaFuncionarios.pesquisarFuncionario(id);

    if (funcionario != NULL){
        cout << "\tColaborador " << funcionario->getNome()
             << " encontrado." << endl;
    }
}

void GerenciadorDePessoal::listarFuncionarios()
{
    listaFuncionarios.listarFuncionarios();
}
