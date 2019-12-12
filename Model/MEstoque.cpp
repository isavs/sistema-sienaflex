#include "MEstoque.h"
#include <time.h>

MEstoque::MEstoque()
{
    
    listaColchoes = ccsv.getListaColchoes("BDColchoes.csv");
    listaBases = ccsv.getListaColchoes("BDBases.csv");
    listaSofas = ecsv.getListaEstofados("BDSofas.csv");
    listaPuffs = ecsv.getListaEstofados("BDPuffs.csv");
    listaPoltronas = ecsv.getListaEstofados("BDPoltronas.csv");

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
        string BDcolcsv = "BDColchoes_" + dataCSV;
        string BDcolbin = "BDColchoes_" + dataBin;
        remove("BDColchoes.dat");
        remove("BDColchoes.csv");
        cbin.gravar("BDColchoes.dat", (*i));
        ccsv.gravar("BDColchoes.csv", (*i));
        cbin.gravar(&BDcolbin[0], (*i));
        ccsv.gravar(&BDcolcsv[0], (*i));
    }
    for (auto i = listaBases.begin(); i != listaBases.end(); i++){
        string BDbascsv = "BDBases_" + dataCSV;
        string BDbasbin = "BDBases_" + dataBin;
        remove("BDBases.dat");
        remove("BDBases.csv");
        cbin.gravar("BDBases.dat", (*i));
        ccsv.gravar("BDBases.csv", (*i));
        cbin.gravar(&BDbasbin[0], (*i));
        ccsv.gravar(&BDbascsv[0], (*i));
    }
    for (auto i = listaSofas.begin(); i != listaSofas.end(); i++){
        string BDsofcsv = "BDSofas_" + dataCSV;
        string BDsofbin = "BDSofas_" + dataBin;
        remove("BDSofas.dat");
        remove("BDSofas.csv");
        ebin.gravar("BDSofas.dat", (*i));
        ecsv.gravar("BDSofas.csv", (*i));
        ebin.gravar(&BDsofbin[0], (*i));
        ecsv.gravar(&BDsofcsv[0], (*i));
    }
    for (auto i = listaPuffs.begin(); i != listaPuffs.end(); i++){
        string BDpufcsv = "BDPuffs_" + dataCSV;
        string BDpufbin = "BDPuffs_" + dataBin;
        remove("BDPuffs.dat");
        remove("BDPuffs.csv");
        ebin.gravar("BDPuffs.dat", (*i));
        ecsv.gravar("BDPuffs.csv", (*i));
        ebin.gravar(&BDpufbin[0], (*i));
        ecsv.gravar(&BDpufcsv[0], (*i));
    }
    for (auto i = listaPoltronas.begin(); i != listaPoltronas.end(); i++){
        string BDpolcsv = "BDPoltronas_" + dataCSV;
        string BDpolbin = "BDPoltronas_" + dataBin;
        remove("BDPoltronas.dat");
        remove("BDPoltronas.csv");
        ebin.gravar("BDPoltronas.dat", (*i));
        ecsv.gravar("BDPoltronas.csv", (*i));
        ebin.gravar(&BDpolbin[0], (*i));
        ecsv.gravar(&BDpolcsv[0], (*i));
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
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);
    if (colchao != NULL){
        colchao->setDataSaida(tm.tm_mday, tm.tm_mon+1, tm.tm_yday+1900);
        ccsv.gravar("BDColchaoVendidos.csv", colchao);
        listaColchoes.remove(colchao);
        return true;
    }
    return false;
}

bool MEstoque::removerBase(MColchao* base)
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);
    if (base != NULL){
        base->setDataSaida(tm.tm_mday, tm.tm_mon+1, tm.tm_yday+1900);
        ccsv.gravar("BDColchaoVendidos.csv", base);
        listaBases.remove(base);
        return true;
    }
    return false;
}

bool MEstoque::removerSofa(MEstofado* sofa)
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);
    if (sofa != NULL){
        sofa->setDataSaida(tm.tm_mday, tm.tm_mon+1, tm.tm_yday+1900);
        ecsv.gravar("BDEstofadoVendidos.csv", sofa);
        listaSofas.remove(sofa);
        return true;
    }
    return false;
}

bool MEstoque::removerPoltrona(MEstofado* poltrona)
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);
    if (poltrona != NULL){
        poltrona->setDataSaida(tm.tm_mday, tm.tm_mon+1, tm.tm_yday+1900);
        ecsv.gravar("BDEstofadoVendidos.csv", poltrona);
        listaSofas.remove(poltrona);
        return true;
    }
    return false;
}

bool MEstoque::removerPuff(MEstofado* puff)
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);
    if (puff != NULL){
        puff->setDataSaida(tm.tm_mday, tm.tm_mon+1, tm.tm_yday+1900);
        ecsv.gravar("BDEstofadoVendidos.csv", puff);
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
