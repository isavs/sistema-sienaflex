#include "EstofadoDAOcsv.h"
#include <iostream>
EstofadoDAOcsv::EstofadoDAOcsv() {

}
EstofadoDAOcsv::~EstofadoDAOcsv() {
    fechar();
}

/*Métodos privados*/

string EstofadoDAOcsv::ler(const char* nome){

    if (abrir(nome, ios::in)) {
        string strArquivo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
        fechar();
        return strArquivo;
    }

    return nullptr;
}

bool EstofadoDAOcsv::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);

    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

MEstofado*  EstofadoDAOcsv::getEstofado(string linha) {
    
    int id = stoi(copiar(&linha, ';'));
    const char* nomeEstofado = (copiar(&linha, ';')).c_str();
    const char* fabricante = (copiar(&linha, ';')).c_str();
    const char* cor = (copiar(&linha, ';')).c_str();
    float largura = stof(copiar(&linha, ';'));
    float altura = stof(copiar(&linha, ';'));
    float profundidade = stof(copiar(&linha, ';'));
    float custo =  stof(copiar(&linha, ';'));
    float preco =  stof(copiar(&linha, ';'));  
    bool vendida = (copiar(&linha, ';').front() == '1')? 1 : 0;
    int lugares =  stoi(copiar(&linha, ';'));

    MEstofado* Estofado = new MEstofado(id, nomeEstofado, fabricante, cor, largura, altura, profundidade, custo, preco, lugares);

    return Estofado;
 }

string  EstofadoDAOcsv::copiar(string *s, char parada)  {
    string destino;
    int i;
    for(i = 0; (*s)[i] != parada; i++){
        destino.push_back((*s)[i]);
    }
    s->erase(0, i+1);
    return destino;
}

bool  EstofadoDAOcsv::gravar(const char* nome, string s) {
    
    if(abrir(nome, ios::app)){
        arquivo <<s;
        fechar();
        return true;
    }

    return false;
}
/*Métodos publicos*/

bool EstofadoDAOcsv::gravar(const char* nome, MEstofado* Estofado) {

    string s = to_string(Estofado->getId()) + ";" 
    + Estofado->getNome() + ";" 
    + Estofado->getFabricante() + ";" 
    + Estofado->getCor() + ";" 
    + to_string(Estofado->getLargura()) + ";" 
    + to_string(Estofado->getAltura()) + ";" 
    + to_string(Estofado->getProfundidade()) + ";" 
    + to_string(Estofado->getCusto()) + ";" 
    + to_string(Estofado->getPreco()) + ";" 
    + to_string(Estofado->getStatus()) + ";"
    + to_string(Estofado->getLugares()) + ";\n";

    return gravar(nome, s);
}

list<MEstofado*> EstofadoDAOcsv::getListaEstofados(const char* nome) {
    string arquivo = ler(nome);
    list<MEstofado*> lista;
    while(!arquivo.empty()) {
        string linha = copiar(&arquivo, '\n');
        lista.push_back(getEstofado(linha));
    }

    return lista;
}

void EstofadoDAOcsv::fechar(){
    arquivo.close();
}