//
// Created by caleb on 01/10/2025.
//

#include "Ramal.h"

void Ramal::validar(const string& ramal)
{
    if (ramal.length() == 2)
    {
        if (isdigit(ramal[0]) && isdigit(ramal[1]))
        {
            int ral = stoi(ramal);
            if (ral >= 0 && ral <= 50)
            {
            }
            else
            {
                throw invalid_argument("Erro: Caracter em ramal invalido");
            }
        }
        else
        {
            throw invalid_argument("Erro: Caracter em ramal invalido");
        }
    }
    else
    {
        throw invalid_argument("Erro: Ramal invalido. Valor entre 00 e 50.");
    }
};