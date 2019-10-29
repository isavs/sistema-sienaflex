#pragma once


class Mercadoria {
private:
    int id;
    char* nome, 
        fabricante,
        cor,
        marca;
    float custo,
        preco;
    bool vendida;
    
public:
    Mercadoria();
    ~Mercadoria();
};