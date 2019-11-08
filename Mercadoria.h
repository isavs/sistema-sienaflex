#pragma once


class Mercadoria {
protected:
    int id;
    const char *nome,
        *fabricante,
        *cor,
        *marca;
    float custo,
        preco;
    bool vendida;

public:
    Mercadoria();
    ~Mercadoria();
    void cadastrarColchao(const char* nome){}
};
