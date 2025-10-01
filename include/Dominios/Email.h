//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_EMAIL_H
#define GERENCIADOR_HOTEL_UNB_EMAIL_H


#include "iostream"

using namespace std;

class Email
{
private:
    string valor;

    void validar(const string& email)
    {
    }

public:
    Email(string valor)
    {
        validar(valor);
        this->valor = valor;
    }

    string getValor() const
    {
        return valor;
    }
};


#endif //GERENCIADOR_HOTEL_UNB_EMAIL_H