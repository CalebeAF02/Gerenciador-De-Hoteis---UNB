//
// Created by caleb on 16/10/2025.
//

#include "../../../include/sistema/persistencias/PersistenciaGerente.h"

#include "sqlite3.h"

bool PersistenciaGerente::criar(Gerente& gerente) {
    sqlite3* db;
    char* mensagemErro = nullptr;

    int rc = sqlite3_open("hotel.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::string sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES ('" +
                      gerente.getNome() + "', '" + gerente.getEmail() + "', '" + gerente.getRamal() + "', '" + gerente.getSenha() + "');";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao inserir gerente: " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
        sqlite3_close(db);
        return false;
    }

    std::cout << "Gerente inserido com sucesso!" << std::endl;
    sqlite3_close(db);
    return true;
}
