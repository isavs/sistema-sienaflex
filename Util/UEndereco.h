#pragma once
#include <string>
using namespace std;

class UEndereco
{
private:
    string cep;
    string rua;
    string numero;
    string bairro;
    string cidade;
    string estado;
    string pais;
    string complemento;

public:
    UEndereco();
    //UEndereco(char* cep, char* rua, int numero, char* bairro, char* cidade, char* estado, char* pais, char* complemento);
    ~UEndereco();
    void setCep(string cep);
    void setRua(string rua);
    void setNumero(string numero);
    void setBairro(string bairro);
    void setCidade(string cidade);
    void setEstado(string estado);
    void setPais(string pais);
    void setComplemento(string complemento);
    const string getCep();
    const string getRua();
    const string getNumero();
    const string getBairro();
    const string getCidade();
    const string getEstado();
    const string getPais();
};
