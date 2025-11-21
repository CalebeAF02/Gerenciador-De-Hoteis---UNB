//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_DINHEIRO_H
#define GERENCIADOR_HOTEL_UNB_DINHEIRO_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    class Dinheiro {
    private:
        int dinheiro;

        void validar(int valor);

    public:
        Dinheiro() = default;

        explicit Dinheiro(const int &valor);

        void setValor(int valor);

        int getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_DINHEIRO_H