#include "Endereco.h"

Endereco::Endereco()
{
    strcpy(this->cep, "");
    strcpy(this->rua, "");
    this->numero = 0;
    strcpy(this->bairro, "");
    strcpy(this->cidade, "");
    strcpy(this->estado, "");
    strcpy(this->pais, "");
    strcpy(this->complemento, "");
}

Endereco::Endereco(char* cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento)
{
    strcpy(this->cep, cep);
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

const char* Endereco::getCep()
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
