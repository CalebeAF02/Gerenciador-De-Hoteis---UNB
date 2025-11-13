//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NUMERO_H
#define GERENCIADOR_HOTEL_UNB_NUMERO_H

#include <iostream>
#include <string>

using namespace std;

class Numero {
private:
    string numeroStr;

    void validar(string valor); // Metodo de validacao

public:
    Numero() = default;

    explicit Numero(const string &valor) {
        setValor(valor);
    };

    void setValor(const string &valor) {
        validar(valor);
        this->numeroStr = valor;
    }

    string getValor() const {
        return numeroStr;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_NUMERO_H