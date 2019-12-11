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
        cout << "\n==================== PESSOAL ====================" << endl;
        cout << "\n1 - Cadastrar novo funcionario\t|\t2 - Atualizar dados de funcionario\t|\t3 - Pesquisar funcionario\n4 - Desligar funcionario\t|\t5 - Lista de funcionarios\t\t|\t6 - Voltar\n>> ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> opcao;
        cout << endl;
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
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Cpf: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cpf);
    cout << "Telefone: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, telefone);
    cout << "Cargo: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cargo);
    cout << "Salario (hora): ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> salarioHora;
    cout << "Cep: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cep);
    cout << "Rua: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, rua);
    cout << "Bairro: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, bairro);
    cout << "Numero: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, numero);
    cout << "Cidade: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cidade);
    cout << "Estado: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, estado);
    cout << "Pais: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, pais);
    cout << "Complemento: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, complemento);
    cout << endl;
    endereco.setCep(cep);
    endereco.setRua(rua);
    endereco.setNumero(numero);
    endereco.setBairro(bairro);
    endereco.setCidade(cidade);
    endereco.setEstado(estado);
    endereco.setPais(pais);
    endereco.setComplemento(complemento);
    if (!cFuncionarios.adicionar(nome, cpf, telefone, endereco, cargo, salarioHora))
        cout << "!!! Erro ao cadastrar !!!" << endl;
}

void VFuncionario::pesquisar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    MFuncionario* funcionario = new MFuncionario();
    int id = -1;
    string nome = "";
    string cpf = "";
    cout << "Id: ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> id;
    cout << "Nome: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Cpf: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cpf);
    if (id != -1 || cpf != ""){
        funcionario = cFuncionarios.pesquisar(id, cpf);
        if (funcionario != NULL){
            imprimirInformacoes(funcionario);
        }
        else{
            cout << "\n!!! Funcionario nao encontrado !!!" << endl;
        }
    }
    else if (nome != ""){
        cout << "Funcionarios encontrados" << endl;
        cout << endl;
        list<MFuncionario*> lista = cFuncionarios.pesquisarNomes(nome);
        list<MFuncionario*>::iterator it;
        for (it = lista.begin(); it != lista.end(); ++it){
            imprimirInformacoes(*it);
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
    __fpurge(stdin);
    fflush(stdin);
    cin >> id;
    funcionario = cFuncionarios.pesquisar(id, cpf);
    if (funcionario == NULL){
        cout << "Funcionario nao encontrado" << endl;
        return;
    }
    cout << "Nome: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Cpf: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cpf);
    cout << "Telefone: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, telefone);
    cout << "Cargo: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cargo);
    cout << "Salario: ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> salario;
    cout << "Cep: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cep);
    cout << "Rua: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, rua);
    cout << "Bairro: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, bairro);
    cout << "Numero: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, numero);
    cout << "Cidade: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, cidade);
    cout << "Estado: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, estado);
    cout << "Pais: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, pais);
    cout << "Complemento: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, complemento);
    cout << endl;
    endereco.setCep(cep);
    endereco.setRua(rua);
    endereco.setNumero(numero);
    endereco.setBairro(bairro);
    endereco.setCidade(cidade);
    endereco.setEstado(estado);
    endereco.setPais(pais);
    endereco.setComplemento(complemento);
    cFuncionarios.atualizar(funcionario, nome, cpf, telefone, endereco, cargo, salario);
}

void VFuncionario::desligar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    int id;
    string nome;
    cout << "Nome: ";
    __fpurge(stdin);
    fflush(stdin);
    getline(cin, nome);
    cout << "Id: ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> id;
    cout << endl;
    if (cFuncionarios.remover(nome, id))
        cout << "Funcionario desligado." << endl;
    else
        cout << "!!! Funcionario nao encontrado !!!" << endl;
    cout << endl;
}

void VFuncionario::listar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    list<MFuncionario*> lista = cFuncionarios.listar();
    list<MFuncionario*>::iterator it;
    cout << "Lista de funcionarios" << endl;
    cout << endl;
    for (it = lista.begin(); it != lista.end(); ++it){
        imprimirInformacoes(*it);
        cout << endl;
    }
}

void VFuncionario::salvar()
{
    CFuncionarios& cFuncionarios = CFuncionarios::getCFuncionarios();
    cFuncionarios.salvarFuncionarios();
}

void VFuncionario::imprimirInformacoes(MFuncionario* funcionario)
{
    cout << "Id: " << funcionario->getId() << endl;
    cout << "Nome: " << funcionario->getNome() << endl;
    cout << "Cpf: " << funcionario->getCpf() << endl;
    cout << "Telefone: " << funcionario->getTelefone() << endl;
    cout << "Cargo: " << funcionario->getCargo() << endl;
    cout << "Endereco" << endl;
    cout << "Rua: " << funcionario->getEndereco().getRua()
         << ", " << funcionario->getEndereco().getNumero() << endl;
    cout << "Bairro: " << funcionario->getEndereco().getBairro() << endl;
    cout << "Cidade: " << funcionario->getEndereco().getCidade() << endl;
    cout << "Estado: " << funcionario->getEndereco().getEstado() << endl;
    cout << "Pais: " << funcionario->getEndereco().getPais() << endl;
    cout << "Cep: " << funcionario->getEndereco().getCep() << endl;
    cout << "Complemento: " << funcionario->getEndereco().getComplemento() << endl;
}
