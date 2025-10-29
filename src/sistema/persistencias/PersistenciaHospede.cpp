//
// Created by caleb on 16/10/2025.
//

#include "../../../include/sistema/persistencias/PersistenciaHospede.h"

#include "sqlite3.h"

bool PersistenciaHospede::criar(Hospede& hospede)
{
    //_________________________ABRE CONEXÂO_______________________________
    sqlite3* db;
    char* mensagemErro = nullptr;

    int rc = sqlite3_open("hotel.db", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    //_________________________------------_______________________________

    std::string sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES ('" +
        hospede.getNome() + "', '" + hospede.getEmail() + "', '" + hospede.getEndereco() + "', '" + hospede.getCartao()
        +
        "');";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao inserir gerente: " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
        sqlite3_close(db);
        return false;
    }
    //_________________________FECHA CONEXÂO_______________________________
    sqlite3_close(db);
    return true;
    //_________________________------------_______________________________
}

vector<Hospede*> PersistenciaHospede::listar()
{
    vector<Hospede*> listarHospedes;

    //_________________________ABRE CONEXÂO_______________________________
    sqlite3* db;
    char* mensagemErro = nullptr;

    int rc = sqlite3_open("hotel.db", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return listarHospedes;
    }
    //_________________________------------_______________________________

    sqlite3_stmt* stmt = nullptr;
    const char* sql = "SELECT nome, email, ramal, senha FROM gerentes;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return listarHospedes;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string endereco = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string cartao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        Hospede* hospedeObj = new Hospede(Nome(nome), Email(email), Endereco(endereco), Cartao(cartao));

        listarHospedes.push_back(hospedeObj);
    }

    sqlite3_finalize(stmt);

    //_________________________FECHA CONEXÂO_______________________________
    sqlite3_close(db);
    //_________________________------------_______________________________
    return listarHospedes;
}