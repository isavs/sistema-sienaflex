#pragma once
#include <string>
#include "../Util/UData.h"
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
    UData entrada;
    UData saida;

public:
    MMercadoria();
    MMercadoria(int id, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco);
    ~MMercadoria();
    void setId(int id);
    void setNome(string nome);
    void setFabricante(string fabricante);
    void setCor(string cor);
    void setMedidas(float largura, float altura, float profundidade);
    void setLargura(float largura);
    void setAltura(float altura);
    void setProfundidade(float profundidade);
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
    const float getCusto();
    const float getPreco();
    const bool getStatus();
    const MMercadoria* getDados();
    void setDataEntrada(int d, int m, int a);
    void setDataSaida(int d, int m, int a);
    UData getDataEntrada();
    UData getDataSaida();
};
