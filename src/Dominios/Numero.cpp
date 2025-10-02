//
// Created by caleb on 01/10/2025.
//

#include "../../include/Dominios/Numero.h"


void Numero::validar(const string valor)
{
    if (valor.length() == 3)
    {
        if ((isdigit(valor[0]) || isdigit(valor[1]) || isdigit(valor[2])) == false)
        {
            throw invalid_argument("Erro: Numero invalido! Digite um valores do tipo numerico.");
        }
        else
        {
            if (valor[0] < '1' && valor[1] < '1' && valor[2] < '1')
            {
                throw invalid_argument("Erro: Digite um valor entre 001 e 999");
            }
        }
    }
    else
    {
        throw invalid_argument("Erro: Formato de Numero invalido! Digite um valor entre 001 e 999");
    }
};