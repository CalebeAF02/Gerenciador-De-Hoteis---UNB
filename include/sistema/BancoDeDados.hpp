//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_BANCODEDADOS_H
#define GERENCIADOR_DE_HOTEIS_UNB_BANCODEDADOS_H

#include "sqlite3.h"
#include <iostream>

using namespace std;

class BancoDeDados {
private:
    sqlite3 *db = nullptr;

public:
    sqlite3 *getConexao() const {
        return db;
    }

    bool abrindoConexao();

    bool fechandoConexao();

    void criandoBancoDeDados();

    void criarTabelaGerentes(sqlite3 *db);

    void criarTabelaHospedes(sqlite3 *db);

    void criarTabelaHoteis(sqlite3 *db);

    void criarTabelaQuartos(sqlite3 *db);

    void criarTabelaReservas(sqlite3 *db);

    void criarTabelaSolicitacoesHospedagem(sqlite3 *db);
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_BANCODEDADOS_H
