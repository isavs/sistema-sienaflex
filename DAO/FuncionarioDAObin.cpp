#include "FuncionarioDAObin.h"
#include <iostream>
#include <string.h>
FuncionarioDAObin::FuncionarioDAObin() {

}
FuncionarioDAObin::~FuncionarioDAObin() {
    fechar();
}

/*Métodos privados*/

bool FuncionarioDAObin::gravar(sFuncionario Funcionario, const char* nome) {

    if(abrir(nome, ios::app)){
            arquivo.write((const char*)(&Funcionario), sizeof(sFuncionario));
            fechar();
            return true;
        }
    fechar();
    return false;
}

/*Métodos publicos*/

bool FuncionarioDAObin::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);
    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

bool FuncionarioDAObin::gravar(const char* nome, MFuncionario* funcionario) {
    sFuncionario p;
    
    strcpy(p.nome, (funcionario->getNome()).c_str());
    strcpy(p.cpf, (funcionario->getCpf()).c_str());
    strcpy(p.telefone, (funcionario->getTelefone()).c_str());
    strcpy(p.bairro, (funcionario->getEndereco().getBairro()).c_str());
    strcpy(p.cep, (funcionario->getEndereco().getCep()).c_str());
    strcpy(p.cidade, (funcionario->getEndereco().getCidade()).c_str());
    strcpy(p.complemento, (funcionario->getEndereco().getComplemento()).c_str());
    strcpy(p.estado, (funcionario->getEndereco().getEstado()).c_str());
    strcpy(p.pais, (funcionario->getEndereco().getPais()).c_str());
    strcpy(p.rua, (funcionario->getEndereco().getRua()).c_str());
    strcpy(p.numero, (funcionario->getEndereco().getNumero()).c_str());
    strcpy(p.cargo, (funcionario->getCargo()).c_str());
    p.id = funcionario->getId();
    p.salario = funcionario->getSalario();
    return gravar(p, nome);
}

list<MFuncionario*> FuncionarioDAObin::getListaFuncionarios(const char* nome) {
    list<MFuncionario*> lista;
    sFuncionario p;

    if(abrir(nome, ios::in)){
        while(arquivo && !arquivo.eof()) {
            arquivo.read((char *)(&p), sizeof(sFuncionario));
            printf("A RUA AQUI NA GET: %s .\n",p.rua);
            UEndereco* endereco = new UEndereco(p.cep,p.rua,p.numero,p.bairro,p.cidade,p.estado,p.pais,p.complemento);
            MFuncionario* funcionario = new MFuncionario(p.id,p.nome,p.cpf, p.telefone,*endereco, p.cargo, p.salario);
            lista.push_back(funcionario);
        }        
    }

    fechar();
    return lista;
}


void FuncionarioDAObin::fechar(){
    arquivo.close();
}