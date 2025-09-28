#include "../validadoresAbstratos/ValidarRamal.h"

#include <iostream>
#include <ostream>

using namespace std;

void ValidarRamal::validar(const string ramal)
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