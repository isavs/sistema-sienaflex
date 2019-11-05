#pragma once
#include "Mercadoria.h"

class Colchao: public Mercadoria
{
private:
public:
  Colchao(const char *nome);
  ~Colchao();
  const char* getNome(){ return nome; }
};