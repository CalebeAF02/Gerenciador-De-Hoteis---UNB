//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_ENDERECO_H
#define GERENCIADOR_HOTEL_UNB_ENDERECO_H

#include <iostream>
#include <string>

using namespace std;

class Endereco {
private:
    string valor;

    void validar(string endereco); // Metodo de validacao

public:
    Endereco() = default;

    explicit Endereco(const string &endereco) {
        setValor(endereco);
    };

    void setValor(const string &endereco) {
        validar(endereco);
        this->valor = endereco;
    }

    string getValor() const {
        return valor;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_ENDERECO_H