//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_DINHEIRO_H
#define GERENCIADOR_HOTEL_UNB_DINHEIRO_H

#include <iostream>
#include <string>

using namespace std;

class Dinheiro {
private:
    int valor;

    void validar(int dinheiroInt); // Metodo de validacao

public:
    Dinheiro() = default;

    explicit Dinheiro(const int &dinheiroInt) {
        setValor(dinheiroInt);
    };

    void setValor(int dinheiroInt) {
        validar(dinheiroInt);
        this->valor = dinheiroInt;
    }

    int getValor() const {
        return valor;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_DINHEIRO_H