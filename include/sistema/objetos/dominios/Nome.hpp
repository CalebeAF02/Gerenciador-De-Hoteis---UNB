//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NOME_H
#define GERENCIADOR_HOTEL_UNB_NOME_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    class Nome {
    private:
        string nomeStr;

        void validar(const string &valor);

    public:
        Nome() = default;

        explicit Nome(const string &valor);

        void setValor(const string &valor);

        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_NOME_H