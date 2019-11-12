#include "GerenciadorDePessoal.h"

<<<<<<< HEAD
GerenciadorDePessoal* GerenciadorDePessoal::gerenciadorDePessoal = 0;
=======

GerenciadorDePessoal* GerenciadorDePessoal::gerenciadorDePessoal = 0;

>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d

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
<<<<<<< HEAD
    string nome;
=======
    char nome[300];
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d

    cout << endl << "\tDados do funcionário:\n\tNome completo: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);

    Funcionario* funcionario = new Funcionario(nome);
<<<<<<< HEAD
=======
    
    cout << endl << "\tDados do funcionário:"<< endl <<"\tNome completo: ";
    //__fpurge(stdin);
    fflush(stdin);
    fgets(nome, 300, stdin);
    Funcionario* funcionario = new Funcionario(nome);
>>>>>>> 81234df6b28e339c95bf6fbeeb525e10a832103d
    listaFuncionarios.adicionarFuncionario(funcionario);

    printf("id: %d", funcionario->getId());
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
