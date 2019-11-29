#include "Arquivo.h"
#include <string>
#include <iostream>
#include<istream>
#include <cstring>
Arquivo::Arquivo() {

}
Arquivo::~Arquivo() {
    arquivo.close();
}

void Arquivo::abrirArquivo(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo | ios::binary);

    if(!arquivo.is_open() || !arquivo.good()) {
        //Mensagem de ERRO
        cout << "ERRO AO ABRIR O ARQUIVO";
        exit(0);
    }
}
void Arquivo::gravarNoArquivo(const char* nome, const char* s) {
    
    if(strstr(nome, ".txt")){
        printf("txt!!");
        abrirArquivo(nome, ios::app);
    }
    else if (strstr(nome, ".ate")){
        printf("ate!!");
        abrirArquivo(nome, ios::binary);
    }
    arquivo << s << endl;
    fecharArquivo();
}
string Arquivo::getArquivo(const char* nome){
    abrirArquivo(nome, ios::in);
    string strArquivo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
    fecharArquivo();
    return strArquivo;
}
vector<string> Arquivo::getLinha(string* str) {
    int pos = str->find_first_of('\n', 0);
    char aux[pos+1];
    
    vector<string> dados;
    
    str->copy(aux, pos);
    str->erase(0, pos+1);
    
    aux[pos] = '\0';
    string linha = aux;
    pos = linha.find_first_of(';', 0);

    while(!linha.empty()) {
        linha.copy(aux, pos);
        linha.erase(0, pos+1);
        aux[pos] = '\0';
        dados.push_back(aux);
        pos = linha.find_first_of(';', 0);
        if(pos < 0) {
            linha.clear();
        }
    }

    return dados;
}
vector<vector<string>> Arquivo::getDados(const char* nome) {
    string arquivo = getArquivo(nome);
    int i = 1;

    while(!arquivo.empty()) {
        listaDeDados.push_back(getLinha(&arquivo));
        i++;
    }

    return listaDeDados;

}

void Arquivo::fecharArquivo(){
    arquivo.close();
}