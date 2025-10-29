//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CARTAO_H
#define GERENCIADOR_HOTEL_UNB_CARTAO_H

#include "iostream"
#include <string>

using namespace std;

class Cartao
{
private:
    string valor;

    void validar(string valor);

public:
    Cartao() = default;

    explicit Cartao(const string& cartao)
    {
        setValor(cartao);
    }

    void setValor(const string& cartao)
    {
        validar(cartao);
        this->valor = cartao;
    }

    string getValor() const
    {
        return valor;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_CARTAO_H