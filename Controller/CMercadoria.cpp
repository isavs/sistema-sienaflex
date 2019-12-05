#include "CMercadoria.h"

int CMercadoria::ids = 0;

CMercadoria::CMercadoria()
{

}

CMercadoria::~CMercadoria()
{

}

bool CMercadoria::criarColchao(string nome)
{
    MMercadoria* colchao = new MMercadoria();
    colchao->setId(++id);
    colchao->setNome(nome);

}

bool CMercadoria::criarBase()
{

}

bool CMercadoria::criarSofa()
{

}

bool CMercadoria::criarPoltrona()
{

}

bool CMercadoria::criarPuff()
{

}
