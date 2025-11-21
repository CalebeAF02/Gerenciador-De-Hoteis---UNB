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

        explicit Email(const string &valor);

        void setValor(const string &valor);

        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_EMAIL_H