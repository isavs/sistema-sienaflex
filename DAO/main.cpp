#include "EstofadoDAObin.h"
#include "list"
#include <iostream>
using namespace std;
// g++ -o tnt EstofadoDAObin.cpp ../Model/MEstofado.cpp ../Model/MMercadoria.cpp main.cpp
int main() {
    EstofadoDAObin e;
    MEstofado * m = new MEstofado (1, "Macadamia", "Macademy", "violeta", 4.5, 2.1, 3.7, 698.98, 497.5, 3);
    e.gravar("estofados.dat", m);
    list<MEstofado*> lista = e.getListaEstofados("estofados.dat");

    for (std::list<MEstofado*>::iterator i = lista.begin(); i != lista.end(); i++) {
        cout << "NA MAIN PORRA" << endl;
        cout << "Id: " << (*i)->getId() << endl;
        cout << "Nome: " << (*i)->getNome() << endl;
        cout << "Fabricante: " << (*i)->getFabricante() << endl;
        cout << "Cor: " << (*i)->getCor() << endl;
        cout << "Altura: " << (*i)->getAltura() << endl;
        cout << "Largura: " << (*i)->getLargura() << endl;
        cout << "Profundidade: " << (*i)->getProfundidade() << endl;
        cout << "Custo: " << (*i)->getCusto() << endl;
        cout << "Preco: " << (*i)->getPreco() << endl;
        cout << "Status: " << (*i)->getStatus() << endl;
        cout << "Tamanho: " << (*i)->getLugares() << endl;
    }
      
}