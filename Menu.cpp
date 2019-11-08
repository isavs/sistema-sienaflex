#include "Menu.h"

Menu::Menu()
{
    menuPessoal();
}

Menu::~Menu()
{

}

void Menu::menuPessoal()
{
    int caso = -1;
    while (caso != 5){
        cout << "\n\t1 - Cadastrar funcionário" << endl
             << "\t2 - Pesquisar funcionário" << endl
             << "\t3 - Lista de funcionários" << endl
             << "\t4 - Desligar funcionário" << endl
             << "\t5 - Sair\n\t>> ";
        cin >> caso;

        switch(caso)
        {
            case 1:
            {
                gerenciadorDePessoal.cadastrarFuncionario();
                // ! problemas com espaço entre nome e sobrenome, pesqusar.
                break;
            }
            case 2:
            {
                gerenciadorDePessoal.pesquisarFuncionario();
                break;
            }
            case 3:
            {
                gerenciadorDePessoal.listarFuncionarios();
                break;
            }
            case 4:
            {
                gerenciadorDePessoal.desligarFuncionario();
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                cout << "\n\t!OPÇÃO INVÁLIDA\n" << endl;
                getchar();
            }
        }
    }
}