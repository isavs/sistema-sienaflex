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
    
    cout << endl << "\tDados do funcionário:"<< endl <<"\tNome completo: ";
    //__fpurge(stdin);
    fflush(stdin);
    fgets(nome, 300, stdin);
    Funcionario* funcionario = new Funcionario(id, nome);
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
    } else {
        cout << "\n\tErro: funcionário não encontrado." << endl;
    }
}

void GerenciadorDePessoal::listarFuncionarios()
{
    listaFuncionarios.listarFuncionarios();
}
