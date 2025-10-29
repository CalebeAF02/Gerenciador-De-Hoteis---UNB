//
// Created by caleb on 01/10/2025.
//

#include "Cartao.h"

void Cartao::validar(const string valor)
{
    if (valor.length() != 16)
    {
        throw invalid_argument("Erro: Tamanho invalido");
    } // implementar algoritimo de lunn
}