//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_BANCODEDADOS_H
#define GERENCIADOR_DE_HOTEIS_UNB_BANCODEDADOS_H

#include "sqlite3.h"
#include <iostream>
#include "../../libs/io/IO.hpp"
#include "../../libs/formato/Formato.hpp"

using namespace std;

namespace Hotelaria {
    class BancoDeDados {
    private:
        sqlite3 *db = nullptr;

        void tabelaGerente(sqlite3 *db);

        void tabelaHospede(sqlite3 *db);

        void tabelaHotel(sqlite3 *db);

        void tabelaQuarto(sqlite3 *db);

        void tabelaReserva(sqlite3 *db);

        void tabelaSolicitacoesDeHospedagem(sqlite3 *db);

    public:
        sqlite3 *getConexao() const;

        bool abrindoConexao();

        bool fechandoConexao();

        void iniciar();
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_BANCODEDADOS_H