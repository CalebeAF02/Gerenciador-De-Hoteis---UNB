//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CAPACIDADE_H
#define GERENCIADOR_HOTEL_UNB_CAPACIDADE_H

#include <iostream>
#include <string>

using namespace std;

class Capacidade {
private:
    int capacidadeInt;

    void validar(int valor); // Metodo de validacao

public:
    Capacidade() = default;

    explicit Capacidade(const int &valor) {
        setValor(valor);
    };

    void setValor(const int &valor) {
        validar(valor);
        this->capacidadeInt = valor;
    }

    int getValor() const {
        return capacidadeInt;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_CAPACIDADE_H