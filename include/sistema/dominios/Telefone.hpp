//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_TELEFONE_H
#define GERENCIADOR_HOTEL_UNB_TELEFONE_H

#include "iostream"
#include <string>

using namespace std;

class Telefone {
private:
    string telefoneStr;

    void validar(string valor);

public:
    Telefone() = default;

    explicit Telefone(const string &valor) {
        setValor(valor);
    }

    void setValor(const string &valor) {
        validar(valor);
        this->telefoneStr = valor;
    }

    string getValor() const {
        return telefoneStr;
    }
};

#endif //GERENCIADOR_HOTEL_UNB_TELEFONE_H