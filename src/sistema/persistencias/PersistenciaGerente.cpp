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
        std::string erroStr = mensagemErro ? mensagemErro : "Erro desconhecido";

        // Verifica se o erro é de violação de UNIQUE no campo email
        if (erroStr.find("UNIQUE constraint failed: gerentes.email") != std::string::npos)
        {
            // não esta apresentando a menssagem

            std::cout << "\nErro: Este email ja esta cadastrado no sistema!" << std::endl;
        }
        else
        {
            std::cout << "\nErro ao inserir gerente: " << erroStr << std::endl<<endl;
        }

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

    sqlite3* db = sistema.getConexao(); // metodo que retorna o ponteiro db


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

Gerente* PersistenciaGerente::autenticarGerentePeloBD(const std::string& email, const std::string& senha)
{
    Sistema sistema;

    if (email.empty() || senha.empty())
        return nullptr;

    if (!sistema.abrindoConexao())
        return nullptr;

    sqlite3* db = sistema.getConexao();
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT nome, email, ramal, senha FROM gerentes WHERE email = ? AND senha = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sistema.fechandoConexao();
        return nullptr;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senha.c_str(), -1, SQLITE_STATIC);

    Gerente* gerente = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string emailBD = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string ramal = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string senhaBD = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        gerente = new Gerente(Nome(nome), Email(emailBD), Ramal(ramal), Senha(senhaBD));
    }

    sqlite3_finalize(stmt);
    sistema.fechandoConexao();
    return gerente;
}

bool PersistenciaGerente::atualizarGerenteNoBD(const Gerente& gerente)
{
    Sistema sistema;
    if (!sistema.abrindoConexao())
        return false;

    sqlite3* db = sistema.getConexao();
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "UPDATE gerentes SET nome = ?, ramal = ?, senha = ? WHERE email = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar atualizacao: " << sqlite3_errmsg(db) << std::endl;
        sistema.fechandoConexao();
        return false;
    }

    sqlite3_bind_text(stmt, 1, gerente.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, gerente.getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, gerente.getEmail().c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sistema.fechandoConexao();

    return rc == SQLITE_DONE;
}

bool PersistenciaGerente::excluirPorEmailDoBD(Gerente* gerenteLogado)
{
    if (gerenteLogado == nullptr)
    {
        std::cout << "Nenhum gerente esta logado. Exclusao nao permitida." << std::endl;
        return false;
    }

    std::string email = gerenteLogado->getEmail();

    Sistema sistema;
    if (!sistema.abrindoConexao())
        return false;

    sqlite3* db = sistema.getConexao(); // metodo que retorna o ponteiro db

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
    cout << "\nSeu cadastro foi excluido com sucesso. Sessao encerrada.\n";
    return true;
}