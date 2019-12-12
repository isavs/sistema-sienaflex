#pragma once
#include "../Model/MMercadoria.h"
#include "../Model/MFuncionario.h"
#include "../DAO/ColchaoDAOcsv.h"
#include "../DAO/EstofadoDAOcsv.h"
#include "../DAO/FuncionarioDAOcsv.h"
#include "../Model/MEstoque.h"
#include "UData.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class URelatorio
{
private:
    double entrada;
    double saida;
    double pagamentos;
    string fluxoDePagamentos;
    string fluxoDeCaixa;
    UData entrada;
    UData saida;
    ColchaoDAOcsv colchoes;
    EstofadoDAOcsv estofados;
    FuncionarioDAOcsv funcionarios;
    fstream arquivo;

public:
    URelatorio();
    ~URelatorio();
    string gerarFluxoDeCaixaMensal(int mes, int ano);
    bool gerarFluxoDeCaixa(int ano);
    void gerarFluxoDePagamentos();
};
