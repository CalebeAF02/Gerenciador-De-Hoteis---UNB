//
// Created by caleb on 01/10/2025.
//

#include "Cartao.hpp"
namespace Hotelaria {
    void Cartao::validar(const string valor) {
        if (valor.length() != 16) {
            throw invalid_argument("Erro: Tamanho invalido");
        } // implementar algoritimo de lunn
    }
}