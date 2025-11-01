//
// Created by caleb on 26/10/2025.
//

#include "../../../include/sistema/persistencias/PersistenciaSolicitacaoHospedagem.h"
#include <sqlite3.h>
#include <iostream>

#include "EnumConversor.h"
#include "HospedeGerenciavel.h"
#include "../../../include/sistema/entidades/SolicitacaoHospedagem.h"

static const char *DB_PATH = "hotel.db";

void PersistenciaSolicitacaoHospedagem::salvar(const SolicitacaoHospedagem &s) {
    BancoDeDados banco;

    if (!banco.abrindoConexao())
        return;

    sqlite3 *db = banco.getConexao();

    const char *sql = R"(
        INSERT INTO solicitacoes_hospedagem (
            email_hospede, id_hotel, id_quarto,
            chegada, partida, status, motivo_recusa
        ) VALUES (?, ?, ?, ?, ?, ?, ?);
    )";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, s.getHospedeId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, s.getHotelId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, s.getQuartoId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, s.getChegada().toString().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, s.getPartida().toString().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, EnumConversor::StatusSolicitacaoHospedagemParaInteiro(s.getStatus()));
    sqlite3_bind_text(stmt, 7, s.getMotivoRecusa().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    banco.fechandoConexao();
}

std::vector<SolicitacaoHospedagem> PersistenciaSolicitacaoHospedagem::buscarPorEmail(const std::string &email) {
    sqlite3 *db;
    sqlite3_open(DB_PATH, &db);

    const char *sql = R"(
        SELECT codigo, id_hotel, id_quarto, chegada, partida, status, motivo_recusa
        FROM solicitacoes_hospedagem
        WHERE email_hospede = ?;
    )";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    std::vector<SolicitacaoHospedagem> lista;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string codigo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        std::string hotelId = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string quartoId = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        std::string chegadaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
        std::string partidaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
        StatusSolicitacaoHospedagem status = EnumConversor::InteiroParaStatusSolicitacaoHospedagem(
            sqlite3_column_int(stmt, 5));
        std::string motivo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6));

        lista.emplace_back(
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

std::vector<SolicitacaoHospedagem> PersistenciaSolicitacaoHospedagem::buscarPorStatus(int statusFiltro) {
    sqlite3 *db;
    sqlite3_open(DB_PATH, &db);

    const char *sql = R"(
        SELECT codigo, email_hospede, id_hotel, id_quarto, chegada, partida, status, motivo_recusa
        FROM solicitacoes_hospedagem
        WHERE status = ?;
    )";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, statusFiltro);

    std::vector<SolicitacaoHospedagem> lista;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string codigo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string hotelId = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        std::string quartoId = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
        std::string chegadaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
        std::string partidaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));
        StatusSolicitacaoHospedagem status = EnumConversor::InteiroParaStatusSolicitacaoHospedagem(
            sqlite3_column_int(stmt, 6));
        std::string motivo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7));

        lista.emplace_back(
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

void PersistenciaSolicitacaoHospedagem::atualizar(const SolicitacaoHospedagem &s) {
    sqlite3 *db;
    sqlite3_open(DB_PATH, &db);

    const char *sql = R"(
        UPDATE solicitacoes_hospedagem
        SET status = ?, motivo_recusa = ?
        WHERE codigo = ?;
    )";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, EnumConversor::StatusSolicitacaoHospedagemParaInteiro(s.getStatus()));
    sqlite3_bind_text(stmt, 2, s.getMotivoRecusa().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}