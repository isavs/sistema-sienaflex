#include "MFuncionarios.h"
#include <time.h>
#include <cstdio>
MFuncionarios::MFuncionarios()
{
    listaFuncionarios =  fcsv.getListaFuncionarios("BDFuncionarios.csv");

}

MFuncionarios::~MFuncionarios()
{

}

MFuncionarios& MFuncionarios::getMFuncionarios()
{
    static MFuncionarios mFuncionarios;
    return mFuncionarios;
}

bool MFuncionarios::setFuncionario(MFuncionario* funcionario)
{
    if (funcionario != NULL){
        listaFuncionarios.push_back(funcionario);
        return true;
    }
    return false;
}

bool MFuncionarios::removeFuncionario(MFuncionario* funcionario)
{
    if (funcionario != NULL){
        listaFuncionarios.remove(funcionario);
        return true;
    }
    return false;
}

list<MFuncionario*> MFuncionarios::getListaFuncionarios()
{
    return listaFuncionarios;
}

void MFuncionarios::salvarFuncionarios()
{
    time_t myTime;
    myTime = time(NULL);
    struct tm tm = *localtime(&myTime);

    string data ="BDFuncionarios_" + to_string(tm.tm_mday) + "-" + to_string(tm.tm_mon +1) + "-" + to_string(tm.tm_year +1900) + "_"+ to_string(tm.tm_hour) + "h" + to_string(tm.tm_min);
    string dataBin = data + ".dat";
    string dataCSV = data + ".csv";

    for (auto i = listaFuncionarios.begin(); i != listaFuncionarios.end(); i++){
        remove("BDFuncionarios.dat");
        fbin.gravar("BDFuncionarios.dat", (*i));
        remove("BDFuncionarios.csv");
        fcsv.gravar("BDFuncionarios.csv", (*i));
        fbin.gravar(&dataBin[0], (*i));
        fcsv.gravar(&dataCSV[0], (*i));

    }
}
