//
// Created by caleb on 28/09/2025.
//

#include "LinhaTSV.h"

void LinhaTSV::extrairAtributo(string valor, string& parte, string& parteResto)
{
    int posicaoTab = valor.find("\t");
    if (posicaoTab == string::npos)
    {
        throw invalid_argument("Erro: Dados invalida");
    }
    parte = valor.substr(0, posicaoTab);
    parteResto = valor.substr(posicaoTab + 1);
}

