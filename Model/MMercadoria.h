#pragma once
#include <string>
using namespace std;

class MMercadoria {
protected:
    int id;
    string nome;
    string fabricante;
    string cor;
    float largura;
    float altura;
    float profundidade;
    float custo;
    float preco;
    bool vendida;

public:
    MMercadoria();
    MMercadoria(int id, const char *nome,const char *fabricante,const char *cor,const char* marca, float custo, float preco,bool vendida);
    ~MMercadoria();
    void setId(int id);
    void setNome(string nome);
    void setFabricante(string fabricante);
    void setCor(string cor);
    void setMedidas(float largura, float altura, float profundida);
    void setCusto(float custo);
    void setPreco(float preco);
    void setStatus(bool vendida);
    const int getId();
    const string getNome();
    const string getFabricante();
    const string getCor();
    const float getLargura();
    const float getAltura();
    const float getProfundidade();
    //const float getCusto();
    const float getPreco();
};
