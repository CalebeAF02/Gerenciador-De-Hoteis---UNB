//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CARTAO_H
#define GERENCIADOR_HOTEL_UNB_CARTAO_H

#include "iostream"
#include <string>

using namespace std;

namespace Hotelaria {
    class Cartao {
    private:
        string cartaoStr;

        void validar(string valor);

    public:
        Cartao() = default;

        explicit Cartao(const string &valor);

        void setValor(const string &valor);

        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_CARTAO_H