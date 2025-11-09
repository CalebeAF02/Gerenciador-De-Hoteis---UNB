//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include <vector>
#include <optional>
#include "Gerente.hpp"
#include "GerenteDTO.hpp"
#include "BancoDeDados.hpp"
#include "sqlite3.h"

using namespace std;

class PersistenciaGerente {
public:
    bool inserir(Gerente &gerente);

    vector<GerenteDTO *> listar();

    bool atualizar(int id, const Gerente &gerente);

    static bool excluirPorEmail(Gerente *gerenteLogado);

    bool autenticarGerente(const string &email, const string &senha);

    optional<GerenteDTO> buscaGerentePorID(int id);

};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H