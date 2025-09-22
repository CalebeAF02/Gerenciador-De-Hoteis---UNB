//
// Created by caleb on 19/09/2025.
//

#include "../validadores/ValidarRamal.h"

using namespace std;

void ValidarRamal::validar(int ramal) {
    if (ramal < 0 || ramal > 50) {
        throw invalid_argument("Erro: Ramal invalido");
    }
};