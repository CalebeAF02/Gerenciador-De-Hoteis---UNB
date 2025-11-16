//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_ENDERECO_H
#define GERENCIADOR_HOTEL_UNB_ENDERECO_H

#include <iostream>
#include <string>

using namespace std;
namespace Hotelaria {
    class Endereco {
    private:
        string enderecoStr;

        void validar(string valor); // Metodo de validacao

    public:
        Endereco() = default;

        explicit Endereco(const string &valor) {
            setValor(valor);
        };

        void setValor(const string &valor) {
            validar(valor);
            this->enderecoStr = valor;
        }

        string getValor() const {
            return enderecoStr;
        }
    };
}

#endif //GERENCIADOR_HOTEL_UNB_ENDERECO_H