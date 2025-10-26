//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CAPACIDADE_H
#define GERENCIADOR_HOTEL_UNB_CAPACIDADE_H

#include <iostream>
#include <string>

using namespace std;

class Capacidade
{
private:
    int valor;

    void validar(int valor); // Metodo de validacao

public:
    Capacidade() = default;

    explicit Capacidade(const int& capacidade)
    {
        setValor(capacidade);
    };

    void setValor(const int& capacidade)
    {
        validar(capacidade);
        this->valor = capacidade;
    }

    int getValor() const
    {
        return valor;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_CAPACIDADE_H