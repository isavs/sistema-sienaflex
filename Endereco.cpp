#include "Endereco.h"

Endereco::Endereco()
{
    cep = 0;
    rua = NULL;
    numero = 0;
    bairro = NULL;
    cidade = NULL;
    estado = NULL;
    pais = NULL;
}

Endereco::Endereco(long int cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento)
{
    this->cep = cep;
    strcpy(this->rua, rua);
    this->numero = numero;
    strcpy(this->bairro, bairro);
    strcpy(this->cidade, cidade);
    strcpy(this->estado, estado);
    strcpy(this->pais, pais);
    strcpy(this->complemento, complemento);
}

Endereco::~Endereco()
{

}

const long int Endereco::getCep()
{
    return cep;
}

const char* Endereco::getRua()
{
    return rua;
}

const int Endereco::getNumero()
{
    return numero;
}

const char* Endereco::getBairro()
{
    return bairro;
}

const char* Endereco::getCidade()
{
    return cidade;
}

const char* Endereco::getEstado()
{
    return estado;
}

const char* Endereco::getPais()
{
    return pais;
}