#include "../validadoresAbstratos/ValidarCodigo.h"

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

void ValidarCodigo::validar(const string codigo)
{
    int cont_baixo = 0;
    int cont_num = 0;
    if (codigo.length() == 10)
    {
        for (int i = 0; i < codigo.length(); i++)
        {
            if (islower(codigo[i]))
            {
                cont_baixo += 1;
            }
            else if (isdigit(codigo[i]))
            {
                cont_num += 1;
            }
            else
            {
                throw invalid_argument("Erro: Caracter invalido");
            }
        }
    }
    else
    {
        throw invalid_argument("Erro: Quantidade de caracteres invalida. Quantidade: 10 ");
    }
};