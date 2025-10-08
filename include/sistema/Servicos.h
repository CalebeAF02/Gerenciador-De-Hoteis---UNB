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
    // Metodos CRUD -> CRIAR, LER, EDITAR, DELETAR  (ARMAZENAR DADOS GERENTE)
    void criarGerente();

    vector<Gerente> lerGerentes();

    void armazenarGerentes(vector<Gerente> gerentes);

    // deletarGerente

    // Metodos Programados de Login
    void loginGerente();

    bool getGerenteEstaLogado();

    bool fazerLogin(string copiaLogin, string senhaLogin);

    // Metodos de Servicos
    void exibirCentralDeServicos();

    void sairDosServicos();

};

inline bool Servicos::getGerenteEstaLogado()
{
    return gerenteEstaLogado;
};
#endif