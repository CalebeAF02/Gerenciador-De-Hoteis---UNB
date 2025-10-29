//
// Created by caleb on 01/10/2025.
//

#include "Telefone.h"


void Telefone::validar(const string valor)
{
    string ddi = "";
    string ddd = "";
    string numero = "";
    if (valor.length() != 14)
    {
        throw invalid_argument("Erro: Sem caracteres suficientes ou acima do esperado ");
    }
    for (int i = 0; i < valor.length(); i++)
    {
        if (i == 0)
        {
            if (valor[i] != '+')
            {
                throw invalid_argument("Erro: Caracter nao e caracter unico de ddi '+'");
            }
        }
        if (valor[i] < 1 || valor[i] > 9)
        {
            if (i < 3)
            {
                ddi += valor[i];
            }
            else if (i < 5)
            {
                ddd += valor[i];
            }
            else if (i < valor.length())
            {
                numero += valor[i];
            }
        }
        else
        {
            throw invalid_argument("Erro: Caracter nao e numero");
        }
    }
};