//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_RAMAL_H
#define GERENCIADOR_HOTEL_UNB_RAMAL_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    class Ramal {
    private:
        string ramalStr;

        void validar(const string &valor);

    public:
        Ramal() = default;

        explicit Ramal(const string &valor);

        void setValor(const string &valor);

        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_RAMAL_H