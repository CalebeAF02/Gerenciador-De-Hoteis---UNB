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
    string valor;

    void validar(string valor);

public:
    Telefone() = default;

    explicit Telefone(const string &telefone) {
        setValor(telefone);
    }

    void setValor(const string &telefone) {
        validar(telefone);
        this->valor = telefone;
    }

    string getValor() const {
        return valor;
    }
};

#endif //GERENCIADOR_HOTEL_UNB_TELEFONE_H