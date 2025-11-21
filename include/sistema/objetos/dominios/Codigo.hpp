//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CODIGO_H
#define GERENCIADOR_HOTEL_UNB_CODIGO_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    class Codigo {
    private:
        string codigoStr;

        void validar(string valor);

    public:
        Codigo() = default;

        explicit Codigo(const string &valor);

        void setValor(const string &valor);

        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_CODIGO_H