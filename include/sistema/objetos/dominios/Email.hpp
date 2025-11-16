//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_EMAIL_H
#define GERENCIADOR_HOTEL_UNB_EMAIL_H

#include "iostream"
#include <string>

using namespace std;
namespace Hotelaria {
    class Email {
    private:
        string emailStr;

        void validar(const string &valor);

    public:
        Email() = default;

        explicit Email(const string &valor) {
            setValor(valor);
        }

        void setValor(const string &valor) {
            validar(valor);
            this->emailStr = valor;
        }

        string getValor() const;
    };

    inline string Email::getValor() const {
        return emailStr;
    }
}

#endif //GERENCIADOR_HOTEL_UNB_EMAIL_H