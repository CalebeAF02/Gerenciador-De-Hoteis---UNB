//
// Created by caleb on 01/10/2025.
//

#include "Cartao.hpp"

namespace Hotelaria {
    Cartao::Cartao(const string &valor) {
        setValor(valor);
    }

    void Cartao::setValor(const string &valor) {
        validar(valor);
        this->cartaoStr = valor;
    }

    string Cartao::getValor() const {
        return cartaoStr;
    }

    void Cartao::validar(const string valor) {
        if (valor.length() != 16) {
            throw invalid_argument("Erro: Tamanho invalido");
        }

        int soma = 0;
        bool dobrar = false;

        // Percorre da direita para a esquerda
        for (int i = valor.length() - 1; i >= 0; i--) {
            if (!isdigit(valor[i])) {
                throw invalid_argument("Erro: Cartao deve conter apenas dígitos");
            }

            int digito = valor[i] - '0';

            if (dobrar) {
                digito *= 2;
                if (digito > 9) digito -= 9;
            }

            soma += digito;
            dobrar = !dobrar; // alterna entre dobrar e não dobrar
        }

        if (soma % 10 != 0) {
            throw invalid_argument("Erro: Cartao invalido pelo algoritmo de Luhn");
        }
    }
}