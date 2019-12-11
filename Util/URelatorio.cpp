#include "URelatorio.h"

URelatorio::URelatorio()
{

}

URelatorio::~URelatorio()
{

}

void URelatorio::gerarFluxoDeCaixa()
{
    UData data, saida;
    string s;

    auto itC = colchoes.getListaColchoes("BDColchoes.csv").begin();
    auto itE = estofados.getListaEstofados("BDEstofados.csv").begin();
    auto itF = funcionarios.getListaFuncionarios("BDFuncionarios.csv").begin();

    while ((entrada.getDia() <= (*itC)->getDataEntrada().getDia()
        && entrada.getMes() <= (*itC)->getDataEntrada().getMes()
        && entrada.getAno() <= (*itC)->getDataEntrada().getAno()) ||
        (entrada.getDia() <= (*itE)->getDataEntrada().getDia()
        && entrada.getMes() <= (*itE)->getDataEntrada().getMes()
        && entrada.getAno() <= (*itE)->getDataEntrada().getAno()) ||
        (entrada.getDia() <= (*itF)->getDataEntrada().getDia()
        && entrada.getMes() <= (*itF)->getDataEntrada().getMes()
        && entrada.getAno() <= (*itF)->getDataEntrada().getAno())){
        while (itC = colchoes.getListaColchoes("BDColchoes.csv").end())
    }
    while (it != colchoes.getListaColchoes("BDColchoes.csv").end()){
        data((*it)->getDataEntrada().getDia(), (*it)->getDataEntrada().getMes(), (*it)->getDataEntrada().getAno());
        do {
            compras += (*it)->getCusto();
            if ((*it)->getDataSaida().getDia() == data.getDia() &&
                (*it)->getDataSaida().getMes() == data.getMes() &&
                (*it)->getDataSaida().getAno() == data.getAno()){
                vendas += (*it)->getPreco();
            }
            it++;
        } while ((*it)->getDataEntrada().getDia() == data.getDia())
    }

    for (  it++){
        data = (*it)
        if ()

        for (){

        }
    }

    s = s + to_string(mercadoria->getDataEntrada().getDia()) + '/'
        + to_string(mercadoria->getDataEntrada().getMes()) + '/'
        + to_string(mercadoria->getDataEntrada().getAno()) + '/' + ";"
        + to_string(mercadoria->getDataSaida().getDia()) + '/'
        + to_string(mercadoria->getDataSaida().getMes()) + '/'
        + to_string(mercadoria->getDataSaida().getAno()) + '/' + ";"
    string



    string s = to_string(colchoa->getId()) + ";"
    + colchao->getNome() + ";"
    + colchao->getFabricante() + ";"
    + colchao->getCor() + ";"
    + to_string(colchao->getLargura()) + ";"
    + to_string(colchao->getAltura()) + ";"
    + to_string(colchao->getProfundidade()) + ";"
    + to_string(colchao->getCusto()) + ";"
    + to_string(colchao->getPreco()) + ";"
    + to_string(colchao->getStatus()) + ";"
    + colchao->getTamanho()+ ";\n";

    return gravar(nome, s);


}

void URelatorio::gerarFluxoDePagamentos()
{

}
