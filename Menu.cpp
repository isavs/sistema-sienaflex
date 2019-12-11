#include "Menu.h"

Menu::Menu()
{
    menu();
}

Menu::~Menu()
{

}

void Menu::menu()
{
    int caso = -1;
    while (caso != 4){
        cout << "\n==================== MENU ====================" << endl;
        cout << "\n1 - Mercadorias\t|\t2 - Funcionarios\n3 - Relatorios\t|\t4 - Sair\n>> ";
        cin >> caso;

        switch(caso)
        {
            case 1:
            {
                vMercadoria->view();
                break;
            }
            case 2:
            {
                vFuncionario->view();
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
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
