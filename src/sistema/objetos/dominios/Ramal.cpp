//
// Created by caleb on 01/10/2025.
//

#include "Ramal.hpp"

void Ramal::validar(const string &ramal) {
    // 1. TAMANHO
    if (ramal.length() != 2) {
        throw invalid_argument("Erro: Ramal invalido. Deve ter 2 digitos (00-50).");
    }

    // 2. CONTEÚDO (APENAS DÍGITOS)
    if (!isdigit(ramal[0]) || !isdigit(ramal[1])) {
        throw invalid_argument("Erro: Ramal deve conter apenas digitos.");
    }

    // 3. RANGE (00 a 50)
    int ral = stoi(ramal);
    if (ral < 0 || ral > 50) {
        throw invalid_argument("Erro: Ramal fora do range permitido (00 a 50).");
    }

    // Se passou por tudo, é válido (não lança exceção)
};