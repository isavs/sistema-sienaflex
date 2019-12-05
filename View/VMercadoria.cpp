#include "VMercadoria.h"

VMercadoria::VMercadoria()
{

}

VMercadoria::~VMercadoria()
{

}

void VMercadoria::adicionar()
{
    string nome = "";
    string fabricante = "";
    string cor = "";
    float largura = 0.0;
    float altura = 0.0;
    float profundidade = 0.0;
    float custo = 0.0;
    float preco = 0.0;
    string descricao = "";

    int opcao = -1;
    while (opcao != 6){
        cout << "1 - Colchao\n2 - Base\n3 - Sofa\n4 - Poltrona\n5 - Puff\n6 - Voltar\n>>";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
        {

            break;
        }

        default:
            break;
        }
    }
}

void VMercadoria::atualizar()
{

}

void VMercadoria::pesquisar()
{

}

void remover()
{

}

void listar()
{

}
