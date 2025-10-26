//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_RAMAL_H
#define GERENCIADOR_HOTEL_UNB_RAMAL_H

#include <iostream>
#include <string>

using namespace std;

class Ramal
{
private:
    string valor;

    void validar(const string& ramal); // Metodo de validacao

public:
    Ramal() = default;

    explicit Ramal(const string& ramal)
    {
        setValor(ramal);
    };

    void setValor(const string& ramal)
    {
        validar(ramal);
        this->valor = ramal;
    }

    string getValor() const;
};

inline string Ramal::getValor() const
{
    return valor;
}
#endif //GERENCIADOR_HOTEL_UNB_RAMAL_H