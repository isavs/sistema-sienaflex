#include "UEndereco.h"

UEndereco::UEndereco()
{

}

UEndereco::UEndereco(char* cep, char* rua, char* numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento)
{
    this->cep = cep;
    this->rua = rua;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->pais = pais;
    this->complemento = complemento;
}

UEndereco::~UEndereco()
{

}

void UEndereco::setCep(string cep)
{
    this->cep = cep;
}

void UEndereco::setRua(string rua)
{
    this->rua = rua;
}

void UEndereco::setNumero(string numero)
{
    this->numero = numero;
}

void UEndereco::setBairro(string bairro)
{
    this->bairro = bairro;
}

void UEndereco::setCidade(string cidade)
{
    this->cidade = cidade;
}

void UEndereco::setEstado(string estado)
{
    this->estado = estado;
}

void UEndereco::setPais(string pais)
{
    this->pais = pais;
}

void UEndereco::setComplemento(string complemento)
{
    this->complemento = complemento;
}

const string UEndereco::getCep()
{
    return cep;
}

const string UEndereco::getRua()
{
    return rua;
}

const string UEndereco::getNumero()
{
    return numero;
}

const string UEndereco::getBairro()
{
    return bairro;
}

const string UEndereco::getCidade()
{
    return cidade;
}

const string UEndereco::getEstado()
{
    return estado;
}

const string UEndereco::getPais()
{
    return pais;
}
<<<<<<< HEAD
const string UEndereco::getComplemento()
{
    return complemento;
}
=======

const string UEndereco::getComplemento()
{
    return complemento;
}
>>>>>>> 9fad704ff0564f2fad55a29f8dfb7921e92e8f68
