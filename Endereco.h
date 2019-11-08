#pragma once
#include <string.h>

class Endereco
{
private:
    char cep[300];
    char rua[300];
    int numero;
    char bairro[300];
    char cidade[300];
    char estado[300];
    char pais[300];
    char complemento[300];

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
