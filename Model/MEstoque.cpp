#include "MEstoque.h"
#include <time.h>

MEstoque::MEstoque()
{
    listaColchoes = ccsv.getListaColchaos("../BDbin/BDColchoes.csv");
    listaBases = ccsv.getListaColchaos("../BDbin/BDBases.csv");

    listaSofas = ecsv.getListaEstofados("../BDbin/BDSofas");
    listaPuffs = ecsv.getListaEstofados("../BDbin/BDPuffs");
    listaPoltronas = ecsv.getListaEstofados("../BDbin/BDPoltronas");

}

MEstoque::~MEstoque()
{

}

MEstoque& MEstoque::getMEstoque()
{
    static MEstoque mEstoque;
    return mEstoque;
}
void MEstoque::salvarEstoque()
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);

    string data = to_string(tm.tm_mday) + "-" + to_string(tm.tm_mon +1) + "-" + to_string(tm.tm_year +1900) + "_"+ to_string(tm.tm_hour) + "h" + to_string(tm.tm_min);
    string dataBin = data + ".dat";
    string dataCSV = data + ".csv";

    for (auto i = listaColchoes.begin(); i != listaColchoes.end(); i++){
        string BDcolcsv = "../BDcsv/BDColchoes_" + dataBin;
        string BDcolbin = "../BDbin/BDColchoes_" + dataCSV;
        cbin.gravar("../BDbin/BDColchoes.dat", (*i));
        ccsv.gravar("../BDcsv/BDColchoes.csv", (*i));
        cbin.gravar(&BDcolbin[0], (*i));
        ccsv.gravar(&BDcolbin[0], (*i));
    }
    for (auto i = listaBases.begin(); i != listaBases.end(); i++){
        string BDbascsv = "../BDcsv/BDBases_" + dataBin;
        string BDbasbin = "../BDbin/BDBases_" + dataCSV;
        cbin.gravar("../BDbin/BDBases.dat", (*i));
        ccsv.gravar("../BDcsv/BDBases.csv", (*i));
        cbin.gravar(&BDbasbin[0], (*i));
        ccsv.gravar(&BDbasbin[0], (*i));
    }
    for (auto i = listaSofas.begin(); i != listaSofas.end(); i++){
        string BDsofcsv = "../BDcsv/BDSofas_" + dataBin;
        string BDsofbin = "../BDbin/BDSofas_" + dataCSV;
        ebin.gravar("../BDbin/BDSofas.dat", (*i));
        ecsv.gravar("../BDcsv/BDSofas.csv", (*i));
        ebin.gravar(&BDsofbin[0], (*i));
        ecsv.gravar(&BDsofbin[0], (*i));
    }
    for (auto i = listaPuffs.begin(); i != listaPuffs.end(); i++){
        string BDpufcsv = "../BDcsv/BDPuffs_" + dataBin;
        string BDpufbin = "../BDbin/BDPuffs_" + dataCSV;
        ebin.gravar("../BDbin/BDPuffs.dat", (*i));
        ecsv.gravar("../BDcsv/BDPuffs.csv", (*i));
        ebin.gravar(&BDpufbin[0], (*i));
        ecsv.gravar(&BDpufbin[0], (*i));
    }
    for (auto i = listaPoltronas.begin(); i != listaPoltronas.end(); i++){
        string BDpolcsv = "../BDcsv/BDPoltronas_" + dataBin;
        string BDpolbin = "../BDbin/BDPoltronas_" + dataCSV;
        ebin.gravar("../BDbin/BDPoltronas.dat", (*i));
        ecsv.gravar("../BDcsv/BDPoltronas.csv", (*i));
        ebin.gravar(&BDpolbin[0], (*i));
        ecsv.gravar(&BDpolbin[0], (*i));
    }

}

bool MEstoque::setColchao(MColchao* colchao)
{
    if (colchao != NULL){
        listaColchoes.push_back(colchao);
        return true;
    }
    return false;
}

bool MEstoque::setBase(MColchao* base)
{
    if (base != NULL){
        listaBases.push_back(base);
        return true;
    }
    return false;
}

bool MEstoque::setSofa(MEstofado* sofa)
{
    if (sofa != NULL){
        listaSofas.push_back(sofa);
        return true;
    }
    return false;
}

bool MEstoque::setPoltrona(MEstofado* poltrona)
{
    if (poltrona != NULL){
        listaSofas.push_back(poltrona);
        return true;
    }
    return false;
}

bool MEstoque::setPuff(MEstofado* puff)
{
    if (puff != NULL){
        listaPuffs.push_back(puff);
        return true;
    }
    return false;
}

bool MEstoque::removerColchao(MColchao* colchao)
{
    if (colchao != NULL){
        listaColchoes.remove(colchao);
        return true;
    }
    return false;
}

bool MEstoque::removerBase(MColchao* base)
{
    if (base != NULL){
        listaBases.remove(base);
        return true;
    }
    return false;
}

bool MEstoque::removerSofa(MEstofado* sofa)
{
    if (sofa != NULL){
        listaSofas.remove(sofa);
        return true;
    }
    return false;
}

bool MEstoque::removerPoltrona(MEstofado* poltrona)
{
    if (poltrona != NULL){
        listaSofas.remove(poltrona);
        return true;
    }
    return false;
}

bool MEstoque::removerPuff(MEstofado* puff)
{
    if (puff != NULL){
        listaPuffs.remove(puff);
        return true;
    }
    return false;
}

list<MColchao*> MEstoque::getListaColchoes()
{
    return listaColchoes;
}

list<MColchao*> MEstoque::getListaBases()
{
    return listaBases;
}

list<MEstofado*> MEstoque::getListaSofas()
{
    return listaSofas;
}

list<MEstofado*> MEstoque::getListaPoltronas()
{
    return listaPoltronas;
}

list<MEstofado*> MEstoque::getListaPuffs()
{
    return listaPuffs;
}
