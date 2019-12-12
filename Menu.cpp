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
    system("clear");
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
                gerarRelatorios();
                break;
            }
            case 4:
            {
                 vMercadoria->salvar();
                 vFuncionario->salvar();
                break;
            }
            default:
            {
                cout << "\n\t!OPÇÃO INVÁLIDA\n" << endl;
                //__fpurge(stdin);
                fflush(stdin);
                getchar();
            }
        }
    }
}

void Menu::gerarRelatorios()
{
    URelatorio relatorio;
    int caso = -1;
    while (caso != 4){
        cout << "\nGerar fluxo de caixa\t|\t2 - Gerar relatorio de pagamentos\n3 - Sair\n>> ";
        cin >> caso;
        cout << endl;
        switch(caso)
        {
            case 1:
            {
                int ano;
                cout << "Ano: ";
                cin >> ano;
                cout << endl;
                if (!relatorio.gerarFluxoDeCaixa(ano))
                    cout << "!!! Relatorio nao gerado !!!"<< endl;
                else
                     cout << "Fluxo de caixa gerado com sucesso." << endl;
                break;
            }
            case 2:
            {
                if (!relatorio.gerarFluxoDePagamentos())
                    cout << "!!! Relatorio nao gerado !!!"<< endl;
                else
                    cout << "Fluxo de pagamentos gerado com sucesso." << endl;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
