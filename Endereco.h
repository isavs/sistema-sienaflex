#pragma once
#include <string.h>

class Endereco
{
private:
    char* cep;
    char* rua;
    int numero;
    char* bairro;
    char* cidade;
    char* estado;
    char* pais;
    char* complemento;

public:
    Endereco();
    Endereco(char* cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento);
    ~Endereco();
    const char* getCep();
    const char* getRua();
    const int getNumero();
    const char* getBairro();
    const char* getCidade();
    const char* getEstado();
    const char* getPais();
};