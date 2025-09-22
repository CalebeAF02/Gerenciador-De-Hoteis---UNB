//
// Created by caleb on 21/09/2025.
//

#include "ValidarDinheiro.h"

using namespace std;

void ValidarDinheiro::validar(int valor) {
    if (valor == 800) {
        // tipo 1 de quarto
    } else if (valor == 1200) {
        // tipo 2 de quarto
    }  else if (valor<=0 || valor>=1000000) {
        // tipo 2 de quarto
    }else {
        throw invalid_argument("Erro: Valor invalido! Digite o valor R$ 800 ou R$ 1200 !");
    }
};
