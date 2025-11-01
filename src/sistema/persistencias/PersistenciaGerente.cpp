//
// Created by caleb on 16/10/2025.
//

#include "PersistenciaGerente.h"

bool PersistenciaGerente::adicionarAoBD(Gerente &gerente) {
    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao();

    std::string sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES ('" +
                      gerente.getNome() + "', '" + gerente.getEmail() + "', '" + gerente.getRamal() + "', '" + gerente.
                      getSenha() +
                      "');";

    char *mensagemErro = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK) {
        std::string erroStr = mensagemErro ? mensagemErro : "Erro desconhecido";

        // Verifica se o erro é de violação de UNIQUE no campo email
        if (erroStr.find("UNIQUE constraint failed: gerentes.email") != std::string::npos) {
            // não esta apresentando a menssagem

            std::cout << "\nErro: Este email ja esta cadastrado no sistema!" << std::endl;
        } else {
            std::cout << "\nErro ao inserir gerente: " << erroStr << std::endl << endl;
        }

        sqlite3_free(mensagemErro);
        sqlite3_close(db);
        return false;
    }

    banco.fechandoConexao();
    return true;
}

vector<Gerente *> PersistenciaGerente::listarBD() {
    vector<Gerente *> listaGerentes;

    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return listaGerentes;

    sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db


    sqlite3_stmt *stmt = nullptr;
    const char *sql = "SELECT nome, email, ramal, senha FROM gerentes;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        banco.fechandoConexao();
        return listaGerentes;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        std::string senha = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

        Gerente *gerenteObj = new Gerente(Nome(nome), Email(email), Ramal(ramal), Senha(senha));

        listaGerentes.push_back(gerenteObj);
    }

    sqlite3_finalize(stmt);
    banco.fechandoConexao();
    return listaGerentes;
}

bool PersistenciaGerente::autenticarGerentePeloBD(const std::string &email, const std::string &senha) {
    BancoDeDados banco;

    if (email.empty() || senha.empty())
        return false;

    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao();
    sqlite3_stmt *stmt = nullptr;

    const char *sql = "SELECT COUNT(*) FROM gerentes WHERE email = ? AND senha = ? LIMIT 1;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        banco.fechandoConexao();
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senha.c_str(), -1, SQLITE_STATIC);

    bool statusAutenticacao = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int quantidade = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
        if (quantidade > 0) {
            statusAutenticacao = true;
        }
    }

    sqlite3_finalize(stmt);
    banco.fechandoConexao();
    return statusAutenticacao;
}

bool PersistenciaGerente::atualizarGerenteNoBD(const Gerente &gerente) {
    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao();
    sqlite3_stmt *stmt = nullptr;

    const char *sql = "UPDATE gerentes SET nome = ?, ramal = ?, senha = ? WHERE email = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao preparar atualizacao: " << sqlite3_errmsg(db) << std::endl;
        banco.fechandoConexao();
        return false;
    }

    sqlite3_bind_text(stmt, 1, gerente.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, gerente.getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, gerente.getEmail().c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    banco.fechandoConexao();

    return rc == SQLITE_DONE;
}

bool PersistenciaGerente::excluirPorEmailDoBD(Gerente *gerenteLogado) {
    if (gerenteLogado == nullptr) {
        std::cout << "Nenhum gerente esta logado. Exclusao nao permitida." << std::endl;
        return false;
    }

    std::string email = gerenteLogado->getEmail();

    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db

    std::string sql = "DELETE FROM gerentes WHERE email = '" + email + "';";
    char *mensagemErro = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao excluir gerente: " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
        banco.fechandoConexao();
        return false;
    }

    banco.fechandoConexao();
    cout << "\nSeu cadastro foi excluido com sucesso. Sessao encerrada.\n";
    return true;
}