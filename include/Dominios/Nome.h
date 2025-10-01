//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NOME_H
#define GERENCIADOR_HOTEL_UNB_NOME_H

#include "iostream"

using namespace std;

class Nome
{
private:
    string valor;

    void validar(const string& nome);

public:
    Nome() : valor(" :) ")
    {
    }

    Nome(const string& nome)
    {
        validar(nome);
        this->valor = nome;
    }

    string getValor() const
    {
        return valor;
    }
};
#endif //GERENCIADOR_HOTEL_UNB_NOME_H