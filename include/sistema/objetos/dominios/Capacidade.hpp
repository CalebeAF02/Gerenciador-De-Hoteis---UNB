//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CAPACIDADE_H
#define GERENCIADOR_HOTEL_UNB_CAPACIDADE_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    class Capacidade {
    private:
        int capacidadeInt;

        void validar(int valor);

    public:
        Capacidade() = default;

        explicit Capacidade(const int &valor);

        void setValor(const int &valor);

        int getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_CAPACIDADE_H