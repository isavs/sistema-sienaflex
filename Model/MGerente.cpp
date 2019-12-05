#include "MGerente.h"

MGerente::MGerente()
{

}

MGerente::MGerente(int id, string nome)
{
    this->id = id;
    this->salario = salario;
}

MGerente::~MGerente()
{

}

void MGerente::setId(int id)
{
    this->id = id;
}

void MGerente::setSalario(double salario)
{
    this->salario = salario;
}

void MGerente::setStatus(bool ativo)
{
    this->ativo = ativo;
}

void MGerente::setBonus(double bonus)
{
    this->bonus = bonus;
}

const int MGerente::getId()
{
    return id;
}

const double MGerente::getSalario()
{
    return salario;
}

const bool MGerente::getStatus()
{
    return ativo;
}

const double MGerente::getBonus()
{
    return bonus;
}
