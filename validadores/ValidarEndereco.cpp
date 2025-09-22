//
// Created by caleb on 19/09/2025.
//

#include "../validadores/ValidarEndereco.h"

#include <string>

using namespace std;

void ValidarEndereco::validar(string endereco) {
    throw invalid_argument("Erro: Endereco invalido");
};