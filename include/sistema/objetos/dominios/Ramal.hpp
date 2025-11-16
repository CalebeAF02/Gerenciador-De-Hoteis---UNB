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

        void validar(const string &valor); // Metodo de validacao

    public:
        Ramal() = default;

        explicit Ramal(const string &valor) {
            setValor(valor);
        };

        void setValor(const string &valor) {
            validar(valor);
            this->ramalStr = valor;
        }

        string getValor() const;
    };

    inline string Ramal::getValor() const {
        return ramalStr;
    }
}

#endif //GERENCIADOR_HOTEL_UNB_RAMAL_H