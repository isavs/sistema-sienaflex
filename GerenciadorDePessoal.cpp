#include "GerenciadorDePessoal.h"

<<<<<<< HEAD
GerenciadorDePessoal* GerenciadorDePessoal::gerenciadorDePessoal = 0;
=======

int GerenciadorDePessoal::id = 0;
>>>>>>> 37473289a53946ac143c5274d3d769b5ad79a4eb

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
    char nome[300];
<<<<<<< HEAD

    cout << endl << "\tDados do funcionário:\n\tNome completo: ";
    __fpurge(stdin);
    fflush(stdin);
    fgets(nome, 300, stdin);

    Funcionario* funcionario = new Funcionario(nome);
=======
    
    cout << endl << "\tDados do funcionário:"<< endl <<"\tNome completo: ";
    //__fpurge(stdin);
    fflush(stdin);
    fgets(nome, 300, stdin);
    Funcionario* funcionario = new Funcionario(id, nome);
>>>>>>> 37473289a53946ac143c5274d3d769b5ad79a4eb
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
