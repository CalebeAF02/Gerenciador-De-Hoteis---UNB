//
// Created by caleb on 01/10/2025.
//

#include "Telefone.hpp"


void Telefone::validar(const string valor) {
    string ddi = "";
    string ddd = "";
    string numero = "";
    if (valor.length() != 15) {
        throw invalid_argument("Erro: Sem caracteres suficientes ou acima do esperado.");
    }
    for (int i = 0; i < valor.length(); i++) {
        if (i == 0) {
            if (valor[i] != '+') {
                throw invalid_argument("Erro: Caracter nao e caracter unico de ddi '+'.");
            }
        }
        if (i <= 2) {
            ddi += valor[i];
        } else if (i <= 4) {
            ddd += valor[i];
        } else if (i <= valor.length()) {
            numero += valor[i];
        } else {
            throw invalid_argument("Erro: Caracter nao e numero");
        }
    }
    if (ddi[0] != '+') {
        throw invalid_argument("Erro: Primeiro caracter invalido. Esperado '+'.");
    }

    if (!(isdigit(ddi[1]) && isdigit(ddi[2]))) {
        throw invalid_argument("Erro: DDD invalido");
    }

    if (!(isdigit(ddd[0]) && isdigit(ddd[1]))) {
        throw invalid_argument("Erro: DDD invalido");
    }
    if (numero.length() != 10) {
        throw invalid_argument("Erro: numero invalido");
    }
};