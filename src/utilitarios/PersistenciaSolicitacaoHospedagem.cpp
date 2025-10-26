//
// Created by caleb on 26/10/2025.
//

#include "../../include/utilitarios/PersistenciaSolicitacaoHospedagem.h"
#include <sqlite3.h>
#include <iostream>

#include "SolicitacaoHospedagem.h"

static const char* DB_PATH = "sistema_hotel.db";

void PersistenciaSolicitacaoHospedagem::inicializar()
{
    sqlite3* db;
    char* erroMsg = nullptr;

    if (sqlite3_open(DB_PATH, &db) != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS solicitacoes_hospedagem (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            codigo TEXT NOT NULL UNIQUE,
            email_hospede TEXT NOT NULL,
            id_hotel TEXT NOT NULL,
            id_quarto TEXT NOT NULL,
            chegada TEXT NOT NULL,
            partida TEXT NOT NULL,
            status INTEGER NOT NULL,
            motivo_recusa TEXT
        );
    )";

    if (sqlite3_exec(db, sql, nullptr, nullptr, &erroMsg) != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela: " << erroMsg << std::endl;
        sqlite3_free(erroMsg);
    }

    sqlite3_close(db);
}

void PersistenciaSolicitacaoHospedagem::salvar(const SolicitacaoHospedagem& s)
{
    sqlite3* db;
    sqlite3_open(DB_PATH, &db);

    const char* sql = R"(
        INSERT INTO solicitacoes_hospedagem (
            codigo, email_hospede, id_hotel, id_quarto,
            chegada, partida, status, motivo_recusa
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?);
    )";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, s.getCodigo().getValor().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, s.getHospedeId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, s.getHotelId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, s.getQuartoId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, s.getChegada().toString().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, s.getPartida().toString().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, s.getStatus());
    sqlite3_bind_text(stmt, 8, s.getMotivoRecusa().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

std::vector<SolicitacaoHospedagem> PersistenciaSolicitacaoHospedagem::buscarPorEmail(const std::string& email)
{
    sqlite3* db;
    sqlite3_open(DB_PATH, &db);

    const char* sql = R"(
        SELECT codigo, id_hotel, id_quarto, chegada, partida, status, motivo_recusa
        FROM solicitacoes_hospedagem
        WHERE email_hospede = ?;
    )";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    std::vector<SolicitacaoHospedagem> lista;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string codigo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string hotelId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string quartoId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string chegadaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string partidaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        int status = sqlite3_column_int(stmt, 5);
        std::string motivo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

        lista.emplace_back(
            Codigo(codigo),
            email,
            hotelId,
            quartoId,
            Data(chegadaStr),
            Data(partidaStr),
            status,
            motivo
        );
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return lista;
}

std::vector<SolicitacaoHospedagem> PersistenciaSolicitacaoHospedagem::buscarPorStatus(int statusFiltro)
{
    sqlite3* db;
    sqlite3_open(DB_PATH, &db);

    const char* sql = R"(
        SELECT codigo, email_hospede, id_hotel, id_quarto, chegada, partida, status, motivo_recusa
        FROM solicitacoes_hospedagem
        WHERE status = ?;
    )";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, statusFiltro);

    std::vector<SolicitacaoHospedagem> lista;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string codigo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string hotelId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string quartoId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string chegadaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string partidaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        int status = sqlite3_column_int(stmt, 6);
        std::string motivo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

        lista.emplace_back(
            Codigo(codigo),
            email,
            hotelId,
            quartoId,
            Data(chegadaStr),
            Data(partidaStr),
            status,
            motivo
        );
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return lista;
}

void PersistenciaSolicitacaoHospedagem::atualizar(const SolicitacaoHospedagem& s)
{
    sqlite3* db;
    sqlite3_open(DB_PATH, &db);

    const char* sql = R"(
        UPDATE solicitacoes_hospedagem
        SET status = ?, motivo_recusa = ?
        WHERE codigo = ?;
    )";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, s.getStatus());
    sqlite3_bind_text(stmt, 2, s.getMotivoRecusa().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, s.getCodigo().getValor().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}