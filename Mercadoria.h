#pragma once
#include <string>
#include <vector>
using namespace std;

class Mercadoria {
protected:
    int id;
    string nome,
        fabricante,
        cor,
        marca;
    float custo,
        preco;
    bool vendida;

public:
    Mercadoria();
    Mercadoria(vector<string> atributos);
    Mercadoria(int id, const char *nome,const char *fabricante,const char *cor,const char* marca, float custo, float preco,bool vendida);
    ~Mercadoria();

    int getId(){return id;}
    string getNome(){return nome;}
    string getFabricante(){return fabricante;}
    string getCor(){return cor;}
    string getMarca(){return marca;}
    float getCusto(){return custo;}
    float getPreco(){return preco;}
    bool getStatus(){return vendida;}

    void setId(int id);
    void setNome(const char *nome);
    void setFabricante(const char *fabricante);
    void setCor(const char *cor);
    void setMarca(const char *marca);
    void setCusto(float custo);
    void setPreco(float preco);
    void setStatus(bool vendida);

    void cadastrarColchao(const char* nome){}
};
