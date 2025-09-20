//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_DATA_H
#define CODIGOS_CLION_TP1_IML_DATA_H

#include <string>
#include <stdexcept>
#include "validadores/ValidarInt.h"

using namespace std;

class Data : ValidarInt, exception {
private:
    static const int TIPO_DIA = 1;
    static const int TIPO_MES = 2;
    static const int TIPO_ANO = 3;

public:
    int dia;
    int mes;
    int ano;

    void validar(int tipo, int valor) override;

    //Construtor
    Data() = default;

    // Metodo de Impressao
    string toString() {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }

    //metodo Setar - Entrada
    void setData(int d, int m, int a) {
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

inline int Data::getDia() {
    return dia;
}

inline int Data::getMes() {
    return mes;
}

inline int Data::getAno() {
    return ano;
}
#endif //CODIGOS_CLION_TP1_IML_DATA_H
