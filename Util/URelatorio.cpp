#include "URelatorio.h"

URelatorio::URelatorio()
{

}

URelatorio::~URelatorio()
{

}
string URelatorio::gerarFluxoDeCaixaMensal(int mes, int ano)
{
    double compras = 0;
    double vendas = 0; 
    string s = to_string(mes) + '/' + to_string (ano) + ';';
    list<MColchao*> clist = colchoes.getListaColchoes("BDColchoes.csv");
    for (auto it = clist.begin(); it != clist.end(); it++){
        if(mes == (*it)->getDataEntrada().getMes()
        && ano == (*it)->getDataEntrada().getAno()){
            compras += (*it)->getCusto();
        }
    }
    list<MEstofado*> elist = estofados.getListaEstofados("BDEstofados.csv");
    for (auto it = elist.begin(); it != elist.end(); it++){
        if(mes == (*it)->getDataEntrada().getMes()
        && ano == (*it)->getDataEntrada().getAno()){
            compras += (*it)->getCusto();
        }
    }
    clist.clear();
    clist = colchoes.getListaColchoes("BDColchaoVendido.csv");
    for (auto it = clist.begin(); it != clist.end(); it++){
        if(mes == (*it)->getDataSaida().getMes()
        && ano == (*it)->getDataSaida().getAno()){
            vendas += (*it)->getPreco();
        }
    }
    elist.clear();
    elist = estofados.getListaEstofados("BDEstofadoVendidos.csv");
    for (auto it = elist.begin(); it != elist.end(); it++){
        if(mes == (*it)->getDataSaida().getMes()
        && ano == (*it)->getDataSaida().getAno()){
            vendas += (*it)->getPreco();
        }
    }
    s = s + to_string(compras) + ';' + to_string(vendas) +';' + to_string(vendas-compras) + ";\n";
    return s;
}
bool URelatorio::gerarFluxoDeCaixa(int ano)
{
    string nome = "FluxoDeCaixa" + to_string(ano) + ".csv";
    remove(&nome[0]);
    arquivo.open(&nome[0], ios::app);

    if (!arquivo.is_open() || !arquivo.good()) {
        return false;
    }
    string s = "Data;Despesas;Vendas;Fluxo;\n";
    for (int i = 1; i < 13; i++) {
        s = s + gerarFluxoDeCaixaMensal(i, ano);
    }
    cout << "A string FC: " << s;
    arquivo << s;
    arquivo.close();
    return true;
}

bool URelatorio::gerarFluxoDePagamentos()
{
    remove("FluxoDePagamentos.csv");
    arquivo.open("FluxoDePagamentos.csv", ios::app);

    if (!arquivo.is_open() || !arquivo.good()) {
        return false;
    }

    string s = "";
    double pagamentos = 0;

    s += "Funcionario;CPF;Salario;Total;\n";
    list<MFuncionario*>flist = funcionarios.getListaFuncionarios("BDFuncionarios.csv");
    for (auto it = flist.begin(); it != flist.end(); it++){
        s += (*it)->getNome() + ";"
        + (*it)->getCpf() + ";"
        + to_string((*it)->getSalario()) + ";\n";
        pagamentos += pagamentos;
    }

    s += ";;;" + to_string(pagamentos) + ";\n";

    arquivo << s;
    arquivo.close();
}
