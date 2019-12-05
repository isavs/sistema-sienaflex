#include "MFuncionario.h"

class MGerente: public MFuncionario
{
private:
    double bonus;

public:
    MGerente();
    MGerente(int id, string nome);
    ~MGerente();
    void setId(int id);
    void setSalario(double salario);
    void setBonus(double bonus);
    const int getId();
    const double getSalario();
    const double getBonus();
};
