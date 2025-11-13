//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CODIGO_H
#define GERENCIADOR_HOTEL_UNB_CODIGO_H

#include <iostream>
#include <string>

using namespace std;

class Codigo {
private:
    string codigoStr;

    void validar(string valor); // Metodo de validacao

public:
    Codigo() = default;

    explicit Codigo(const string &valor) {
        setValor(valor);
    };

    void setValor(const string &valor) {
        validar(valor);
        this->codigoStr = valor;
    }

    string getValor() const {
        return codigoStr;
    }
};

#endif //GERENCIADOR_HOTEL_UNB_CODIGO_H