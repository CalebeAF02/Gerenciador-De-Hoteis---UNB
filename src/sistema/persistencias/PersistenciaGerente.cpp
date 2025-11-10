//
// Created by caleb on 16/10/2025.
//

#include "PersistenciaGerente.hpp"

bool PersistenciaGerente::inserir(Gerente &gerente) {
    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao();

    string sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES ('" +
                 gerente.getNome() + "', '" + gerente.getEmail() + "', '" + gerente.getRamal() + "', '" + gerente.
                 getSenha() +
                 "');";

    char *mensagemErro = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK) {
        string erroStr = mensagemErro ? mensagemErro : "Erro desconhecido";

        // Verifica se o erro é de violação de UNIQUE no campo email
        if (erroStr.find("UNIQUE constraint failed: gerentes.email") != string::npos) {
            // não esta apresentando a menssagem

            ConsoleIO::PrintMenssagem("Erro: Este email ja esta cadastrado no sistema!");
        } else {
            ConsoleIO::PrintMenssagem("Erro ao inserir gerente: " + erroStr);
        }

        sqlite3_free(mensagemErro);
        sqlite3_close(db);
        return false;
    }

    banco.fechandoConexao();
    return true;
}

vector<GerenteDTO *> PersistenciaGerente::listar() {
    vector<GerenteDTO *> lista;

    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return lista;

    sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db


    sqlite3_stmt *stmt = nullptr;
    const char *sql = "SELECT id, nome, email, ramal FROM gerentes;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
        banco.fechandoConexao();
        return lista;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
        string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        string email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

        GerenteDTO *gerenteObj = new GerenteDTO(id, nome, email, ramal);

        lista.push_back(gerenteObj);
    }

    sqlite3_finalize(stmt);
    banco.fechandoConexao();
    return lista;
}

bool PersistenciaGerente::autenticarGerente(const string &email, const string &senha) {
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
        cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
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

bool PersistenciaGerente::atualizar(int id, const Gerente &gerente) {
    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao();
    sqlite3_stmt *stmt = nullptr;

    const char *sql = "UPDATE gerentes SET nome = ?, email = ?, ramal = ?, senha = ? WHERE id = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Erro ao preparar atualizacao: " << sqlite3_errmsg(db) << endl;
        banco.fechandoConexao();
        return false;
    }

    sqlite3_bind_text(stmt, 1, gerente.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, gerente.getEmail().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, gerente.getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, id);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    banco.fechandoConexao();

    return rc == SQLITE_DONE;
}

bool PersistenciaGerente::excluirPorEmail(Gerente *gerenteLogado) {
    if (gerenteLogado == nullptr) {
        cout << "Nenhum gerente esta logado. Exclusao nao permitida." << endl;
        return false;
    }

    string email = gerenteLogado->getEmail();

    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return false;

    sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db

    string sql = "DELETE FROM gerentes WHERE email = '" + email + "';";
    char *mensagemErro = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);
    if (rc != SQLITE_OK) {
        cerr << "Erro ao excluir gerente: " << mensagemErro << endl;
        sqlite3_free(mensagemErro);
        banco.fechandoConexao();
        return false;
    }

    banco.fechandoConexao();
    cout << "\nSeu cadastro foi excluido com sucesso. Sessao encerrada.\n";
    return true;
}

optional<GerenteDTO> PersistenciaGerente::buscaGerentePorID(int id) {
    optional<GerenteDTO> dto = nullopt;

    BancoDeDados banco;
    if (!banco.abrindoConexao())
        return nullopt; // Retorna o optional vazio (falha na busca);

    sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db


    sqlite3_stmt *stmt = nullptr;
    const char *sql = "SELECT id, nome, email, ramal FROM gerentes WHERE id = ? LIMIT 1;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
        banco.fechandoConexao();
        return nullopt; // Retorna o optional vazio (falha na busca);
    }

    sqlite3_bind_int(stmt, 1, id);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
        string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        string email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

        dto = GerenteDTO(id, nome, email, ramal);
    }

    sqlite3_finalize(stmt);
    banco.fechandoConexao();
    return dto;
}
