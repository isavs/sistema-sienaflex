#include "MercadoriaDAOtxt.h"
#include <iostream>
MercadoriaDAOtxt::MercadoriaDAOtxt() {

}
MercadoriaDAOtxt::~MercadoriaDAOtxt() {
    fechar();
}

/*Métodos privados*/

string MercadoriaDAOtxt::ler(const char* nome){

    if (abrir(nome, ios::in)) {
        string strArquivo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
        fechar();
        return strArquivo;
    }

    return nullptr;
}

bool MercadoriaDAOtxt::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);

    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

Mercadoria*  MercadoriaDAOtxt::getMercadoria(string linha) {
    
    int id = stoi(copiar(&linha, ';'));
    const char* nomeMercadoria = (copiar(&linha, ';')).c_str();
    const char* fabricante = (copiar(&linha, ';')).c_str();
    const char* cor = (copiar(&linha, ';')).c_str();
    const char* marca = (copiar(&linha, ';')).c_str();
    float custo =  stof(copiar(&linha, ';'));
    float preco =  stof(copiar(&linha, ';'));  
    bool vendida = (copiar(&linha, ';').front() == '1')? 1 : 0;

    Mercadoria* mercadoria = new Mercadoria(id, nomeMercadoria, fabricante, cor, marca, custo, preco, vendida);

    return mercadoria;
 }

string  MercadoriaDAOtxt::copiar(string *s, char parada)  {
    string destino;
    int i;
    for(i = 0; (*s)[i] != parada; i++){
        destino.push_back((*s)[i]);
    }
    s->erase(0, i+1);
    return destino;
}

bool  MercadoriaDAOtxt::gravar(const char* nome, string s) {
    
    if(abrir(nome, ios::app)){
        arquivo <<s;
        fechar();
        return true;
    }

    return false;
}
/*Métodos publicos*/

bool MercadoriaDAOtxt::gravar(const char* nome, Mercadoria* mercadoria) {

    string s = to_string(mercadoria->getId()) + ";" 
    + mercadoria->getNome() + ";" 
    + mercadoria->getFabricante() + ";" 
    + mercadoria->getCor() + ";" 
    + mercadoria->getMarca() + ";" 
    + to_string(mercadoria->getCusto()) + ";" 
    + to_string(mercadoria->getPreco()) + ";" 
    + to_string(mercadoria->getStatus()) + ";\n";

    return gravar(nome, s);
}

list<Mercadoria*> MercadoriaDAOtxt::getListaMercadorias(const char* nome) {
    string arquivo = ler(nome);
    list<Mercadoria*> lista;
    while(!arquivo.empty()) {
        string linha = copiar(&arquivo, '\n');
        lista.push_back(getMercadoria(linha));
    }

    return lista;
}

void MercadoriaDAOtxt::fechar(){
    arquivo.close();
}