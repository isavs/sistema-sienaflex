#include "FuncionarioDAOcsv.h"

FuncionarioDAOcsv::FuncionarioDAOcsv() {

}
FuncionarioDAOcsv::~FuncionarioDAOcsv() {
    fechar();
}

/*Métodos privados*/

string FuncionarioDAOcsv::ler(const char* nome){

    if (abrir(nome, ios::in)) {
        string strArquivo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
        fechar();
        return strArquivo;
    }

    return nullptr;
}

bool FuncionarioDAOcsv::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);

    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}
UEndereco* FuncionarioDAOcsv::getEndereco(string linha) {

    char* cep = (char*)(copiar(&linha, ';')).c_str();
    char* rua = (char*)(copiar(&linha, ';')).c_str();
    char* numero = (char*)(copiar(&linha, ';')).c_str();
    char* bairro = (char*)(copiar(&linha, ';')).c_str();
    char* cidade = (char*)(copiar(&linha, ';')).c_str();
    char* estado = (char*)(copiar(&linha, ';')).c_str();
    char* pais = (char*)(copiar(&linha, ';')).c_str();
    char* complemento = (char*)(copiar(&linha, ';')).c_str();

    UEndereco* endereco = new UEndereco(cep, rua, numero, bairro, cidade, estado, pais, complemento);
    return endereco;
}
MFuncionario*  FuncionarioDAOcsv::getFuncionario(string linha) {
    
    int id = stoi(copiar(&linha, ';'));
    string nome = copiar(&linha, ';');
    string cargo = copiar(&linha, ';');
    string cpf = copiar(&linha, ';');
    string telefone = copiar(&linha, ';');
    double salario = stod(copiar(&linha, ';'));
    UEndereco endereco = *getEndereco(linha);
    MFuncionario* funcionario = new MFuncionario(id, nome, cpf, telefone, endereco, cargo, salario);

    return funcionario;
 }

string  FuncionarioDAOcsv::copiar(string *s, char parada)  {
    string destino;
    int i;
    for(i = 0; (*s)[i] != parada; i++){
        destino.push_back((*s)[i]);
    }
    s->erase(0, i+1);
    return destino;
}

bool  FuncionarioDAOcsv::gravar(const char* nome, string s) {
    
    if(abrir(nome, ios::app)){
        arquivo << s << endl;
        fechar();
        return true;
    }

    return false;
}
/*Métodos publicos*/

bool FuncionarioDAOcsv::gravar(const char* nome, MFuncionario* funcionario) {

    string s = to_string(funcionario->getId()) + ";" 
    + funcionario->getNome() + ";" 
    + funcionario->getCargo() + ";" 
    + funcionario->getCpf() + ";" 
    + funcionario->getTelefone() + ";" 
    + to_string(funcionario->getSalario()) + ";"
    + funcionario->getEndereco().getCep() + ";" 
    + funcionario->getEndereco().getRua() + ";"
    + funcionario->getEndereco().getNumero() + ";"
    + funcionario->getEndereco().getBairro() + ";"
    + funcionario->getEndereco().getCidade() + ";"
    + funcionario->getEndereco().getEstado() + ";"
    + funcionario->getEndereco().getPais() + ";"
    + funcionario->getEndereco().getComplemento() + ";";


    return gravar(nome, s);
}

list<MFuncionario*> FuncionarioDAOcsv::getListaFuncionarios(const char* nome) {
    string arquivo = ler(nome);
    list<MFuncionario*> lista;
    while(!arquivo.empty()) {
        string linha = copiar(&arquivo, '\n');
        lista.push_back(getFuncionario(linha));
    }

    return lista;
}

void FuncionarioDAOcsv::fechar(){
    arquivo.close();
}