#include "VMercadoria.h"

VMercadoria::VMercadoria()
{

}

VMercadoria::~VMercadoria()
{

}

void VMercadoria::view()
{
    int opcao = -1;
    while (opcao != 6){
        cout << "\n==================== MERCADORIAS ====================" << endl;
        cout << "\n1 - Cadastrar\t|\t2 - Atualizar\t|\t3 - Pesquisar\n4 - Remover\t|\t5 - Listar\t|\t6 - Voltar\n>> ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> opcao;
        cout << endl;
        switch (opcao)
        {
            case 1:
            {
                adicionar();
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
                remover();
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

void VMercadoria::adicionar()
{
    CMercadoria& cMercadoria = CMercadoria::getCMercadoria();
    string nome = "";
    string fabricante = "";
    string cor = "";
    float largura = 0.0;
    float altura = 0.0;
    float profundidade = 0.0;
    float custo = 0.0;
    float preco = 0.0;
    string tamanho = "";
    float lugares = 0;
    bool valido = false;
    int opcao = -1;
    while (opcao != 6){
        cout << "\n==================== CADASTRO DE MERCADORIA ====================" << endl;
        cout << "\n1 - Colchao\t|\t2 - Base\t|\t3 - Sofa\n4 - Poltrona\t|\t5 - Puff\t|\t6 - Voltar\n>> ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> opcao;
        cout << endl;
        switch (opcao)
        {
            case 1:
            {
                cout << "\n==================== CADASTRO DE COLCHAO ====================" << endl;
                cout << endl;
                cout << "Nome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Custo: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> custo;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Tamanho: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, tamanho);
                cout << endl;
                valido = cMercadoria.criarColchao(nome, fabricante, cor, largura, altura, profundidade, custo, preco, tamanho);
                if (!valido)
                    cout << "!!! Erro ao cadastrar !!!" << endl;
                break;
            }
            case 2:
            {
                cout << "\n==================== CADASTRO DE BASE ====================" << endl;
                cout << "Nome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Custo: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> custo;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Tamanho: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, tamanho);
                if (!cMercadoria.criarBase(nome, fabricante, cor, largura, altura, profundidade, custo, preco, tamanho))
                    cout << "!!! Erro ao cadastrar !!!" << endl;
                break;
            }
            case 3:
            {
                cout << "\n==================== CADASTRO DE SOFA ====================" << endl;
                cout << "Nome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Custo: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> custo;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Lugares: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> lugares;
                if (!cMercadoria.criarSofa(nome, fabricante, cor, largura, altura, profundidade, custo, preco, lugares))
                    cout << "!!! Erro ao cadastrar !!!" << endl;
                break;
            }
            case 4:
            {
                cout << "\n==================== CADASTRO DE POLTRONA ====================" << endl;
                cout << "Nome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Custo: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> custo;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Lugares: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> lugares;
                if (!cMercadoria.criarPoltrona(nome, fabricante, cor, largura, altura, profundidade, custo, preco, lugares))
                    cout << "!!! Erro ao cadastrar !!!" << endl;
                break;
            }
            case 5:
            {
                cout << "\n==================== CADASTRO DE PUFF ====================" << endl;
                cout << "Nome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Custo: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> custo;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Lugares: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> lugares;
                if (!cMercadoria.criarPuff(nome, fabricante, cor, largura, altura, profundidade, custo, preco, lugares))
                    cout << "!!! Erro ao cadastrar !!!" << endl;
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

void VMercadoria::atualizar()
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    MColchao* colchao = new MColchao();
    MEstofado* estofado = new MEstofado();
    int id = -1;
    string nome = "";
    string fabricante = "";
    string cor = "";
    float largura = 0.0;
    float altura = 0.0;
    float profundidade = 0.0;
    float custo = 0.0;
    float preco = 0.0;
    string tamanho = "";
    float lugares = 0;
    cout << "\n==================== ATUALIZACAO DE MERCADORIA ====================" << endl;
    cout << endl;
    cout << "Id: ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> id;
    colchao = cEstoque.pesquisarColchao(id);
    estofado = cEstoque.pesquisarEstofado(id);
    if (colchao == NULL && estofado == NULL){
        cout << "!!! Mercadoria nao encontrada !!!" << endl;
        return;
    }
    if (colchao != NULL){
        cout << "\nNome do modelo: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, nome);
        cout << "Fabricante: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, fabricante);
        cout << "Cor: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, cor);
        cout << "Largura: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> largura;
        cout << "Altura: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> altura;
        cout << "Profundidade: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> profundidade;
        cout << "Preco: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> preco;
        cout << "Tamanho: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, tamanho);
        cout << endl;
        cEstoque.atualizarColchao(colchao, nome, fabricante, cor, largura, altura, profundidade, preco, tamanho);
    }
    else{
        cout << "\nNome do modelo: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, nome);
        cout << "Fabricante: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, fabricante);
        cout << "Cor: ";
        __fpurge(stdin);
        fflush(stdin);
        getline(cin, cor);
        cout << "Largura: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> largura;
        cout << "Altura: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> altura;
        cout << "Profundidade: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> profundidade;
        cout << "Preco: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> preco;
        cout << "Lugares: ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> lugares;
        cout << endl;
        cEstoque.atualizarEstofado(estofado, nome, fabricante, cor, largura, altura, profundidade, preco, lugares);
    }
}

void VMercadoria::pesquisar()
{
    int opcao = -1;
    while (opcao != 3){
        cout << "\n==================== PESQUISA DE MERCADORIA ====================" << endl;
        cout << endl;
        cout << "\n1 - Pesquisar produto especifico\t|\t2 - Pesquisar lista de produtos\n3 - Voltar\n>> ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> opcao;
        cout << endl;
        switch (opcao)
        {
            case 1:
            {
                pesquisarId();
                break;
            }
            case 2:
            {
                pesquisarCaracteristicas();
                break;
            }
            default:
                break;
        }
    }
}

void VMercadoria::pesquisarId()
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    MColchao* colchao = new MColchao();
    MEstofado* estofado = new MEstofado();
    int id = -1;
    cout << "Id: ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> id;
    cout << endl;
    colchao = cEstoque.pesquisarColchao(id);
    estofado = cEstoque.pesquisarEstofado(id);
    if (colchao == NULL && estofado == NULL){
        cout << "!!! Mercadoria nao encontrada !!!" << endl;
        return;
    }
    if (colchao != NULL)
        imprimirInformacoes(colchao);
    else
        imprimirInformacoes(estofado);
    cout << endl;
}

void VMercadoria::pesquisarCaracteristicas()
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    list<MColchao*> listaColchoes;
    list<MEstofado*> listaEstofados;
    string nome = "";
    string fabricante = "";
    string cor = "";
    float largura = 0.0;
    float altura = 0.0;
    float profundidade = 0.0;
    float preco = 0.0;
    string tamanho = "";
    float lugares = 0;
    int opcao = -1;
    while (opcao != 6){
        cout << "\n==================== PESQUISA DE MERCADORIAS ====================" << endl;
        cout << "\n1 - Colchao\t|\t2 - Base\t|\t3 - Sofa\n4 - Poltrona\t|\t5 - Puff\t|\t6 - Voltar\n>> ";
        cin >> opcao;
        cout << endl;
        switch (opcao)
        {
            case 1:
            {
                cout << "\n==================== DADOS DE PESQUISA DE COLCHAO ====================" << endl;
                cout << endl;
                cout << "\nNome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Tamanho: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, tamanho);
                cout << endl;
                listaColchoes = cEstoque.pesquisarColchoes(1, nome, fabricante, cor, largura, altura, profundidade, preco, tamanho);
                if (listaColchoes.empty()){
                    cout << "!!! Nenhuma mercadoria encontrada !!!" << endl;
                    break;
                }
                cout << "Mercadorias encontradas\n" << endl;
                cout << endl;
                list<MColchao*>::iterator it;
                for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                cout << "\n==================== DADOS DE PESQUISA DE BASE ====================" << endl;
                cout << endl;
                cout << "\nNome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Tamanho: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, tamanho);
                cout << endl;
                listaColchoes = cEstoque.pesquisarColchoes(2, nome, fabricante, cor, largura, altura, profundidade, preco, tamanho);
                if (listaColchoes.empty()){
                    cout << "!!! Nenhuma mercadoria encontrada !!!" << endl;
                    break;
                }
                cout << "Mercadorias encontradas\n" << endl;
                cout << endl;
                list<MColchao*>::iterator it;
                for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 3:
            {
                cout << "\n==================== DADOS DE PESQUISA DE SOFA ====================" << endl;
                cout << endl;
                cout << "\nNome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Lugares: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> lugares;
                cout << endl;
                listaEstofados = cEstoque.pesquisarEstofados(3, nome, fabricante, cor, largura, altura, profundidade, preco, lugares);
                if (listaEstofados.empty()){
                    cout << "!!! Nenhuma mercadoria encontrada !!!" << endl;
                    break;
                }
                cout << "Mercadorias encontradas\n" << endl;
                cout << endl;
                list<MEstofado*>::iterator it;
                for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                cout << "\n==================== DADOS DE PESQUISA DE POLTRONA ====================" << endl;
                cout << endl;
                cout << "\nNome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Lugares: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> lugares;
                cout << endl;
                listaEstofados = cEstoque.pesquisarEstofados(4, nome, fabricante, cor, largura, altura, profundidade, preco, lugares);
                if (listaEstofados.empty()){
                    cout << "!!! Nenhuma mercadoria encontrada !!!" << endl;
                    break;
                }
                cout << "Mercadorias encontradas\n" << endl;
                cout << endl;
                list<MEstofado*>::iterator it;
                for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 5:
            {
                cout << "\n==================== DADOS DE PESQUISA DE PUFF ====================" << endl;
                cout << endl;
                cout << "\nNome do modelo: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, nome);
                cout << "Fabricante: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, fabricante);
                cout << "Cor: ";
                __fpurge(stdin);
                fflush(stdin);
                getline(cin, cor);
                cout << "Largura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> largura;
                cout << "Altura: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> altura;
                cout << "Profundidade: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> profundidade;
                cout << "Preco: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> preco;
                cout << "Lugares: ";
                __fpurge(stdin);
                fflush(stdin);
                cin >> lugares;
                cout << endl;
                listaEstofados = cEstoque.pesquisarEstofados(5, nome, fabricante, cor, largura, altura, profundidade, preco, lugares);
                if (listaEstofados.empty()){
                    cout << "!!! Nenhuma mercadoria encontrada !!!" << endl;
                    break;
                }
                cout << "Mercadorias encontradas\n" << endl;
                cout << endl;
                list<MEstofado*>::iterator it;
                for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
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

void VMercadoria::remover()
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    int id = -1;
    cout << "Id: ";
    __fpurge(stdin);
    fflush(stdin);
    cin >> id;
    cout << endl;
    if (cEstoque.removerColchao(id))
        cout << "Colchao removido com sucesso." << endl;
    else if (cEstoque.removerBase(id))
        cout << "Base removida com sucesso." << endl;
    else if (cEstoque.removerSofa(id))
        cout << "Sofa removido com sucesso." << endl;
    else if (cEstoque.removerPoltrona(id))
        cout << "Poltrona removida com sucesso." << endl;
    else if (cEstoque.removerPuff(id))
        cout << "Puff removida com sucesso." << endl;
    else
        cout << "Mercadoria nao encontrada." << endl;
    cout << endl;
}

void VMercadoria::listar()
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    list<MColchao*> listaColchoes;
    listaColchoes.clear();
    list<MEstofado*> listaEstofados;
    listaEstofados.clear();
    int opcao = -1;
    while (opcao != 6){
        cout << "\n==================== LISTA DE MERCADORIA ====================" << endl;
        cout << "\n1 - Colchoes\t|\t2 - Bases\t|\t3 - Sofas\t|\t4 - Poltronas\t|\t5 - Puffs\t|\t6 - Voltar\n>> ";
        __fpurge(stdin);
        fflush(stdin);
        cin >> opcao;
        cout << endl;
        switch (opcao)
        {
            case 1:
            {
                listaColchoes = cEstoque.listarColchoes();
                list<MColchao*>::iterator it;
                for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                listaColchoes = cEstoque.listarBases();
                list<MColchao*>::iterator it;
                int i = 0;
                for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
                    imprimirInformacoes(*it);
                    i++;
                    printf("passou %d\n\n", i);
                    cout << endl;
                }
                break;
            }
            case 3:
            {
                listaEstofados = cEstoque.listarSofas();
                list<MEstofado*>::iterator it;
                for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                listaEstofados = cEstoque.listarPoltronas();
                list<MEstofado*>::iterator it;
                for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
                break;
            }
            case 5:
            {
                listaEstofados = cEstoque.listarPuffs();
                list<MEstofado*>::iterator it;
                for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
                    imprimirInformacoes(*it);
                    cout << endl;
                }
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

void VMercadoria::imprimirInformacoes(MColchao* mercadoria)
{
    cout << "Id mercadoria: " << mercadoria->getId() << endl;
    cout << "Nome do modelo: " << mercadoria->getNome() << endl;
    cout << "Fabricante: " << mercadoria->getFabricante() << endl;
    cout << "Cor: " << mercadoria->getCor() << endl;
    cout << "Largura: " << mercadoria->getLargura() << endl;
    cout << "Altura: " << mercadoria->getAltura() << endl;
    cout << "Profundidade: " << mercadoria->getProfundidade() << endl;
    cout << "Preco: " << mercadoria->getPreco() << endl;
    cout << "Tamanho: " << mercadoria->getTamanho() << endl;
}

void VMercadoria::imprimirInformacoes(MEstofado* mercadoria)
{
    cout << "Id mercadoria: " << mercadoria->getId() << endl;
    cout << "Nome do modelo: " << mercadoria->getNome() << endl;
    cout << "Fabricante: " << mercadoria->getFabricante() << endl;
    cout << "Cor: " << mercadoria->getCor() << endl;
    cout << "Largura: " << mercadoria->getLargura() << endl;
    cout << "Altura: " << mercadoria->getAltura() << endl;
    cout << "Profundidade: " << mercadoria->getProfundidade() << endl;
    cout << "Preco: " << mercadoria->getPreco() << endl;
    cout << "Lugares: " << mercadoria->getLugares() << endl;
}

void VMercadoria::salvar()
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    cEstoque.salvarEstoque();
}
