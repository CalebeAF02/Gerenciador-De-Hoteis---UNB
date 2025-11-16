//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SENHA_H
#define GERENCIADOR_HOTEL_UNB_SENHA_H

#include <iostream>
#include <string>

using namespace std;
namespace Hotelaria {
    class Senha {
    private:
        string senhaStr;

        void validar(string valor); // Metodo de validacao

    public:
        Senha() = default;

        explicit Senha(const string &valor) {
            setValor(valor);
        };

        void setValor(const string &valor) {
            validar(valor);
            this->senhaStr = valor;
        }

        string getValor() const;
    };

    inline string Senha::getValor() const {
        return senhaStr;
    }
}


#endif //GERENCIADOR_HOTEL_UNB_SENHA_H