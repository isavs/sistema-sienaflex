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
using namespace std;

class URelatorio
{
private:
    double entrada;
    double saida;
    double compras;
    double vendas;
    double pagamentos;
    string fluxoDePagamentos;
    string fluxoDeCaixa;
    UData entrada;
    UData saida;
    ColchaoDAOcsv colchoes;
    EstofadoDAOcsv estofados;
    FuncionarioDAOcsv funcionarios;

public:
    URelatorio();
    ~URelatorio();
    void gerarFluxoDeCaixa();
    void gerarFluxoDePagamentos();
};
