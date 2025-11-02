//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NUMERO_H
#define GERENCIADOR_HOTEL_UNB_NUMERO_H

#include <iostream>
#include <string>

using namespace std;

class Numero
{
private:
    string valor;

    void validar(string valor); // Metodo de validacao

public:
    Numero() = default;

    explicit Numero(const string& numero)
    {
        setValor(numero);
    };

    void setValor(const string& numero)
    {
        validar(numero);
        this->valor = numero;
    }

    string getValor() const
    {
        return valor;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_NUMERO_H
