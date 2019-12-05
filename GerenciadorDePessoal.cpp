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
    // Prints serão só na View
    cout << endl << "\tDados do funcionário:\n\tNome completo: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);

    // Isso é no Controller
    // Criar o objeto e tratar os dados
    Funcionario* funcionario = new Funcionario(nome);

    // Lista tem que estar no Model
    // Manda o objeto pronto para ser armazenado
    // "Funcionario", nesse caso, funcionando só como "molde"
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
