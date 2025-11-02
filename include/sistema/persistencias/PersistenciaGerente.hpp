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
    bool inserirAoBD(Gerente &gerente);

    vector<Gerente *> listarBD();

    bool autenticarGerentePeloBD(const string &email, const string &senha);

    bool atualizarGerenteNoBD(const Gerente &gerente);

    static bool excluirPorEmailDoBD(Gerente *gerenteLogado);
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
