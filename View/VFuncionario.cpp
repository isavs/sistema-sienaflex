#include "VFuncionario.h"

VFuncionario::VFuncionario()
{

}

VFuncionario::~VFuncionario()
{

}

void VFuncionario::view()
{
    int opcao = -1;
    while (opcao != 6){
        cout << "\nPESSOAL\n1 - Cadastrar novo funcionario || 2 - Atualizar dados de funcionario || 3 - Pesquisar funcionario || 4 - Desligar funcionario || 5 - Lista de funcionarios || 6 - Voltar\n>> ";
        //__fpurge(stdin);
        fflush(stdin);
        cin >> opcao;
        switch (opcao)
        {
            case 1:
            {
                cadastrar();
                break;
            }
            case 2:
            {
                atualizar();
                break;
            }
            case 3:
            {
                pesquisar();
                break;
            }
            case 4:
            {
                desligar();
                break;
            }
            case 5:
            {
                listar();
                break;
            }
            case 6:
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

void VFuncionario::cadastrar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    UEndereco endereco;
    string nome = "";
    string cpf = "";
    string telefone = "";
    string cep = "";
    string rua = "";
    string numero = "";
    string bairro = "";
    string cidade = "";
    string estado = "";
    string pais = "";
    string complemento = "";
    string cargo = "";
    float salarioHora = 0.0;
    cout << "Dados do funcionario" << endl;
    cout << "Nome: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Cpf: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, cpf);
    cout << "Telefone: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, telefone);
    cout << "Cargo: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, cargo);
    cout << "Salario (hora): ";
    //__fpurge(stdin);
    fflush(stdin);
    cin >> salarioHora;
    if (!cFuncionarios.adicionar(nome, cpf, telefone, endereco, cargo, salarioHora))
        cout << "Erro ao cadastrar" << endl;
}

void VFuncionario::pesquisar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    MFuncionario* funcionario = new MFuncionario();
    int id = -1;
    string nome = "";
    string cpf = "";
    cout << "Id: ";
    //__fpurge(stdin);
    fflush(stdin);
    cin >> id;
    cout << "Nome: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Cpf: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, cpf);
    if (id != -1 || cpf != ""){
        funcionario = cFuncionarios.pesquisar(id, cpf);
        if (funcionario != NULL){
            getDados(funcionario);
        }
        else{
            cout << "\nFuncionario nao encontrado." << endl;
        }
    }
    else if (nome != ""){
        list<MFuncionario*> lista = cFuncionarios.pesquisarNomes(nome);
        list<MFuncionario*>::iterator it;
        for (it = lista.begin(); it != lista.end(); ++it){
            getDados(*it);
            cout << endl;
        }
    }
}

void VFuncionario::atualizar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    MFuncionario* funcionario = new MFuncionario();
    int id = -1;
    UEndereco endereco;
    string nome = "";
    string cpf = "";
    string telefone = "";
    string cep = "";
    string rua = "";
    string numero = "";
    string bairro = "";
    string cidade = "";
    string estado = "";
    string pais = "";
    string complemento = "";
    string cargo = "";
    float salario = 0.0;
    cout << "Dados do funcionario" << endl;
    cout << "Id: ";
    //__fpurge(stdin);
    fflush(stdin);
    cin >> id;
    funcionario = cFuncionarios.pesquisar(id, cpf);
    if (funcionario == NULL){
        cout << "Funcionario nao cadastrado" << endl;
        return;
    }
    cout << "Nome: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Cpf: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, cpf);
    cout << "Telefone: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, telefone);
    cout << "Cargo: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, cargo);
    cout << "Salario: ";
    //__fpurge(stdin);
    fflush(stdin);
    cin >> salario;
    cFuncionarios.atualizar(funcionario, nome, cpf, telefone, endereco, cargo, salario);
}

void VFuncionario::desligar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    int id;
    string nome;
    cout << "Nome: ";
    //__fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Id: ";
    //__fpurge(stdin);
    fflush(stdin);
    cin >> id;
    if (cFuncionarios.remover(nome, id))
        cout << "Funcionario desligado." << endl;
    else
        cout << "Funcionario nao encontrado." << endl;
}

void VFuncionario::listar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    list<MFuncionario*> lista = cFuncionarios.listar();
    list<MFuncionario*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        getDados(*it);
        cout << endl;
    }
}

void VFuncionario::getDados(MFuncionario* funcionario)
{
    cout << "Funcionario com id " << funcionario->getId() << endl;
    cout << funcionario->getNome() << "\t" << funcionario->getCargo() << "\tCPF "
         << funcionario->getCpf() << "Telefone: " << funcionario->getTelefone() << endl;
    cout << "Endereco: " << funcionario->getEndereco().getRua() << ", "
         << funcionario->getEndereco().getNumero() << " - "
         << funcionario->getEndereco().getBairro() << " - "
         << funcionario->getEndereco().getCidade() << " - "
         << funcionario->getEndereco().getEstado() << " - "
         << funcionario->getEndereco().getPais() << " - "
         << funcionario->getEndereco().getCep() << " - "
         << funcionario->getEndereco().getComplemento() << endl;
}
