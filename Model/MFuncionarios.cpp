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
    //NO LINUX: //string dataBin = "../BDbin/" + data + ".dat";
    string dataBin = data + ".dat";
    //NO LINUX: // string dataCSV = "../BDcsv/" + data + ".csv";
    string dataCSV = data + ".csv";
   
    for (auto i = listaFuncionarios.begin(); i != listaFuncionarios.end(); i++){
        //NO LINUX: //fbin.gravar("../BDbin/BDFuncionarios.dat", (*i));
        remove("BDFuncionarios.dat");
        fbin.gravar("BDFuncionarios.dat", (*i));
        //NO LINUX: // fcsv.gravar("../BDcsv/BDFuncionarios.csv", (*i));
        remove("BDFuncionarios.csv");
        fcsv.gravar("BDFuncionarios.csv", (*i));
        fbin.gravar(&dataBin[0], (*i));
        fcsv.gravar(&dataCSV[0], (*i));

    }
}
