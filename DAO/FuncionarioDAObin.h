#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "FuncionarioDAO.h"
#include "../Model/MFuncionario.h"
using namespace std;

class FuncionarioDAObin : public FuncionarioDAO {
private:
    fstream arquivo;
    struct sFuncionario {
        char numero[30],
            cep[300],
            rua[300],
            bairro[300],
            cidade[300],
            estado[300],
            pais[300],
            complemento[300],
            nome[30],
            cpf[30],
            telefone[30],
            cargo[40];
        int id;
        float salario;
 
    }; 

private:
    bool gravar(sFuncionario Funcionario, const char* nome);

public:
    FuncionarioDAObin();
    ~FuncionarioDAObin();
    bool abrir(const char* nome, std::ios_base::openmode modo);
    bool gravar(const char* nome, MFuncionario* Funcionario);
    list<MFuncionario*> getListaFuncionarios(const char* nome);
    void fechar();

};

