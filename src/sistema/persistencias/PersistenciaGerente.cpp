//
// Created by caleb on 16/10/2025.
//

#include "../../../include/sistema/persistencias/PersistenciaGerente.h"

#include "Sistema.h"
#include "sqlite3.h"

bool PersistenciaGerente::adicionarAoBD(Gerente& gerente)
{
    Sistema sistema;
    if (!sistema.abrindoConexao())
        return false;

    sqlite3* db = sistema.getConexao(); // método que retorna o ponteiro db

    std::string sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES ('" +
        gerente.getNome() + "', '" + gerente.getEmail() + "', '" + gerente.getRamal() + "', '" + gerente.getSenha() +
        "');";
    char* mensagemErro = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao inserir gerente: " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
        sqlite3_close(db);
        return false;
    }

    sistema.fechandoConexao();
    return true;
}

vector<Gerente*> PersistenciaGerente::listarBD()
{
    vector<Gerente*> listaGerentes;

    Sistema sistema;
    if (!sistema.abrindoConexao())
        return listaGerentes;

    sqlite3* db = sistema.getConexao(); // método que retorna o ponteiro db


    sqlite3_stmt* stmt = nullptr;
    const char* sql = "SELECT nome, email, ramal, senha FROM gerentes;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sistema.fechandoConexao();
        return listaGerentes;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string ramal = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string senha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        Gerente* gerenteObj = new Gerente(Nome(nome), Email(email), Ramal(ramal), Senha(senha));

        listaGerentes.push_back(gerenteObj);
    }

    sqlite3_finalize(stmt);
    sistema.fechandoConexao();
    return listaGerentes;
}

bool PersistenciaGerente::excluirPorEmailDoBD(Gerente* gerenteLogado)
{
    if (gerenteLogado == nullptr)
    {
        std::cout << "Nenhum gerente está logado. Exclusão não permitida." << std::endl;
        return false;
    }

    std::string email = gerenteLogado->getEmail();

    Sistema sistema;
    if (!sistema.abrindoConexao())
        return false;

    sqlite3* db = sistema.getConexao(); // método que retorna o ponteiro db

    std::string sql = "DELETE FROM gerentes WHERE email = '" + email + "';";
    char* mensagemErro = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao excluir gerente: " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
        sistema.fechandoConexao();
        return false;
    }

    sistema.fechandoConexao();
    cout << "\nSeu cadastro foi excluído com sucesso. Sessão encerrada.\n";
    return true;
}