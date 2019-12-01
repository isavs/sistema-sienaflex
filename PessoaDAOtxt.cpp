#include "PessoaDAOtxt.h"

PessoaDAOtxt::PessoaDAOtxt() {

}
PessoaDAOtxt::~PessoaDAOtxt() {
    fechar();
}

/*Métodos privados*/

string PessoaDAOtxt::ler(const char* nome){

    if (abrir(nome, ios::in)) {
        string strArquivo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
        fechar();
        return strArquivo;
    }

    return nullptr;
}

bool PessoaDAOtxt::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);

    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}
Endereco* PessoaDAOtxt::getEndereco(string linha) {

    char* cep = (char*)(copiar(&linha, ';')).c_str();
    char* rua = (char*)(copiar(&linha, ';')).c_str();
    int numero = stoi(copiar(&linha, ';'));
    char* bairro = (char*)(copiar(&linha, ';')).c_str();
    char* cidade = (char*)(copiar(&linha, ';')).c_str();
    char* estado = (char*)(copiar(&linha, ';')).c_str();
    char* pais = (char*)(copiar(&linha, ';')).c_str();
    char* complemento = (char*)(copiar(&linha, ';')).c_str();

    Endereco* endereco = new Endereco(cep, rua, numero, bairro, cidade, estado, pais, complemento);
    return endereco;
}
Pessoa*  PessoaDAOtxt::getPessoa(string linha) {
    
    string nome = copiar(&linha, ';');
    string cpf = copiar(&linha, ';');
    string telefone = copiar(&linha, ';');
    
    Endereco endereco = *getEndereco(linha);
    Pessoa* pessoa = new Pessoa(nome, cpf, telefone, endereco);

    return pessoa;
 }

string  PessoaDAOtxt::copiar(string *s, char parada)  {
    string destino;
    int i;
    for(i = 0; (*s)[i] != parada; i++){
        destino.push_back((*s)[i]);
    }
    s->erase(0, i+1);
    return destino;
}

bool  PessoaDAOtxt::gravar(const char* nome, string s) {
    
    if(abrir(nome, ios::app)){
        arquivo << s << endl;
        fechar();
        return true;
    }

    return false;
}
/*Métodos publicos*/

bool PessoaDAOtxt::gravar(const char* nome, Pessoa* Pessoa) {

    string s = Pessoa->getNome() + ";" 
    + Pessoa->getCpf() + ";" 
    + Pessoa->getTelefone() + ";" 
    + Pessoa->getEndereco().getCep() + ";" 
    + Pessoa->getEndereco().getRua() + ";"
    + to_string(Pessoa->getEndereco().getNumero()) + ";"
    + Pessoa->getEndereco().getBairro() + ";"
    + Pessoa->getEndereco().getCidade() + ";"
    + Pessoa->getEndereco().getEstado() + ";"
    + Pessoa->getEndereco().getPais() + ";"
    + Pessoa->getEndereco().getComplemento() + ";";


    return gravar(nome, s);
}

list<Pessoa*> PessoaDAOtxt::getListaPessoas(const char* nome) {
    string arquivo = ler(nome);
    list<Pessoa*> lista;
    while(!arquivo.empty()) {
        string linha = copiar(&arquivo, '\n');
        lista.push_back(getPessoa(linha));
    }

    return lista;
}

void PessoaDAOtxt::fechar(){
    arquivo.close();
}