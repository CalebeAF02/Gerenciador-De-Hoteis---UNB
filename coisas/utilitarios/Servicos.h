#ifndef UTILITARIOS_SERVICOS_INCLUDE
#define UTILITARIOS_SERVICOS_INCLUDE

#include "../dominios/Gerente.h"
#include "TextoApresentacao.h"

#include "Gerente.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Servicos
{
public:
    void criarGerente();

    vector<Gerente> lerGerentes();

    void armazenarGerentes(vector<Gerente> gerentes);
};

#endif