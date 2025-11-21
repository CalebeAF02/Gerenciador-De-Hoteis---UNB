//
// Created by caleb on 01/10/2025.
//

#include "Codigo.hpp"

namespace Hotelaria {
    Codigo::Codigo(const string &valor) {
        setValor(valor);
    };

    void Codigo::setValor(const string &valor) {
        validar(valor);
        this->codigoStr = valor;
    }

    string Codigo::getValor() const {
        return codigoStr;
    }

    void Codigo::validar(const string codigo) {
        int cont_baixo = 0;
        int cont_alto = 0;
        int cont_num = 0;
        if (codigo.length() == 10) {
            for (int i = 0; i < codigo.length(); i++) {
                if (islower(codigo[i])) {
                    cont_baixo += 1;
                } else if (isalpha(codigo[i])) {
                    cont_alto += 1;
                } else if (isdigit(codigo[i])) {
                    cont_num += 1;
                } else {
                    throw invalid_argument("Erro: Caracter invalido");
                }
            }
        } else {
            throw invalid_argument("Erro: Quantidade de caracteres invalida. Quantidade: 10 ");
        }
    };
}