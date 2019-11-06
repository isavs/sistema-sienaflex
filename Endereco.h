#pragma once
#include <string.h>

class Endereco
{
private:
    long int cep;
    char* rua;
    int numero;
    char* bairro;
    char* cidade;
    char* estado;
    char* pais;
    char* complemento;

public:
    Endereco();
    Endereco(long int cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento);
    ~Endereco();
    const char* getRua();
    const char* getBairro();
    const char* getCidade();
    const char* getEstado();
    const char* getPais();
    const int getNumero();
    const long int getCep();
};