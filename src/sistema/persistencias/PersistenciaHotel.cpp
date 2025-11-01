//
// Created by caleb on 01/11/2025.
//

#include "PersistenciaHotel.h"

bool PersistenciaHotel::inserirAoBD(Hotel *hotel) {
    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao();

    const char *sql = "INSERT INTO hoteis (nome, endereco, telefone, codigo) VALUES (?, ?, ?, ?);";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, hotel->getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hotel->getEndereco().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, hotel->getTelefone().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, hotel->getCodigo().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    banco.fechandoConexao();
    return true;
}