//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CODIGO_H
#define GERENCIADOR_HOTEL_UNB_CODIGO_H

#include <iostream>
#include <string>

using namespace std;

class Codigo
{
private:
    string valor;

    void validar(string codigo); // Metodo de validacao

public:
    Codigo() = default;

    explicit Codigo(const string& codigo)
    {
        setValor(codigo);
    };

    void setValor(const string& codigo)
    {
        validar(codigo);
        this->valor = codigo;
    }

    string getValor() const
    {
        return valor;
    }
};

#endif //GERENCIADOR_HOTEL_UNB_CODIGO_H