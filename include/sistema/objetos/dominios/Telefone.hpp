//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_TELEFONE_H
#define GERENCIADOR_HOTEL_UNB_TELEFONE_H

#include "iostream"
#include <string>

using namespace std;

namespace Hotelaria {
    class Telefone {
    private:
        string telefoneStr;

        void validar(string valor);

    public:
        Telefone() = default;

        explicit Telefone(const string &valor);

        void setValor(const string &valor);

        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_TELEFONE_H