#pragma once
#include "../Util/UEndereco.h"
#include <string>
using namespace std;

class MPessoa
{
protected:
    string nome;
    string cpf;
    string telefone;
    UEndereco endereco;

public:
    MPessoa();
    MPessoa(string nome);
    MPessoa(string nome, string cpf, string telefone, UEndereco endereco);
    MPessoa(char* nome, char* cpf, char* telefone, UEndereco endereco);
    ~MPessoa();
    void setNome(string nome);
    void setCpf(string cpf);
    void setTelefone(string telefone);
    const string getNome();
    const string getCpf();
    const string getTelefone();
    UEndereco getEndereco();
};
