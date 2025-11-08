//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include <vector>

#include "Gerente.hpp"
#include "BancoDeDados.hpp"
#include "sqlite3.h"

using namespace std;

class PersistenciaGerente {
public:
    bool inserir(Gerente &gerente);

    vector<Gerente *> listar();

    bool atualizar(const Gerente &gerente);

    static bool excluirPorEmail(Gerente *gerenteLogado);

    bool autenticarGerente(const string &email, const string &senha);
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H