#include "PessoaDAObin.h"
#include <iostream>
#include <string.h>
PessoaDAObin::PessoaDAObin() {

}
PessoaDAObin::~PessoaDAObin() {
    fechar();
}

/*Métodos privados*/

bool PessoaDAObin::gravar(const char* nome, sPessoa pessoa) {

    if(abrir(nome, ios::app)){
            arquivo.write((const char*)(&pessoa), sizeof(sPessoa));
            fechar();
            return true;
        }
    fechar();
    return false;
}

/*Métodos publicos*/

bool PessoaDAObin::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);
    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

bool PessoaDAObin::gravar(const char* nome, Pessoa* pessoa) {
    sPessoa p;
    
    strcpy(p.nome, (pessoa->getNome()).c_str());
    strcpy(p.cpf, (pessoa->getCpf()).c_str());
    strcpy(p.telefone, (pessoa->getTelefone()).c_str());
    strcpy(p.bairro, pessoa->getEndereco().getBairro());
    strcpy(p.cep, pessoa->getEndereco().getCep());
    strcpy(p.cidade, pessoa->getEndereco().getCidade());
    strcpy(p.complemento, pessoa->getEndereco().getComplemento());
    strcpy(p.estado, pessoa->getEndereco().getEstado());
    strcpy(p.pais, pessoa->getEndereco().getPais());
    strcpy(p.rua, pessoa->getEndereco().getRua());
    p.numero = pessoa->getEndereco().getNumero();


    return gravar(nome, p);
}

list<Pessoa*> PessoaDAObin::getListaPessoas(const char* nome) {
    list<Pessoa*> lista;
    sPessoa p;

    if(abrir(nome, ios::in)){
        while(arquivo && !arquivo.eof()) {
            arquivo.read((char *)(&p), sizeof(sPessoa));
            Endereco* endereco = new Endereco(p.cep,p.rua,p.numero,p.bairro,p.cidade,p.estado,p.pais,p.complemento);
            Pessoa* pessoa = new Pessoa(p.nome,p.cpf, p.telefone,*endereco);
            lista.push_back(pessoa);
        }        
    }

    fechar();
    return lista;
}


void PessoaDAObin::fechar(){
    arquivo.close();
}