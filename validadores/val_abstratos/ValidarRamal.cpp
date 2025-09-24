//
// Created by caleb on 19/09/2025.
//

#include "ValidarRamal.h"

using namespace std;

void ValidarRamal::validar(const string ramal) {
    if (ramal.length() == 2) {
        if (isdigit(ramal[0]) && isdigit(ramal[1])) {
            if (ramal[0] >= '0' && ramal[0] <= '5') {
            } else {
                throw invalid_argument("Erro: Caracter em ramal invalido");
            }
        } else {
            throw invalid_argument("Erro: Caracter em ramal invalido");
        }
    } else {
        throw invalid_argument("Erro: Ramal invalido. Valor entre 00 e 50.");
    }
};