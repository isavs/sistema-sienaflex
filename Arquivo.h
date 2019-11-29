#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Arquivo {
private:
    vector<vector<string>> listaDeDados;
    fstream arquivo;
private:
    string getArquivo(const char* nome);
    vector<string> getLinha(string* str);
public:
    Arquivo();
    ~Arquivo();

    void abrirArquivo(const char* s, std::ios_base::openmode modo);
    void gravarNoArquivo(const char* nome, const char* s);
    void fecharArquivo();
    string lerArquivo(const char* nome);
    vector<vector<string>> getDados(const char* nome);



};

