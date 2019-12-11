#include "ColchaoDAOcsv.h"
#include <iostream>
ColchaoDAOcsv::ColchaoDAOcsv() {

}
ColchaoDAOcsv::~ColchaoDAOcsv() {
    fechar();
}

/*Métodos privados*/

string ColchaoDAOcsv::ler(const char* nome){

    if (abrir(nome, ios::in)) {
        string strArquivo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
        fechar();
        return strArquivo;
    }

    return nullptr;
}

bool ColchaoDAOcsv::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);

    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

MColchao*  ColchaoDAOcsv::getColchao(string linha) {
    
    int id = stoi(copiar(&linha, ';'));
    string nomeColchao = copiar(&linha, ';');
    string fabricante = copiar(&linha, ';');
    string cor = copiar(&linha, ';');
    float largura = stof(copiar(&linha, ';'));
    float altura = stof(copiar(&linha, ';'));
    float profundidade = stof(copiar(&linha, ';'));
    float custo =  stof(copiar(&linha, ';'));
    float preco =  stof(copiar(&linha, ';'));  
    bool vendida = (copiar(&linha, ';').front() == '1')? 1 : 0;
    string tamanho =  copiar(&linha, ';');

    MColchao* Colchao = new MColchao(id, nomeColchao, fabricante, cor, largura, altura, profundidade, custo, preco, tamanho);

    return Colchao;
 }

string  ColchaoDAOcsv::copiar(string *s, char parada)  {
    string destino;
    int i;
    for(i = 0; (*s)[i] != parada; i++){
        destino.push_back((*s)[i]);
    }
    s->erase(0, i+1);
    return destino;
}

bool  ColchaoDAOcsv::gravar(const char* nome, string s) {
    
    if(abrir(nome, ios::app)){
        arquivo <<s;
        fechar();
        return true;
    }

    return false;
}
/*Métodos publicos*/

bool ColchaoDAOcsv::gravar(const char* nome, MColchao* colchao) {

    string s = to_string(colchao->getId()) + ";" 
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

list<MColchao*> ColchaoDAOcsv::getListaColchoes(const char* nome) {
    string arquivo = ler(nome);
    list<MColchao*> lista;
    while(!arquivo.empty()) {
        string linha = copiar(&arquivo, '\n');
        lista.push_back(getColchao(linha));
    }

    return lista;
}

void ColchaoDAOcsv::fechar(){
    arquivo.close();
}