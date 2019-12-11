#include "MMercadoria.h"
#include <time.h>
MMercadoria::MMercadoria()
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);
    id = 0;
    nome = "";
    fabricante = "";
    cor = "";
    custo = 0.0;
    preco = 0.0;
    vendida = false;
    saida.setData(0,0,0);
    entrada.setData(tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
}


MMercadoria::MMercadoria(int id, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco)
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);

    this->id = id;
    this->nome = nome;
    this->fabricante = fabricante;
    this->cor = cor;
    this->largura = largura;
    this->altura = altura;
    this->profundidade = profundidade;
    this->custo = custo;
    this->preco = preco;
    this->vendida = false;

    entrada.setData(tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
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

void MMercadoria::setMedidas(float largura, float altura, float profundidade)
{
    this->largura = largura;
    this->altura = altura;
    this->profundidade = profundidade;
}

void MMercadoria::setLargura(float largura)
{
    this->largura = largura;
}

void MMercadoria::setAltura(float altura)
{
    this->altura = altura;
}

void MMercadoria::setProfundidade(float profundidade)
{
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

const float MMercadoria::getCusto()
{
    return custo;
}
const bool MMercadoria::getStatus()
{
    return vendida;
}

const float MMercadoria::getPreco()
{
    return preco;
}

void  MMercadoria::setDataEntrada(int d, int m, int a)
{
    entrada.setData(d,m, a);
}
void  MMercadoria::setDataSaida(int d, int m, int a)
{
    saida.setData(d,m, a);
}
UData  MMercadoria::getDataEntrada()
{
    return entrada;
}
UData  MMercadoria::getDataSaida()
{
    return saida;
}