//
// Created by caleb on 01/10/2025.
//

#include "Dinheiro.hpp"


void Dinheiro::validar(const int valor) {
    if (!(valor > 0 && valor <= 100000000)) {
        throw invalid_argument("Erro: Valor da diaria invalido. Valorres: Quarto1= R$800,00 e Quarto2= R$1.200,00 !");
    }
}