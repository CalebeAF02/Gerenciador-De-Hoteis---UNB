//
// Created by caleb on 01/10/2025.
//

#include "../../include/dominios/Capacidade.h"

void Capacidade::validar(const int valor)
{
    if (valor < 1 || valor > 4)
    {
        throw invalid_argument("Erro: Capacidade invalida! Digite um valor entre 1 e 4");
    }
    else
    {
        //cou << "Senha: Valida! " << endl;
    }
};