//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_EMAIL_H
#define GERENCIADOR_HOTEL_UNB_EMAIL_H

#include "iostream"
#include <string>

using namespace std;

class Email
{
private:
    string valor;

    void validar(const string& email);

public:
    Email() = default;

    explicit Email(const string& email)
    {
        setValor(email);
    }

    void setValor(const string& email)
    {
        validar(email);
        this->valor = email;
    }

    string getValor() const;
};

inline string Email::getValor() const
{
    return valor;
}


#endif //GERENCIADOR_HOTEL_UNB_EMAIL_H