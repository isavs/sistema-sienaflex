#include "Mercadoria.h"
#include<string.h>
#include<iostream>
using namespace std;

Mercadoria::Mercadoria()
{
    id = 0;
    nome = fabricante = cor = marca = nullptr;
    custo = preco = 0.0;
    vendida = false;
}
Mercadoria::Mercadoria(vector<string> atributos) {
    setStatus(*atributos.end() == "1");
    atributos.pop_back();
    setPreco(stof(*atributos.end()));
    atributos.pop_back();
}
Mercadoria::Mercadoria(int id, const char *nome,const char *fabricante,const char *cor,const char* marca, float custo, float preco,bool vendida)
{
    this->id = id;
    this->nome = nome;
    this->fabricante = fabricante;
    this->cor = cor;
    this->marca = marca;
    this->custo = custo;
    this->preco = preco;
    this->vendida = vendida;
}
Mercadoria::~Mercadoria()
{
    id = 0;
    nome = fabricante = cor = marca = nullptr;
    custo = preco = 0.0;
    vendida = false;
}
void Mercadoria::setId(int id) {
    this->id = id;
}
void Mercadoria::setNome(const char *nome) {
    this->nome = nome;
}
void Mercadoria::setFabricante(const char *fabricante) {
    this->fabricante = fabricante;
}
void Mercadoria::setCor(const char *cor) {
    this->cor = cor;
}
void Mercadoria::setMarca(const char *marca) {
    this->marca = marca;
}
void Mercadoria::setCusto(float custo) {
    this->custo = custo;
}
void Mercadoria::setPreco(float preco) {
    this->preco = preco;
}
void Mercadoria::setStatus(bool vendida) {
    this->vendida = vendida;
}