#ifndef UTILITARIOS_SERVICOS_INCLUDE
#define UTILITARIOS_SERVICOS_INCLUDE

#include "Gerente.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Servicos
{
private:
    bool gerenteEstaLogado = false;
    Gerente gerenteLogado;

public:
    void criarGerente();

    vector<Gerente> lerGerentes();

    void armazenarGerentes(vector<Gerente> gerentes);

    void loginGerente();

    bool getGerenteEstaLogado();

    void exibirCentralDeServicos();

    void sairDosServicos();

    bool fazerLogin(string copiaLogin, string senhaLogin);
};

inline bool Servicos::getGerenteEstaLogado()
{
    return gerenteEstaLogado;
};
#endif