#include "MMercadoria.h"

MMercadoria::MMercadoria()
{
    id = 0;
    nome = "";
    fabricante = "";
    cor = "";
    custo = 0.0;
    preco = 0.0;
    vendida = false;
}


MMercadoria::MMercadoria(int id, const char *nome,const char *fabricante,const char *cor,const char* marca, float custo, float preco,bool vendida)
{
    this->id = id;
    this->nome = nome;
    this->fabricante = fabricante;
    this->cor = cor;
    this->custo = custo;
    this->preco = preco;
    this->vendida = vendida;
}

MMercadoria::~MMercadoria()
{

}

void MMercadoria::setId(int id)
{
    this->id = id;
}

void MMercadoria::setNome(string nome)
{
    this->nome = nome;
}

void MMercadoria::setFabricante(string fabricante)
{
    this->fabricante = fabricante;
}

void MMercadoria::setCor(string cor)
{
    this->cor = cor;
}

void MMercadoria::setMedidas(float largura, float altura, float profundida)
{
    this->largura = largura;
    this->altura = altura;
    this->profundidade = profundidade;
}

void MMercadoria::setCusto(float custo)
{
    this->custo = custo;
}

void MMercadoria::setPreco(float preco)
{
    this->preco = preco;
}

void MMercadoria::setStatus(bool vendida)
{
    this->vendida = vendida;
}

const int MMercadoria::getId()
{
    return id;
}

const string MMercadoria::getNome()
{
    return nome;
}

const string MMercadoria::getFabricante()
{
    return fabricante;
}

const string MMercadoria::getCor()
{
    return cor;
}

const float MMercadoria::getLargura()
{
    return largura;
}

const float MMercadoria::getAltura()
{
    return altura;
}

const float MMercadoria::getProfundidade()
{
    return profundidade;
}

const float MMercadoria::getPreco()
{
    return preco;
}
