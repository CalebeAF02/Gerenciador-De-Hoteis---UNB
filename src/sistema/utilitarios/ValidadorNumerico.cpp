//
// Created by caleb on 09/11/2025.
//

#include "../../../include/sistema/utilitarios/ValidadorNumerico.hpp"

bool ValidadorNumerico::verificaSeENumero(const string &str) {
    // passa por cada caracter, e verifica se a string e um numero

    if (str.empty()) {
        return false;
    }
    for (char c: str) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}