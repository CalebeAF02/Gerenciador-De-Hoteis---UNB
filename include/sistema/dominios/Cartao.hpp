//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CARTAO_H
#define GERENCIADOR_HOTEL_UNB_CARTAO_H

#include "iostream"
#include <string>

using namespace std;

class Cartao {
private:
    string cartaoStr;

    void validar(string valor);

public:
    Cartao() = default;

    explicit Cartao(const string &valor) {
        setValor(valor);
    }

    void setValor(const string &valor) {
        validar(valor);
        this->cartaoStr = valor;
    }

    string getValor() const {
        return cartaoStr;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_CARTAO_H