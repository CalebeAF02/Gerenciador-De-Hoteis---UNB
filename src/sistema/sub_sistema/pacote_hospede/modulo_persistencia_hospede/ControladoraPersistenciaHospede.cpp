//
// Created by caleb on 16/10/2025.
//

#include "ControladoraPersistenciaHospede.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaHospede::inserir(const Hospede &hospede) {
        sqlite3 *db;
        char *mensagemErro = nullptr;

        int rc = sqlite3_open("hotel.db", &db);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << endl;
            return false;
        }

        string sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES ('" +
                     hospede.getNome() + "', '" + hospede.getEmail() + "', '" + hospede.getEndereco() + "', '" + hospede
                     .
                     getCartao()
                     +
                     "');";

        rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao inserir gerente: " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
            sqlite3_close(db);
            return false;
        }
        sqlite3_close(db);
        return true;
    }

    bool ControladoraPersistenciaHospede::autenticar(const string &email, const string &senha) {
        // Ainda não Implementado
        return true;
    }

    vector<HospedeDTO> ControladoraPersistenciaHospede::listar() {
        vector<HospedeDTO> lista;

        BancoDeDados banco;
        if (!banco.abrindoConexao()) {
            return lista;
        }

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, email, endereco, cartao FROM gerentes;";

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return lista;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);

            const char *nome_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            const char *email_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            const char *endereco_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            const char *cartao_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));

            string nome = nome_ptr ? nome_ptr : "";
            string email = email_ptr ? email_ptr : "";
            string endereco = endereco_ptr ? endereco_ptr : "";
            string cartao = cartao_ptr ? cartao_ptr : "";

            HospedeDTO hospedeObj(id, nome, email, endereco, cartao);

            lista.push_back(hospedeObj);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return lista;
    }

    optional<HospedeDTO> ControladoraPersistenciaHospede::pesquisar(const int &id) {
        return nullopt;
    }

    bool ControladoraPersistenciaHospede::atualizar(const Email &emailAntigo, const Hospede &hospede) {
        // Ainda não Implementado
        return true;
    }

    bool ControladoraPersistenciaHospede::excluir(const int &id) {
        // Ainda não Implementado
        return true;
    }
}