#ifndef DATA_INCLUDE
#define DATA_INCLUDE

#include <sstream>
#include <string>
#include <stdexcept>
#include "validadores_principais/ValidarInt.h"

using namespace std;

class Data : ValidarInt, exception
{
private:
    static const int TIPO_DIA = 1;
    static const int TIPO_MES = 2;
    static const int TIPO_ANO = 3;

public:
    int dia;
    int mes;
    int ano;

    static int const JAN = 1;
    static int const FEV = 2;
    static int const MAR = 3;
    static int const ABR = 4;
    static int const MAI = 5;
    static int const JUN = 6;
    static int const JUL = 7;
    static int const AGO = 8;
    static int const SET = 9;
    static int const OUT = 10;
    static int const NOV = 11;
    static int const DEZ = 12;

    void validar(int tipo, int valor) override;

    //Construtores
    Data() = default;

    explicit Data(const string& dataStr)
    {
        int d, m, a;
        char sepMes, sepAno;
        istringstream sepDia(dataStr);

        sepDia >> d >> sepMes >> m >> sepAno >> a;

        if (sepDia.fail() || sepMes != '/' || sepAno != '/')
        {
            throw invalid_argument("Formato de data invalido. Use DD/MM/AAAA.");
        }

        setData(d, m, a); // valida e seta
    }

    // Metodo de Impressao
    string toString()
    {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }

    //metodo Setar - Entrada
    void setData(int d, int m, int a)
    {
        validar(TIPO_DIA, d);
        validar(TIPO_MES, m);
        validar(TIPO_ANO, a);

        this->dia = d;
        this->mes = m;
        this->ano = a;
    };

    //metodos get - Saida
    int getDia();

    int getMes();

    int getAno();
};

inline int Data::getDia()
{
    return dia;
}

inline int Data::getMes()
{
    return mes;
}

inline int Data::getAno()
{
    return ano;
}
#endif