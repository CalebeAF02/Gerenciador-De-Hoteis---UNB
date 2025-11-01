//
// Created by caleb on 01/11/2025.
//

#include "BancoDeDados.h"

bool BancoDeDados::abrindoConexao() {
    //_________________________ABRE CONEXÂO_______________________________
    int rc = sqlite3_open("hotel.db", &db);
    if (rc != SQLITE_OK) {
        cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    char *mensagemErro = nullptr;
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, &mensagemErro);

    cout << "Banco aberto com sucesso!\n";
    return true;
    //_________________________------------_______________________________
}

bool BancoDeDados::fechandoConexao() {
    //_________________________FECHA CONEXÂO_______________________________
    if (db) {
        sqlite3_close(db);
        db = nullptr;
        cout << "Conexao com o banco encerrada com sucesso!\n";
        return true;
    }

    cerr << "Nenhuma conexao ativa para fechar.\n";
    return false;
    //_________________________------------_______________________________
}

void BancoDeDados::criandoBancoDeDados() {
    if (!abrindoConexao())
        return;

    // Comandos SQL para criar cada tabela
    criarTabelaGerentes(db);
    criarTabelaHospedes(db);
    criarTabelaHoteis(db);
    criarTabelaQuartos(db);
    criarTabelaReservas(db);
    criarTabelaSolicitacoesHospedagem(db);

    fechandoConexao();
};

void BancoDeDados::criarTabelaGerentes(sqlite3 *db) {
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS gerentes (
            gerente_id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            email TEXT NOT NULL DEFAULT '',
            ramal TEXT NOT NULL DEFAULT '',
            senha TEXT NOT NULL DEFAULT ''
        );
    )";

    char *mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela 'gerentes': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    } else {
        std::cout << "Tabela 'gerentes' criada com sucesso!" << std::endl;
    }
}

void BancoDeDados::criarTabelaHospedes(sqlite3 *db) {
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS hospedes (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            email TEXT NOT NULL UNIQUE DEFAULT '',
            endereco TEXT NOT NULL DEFAULT '',
            cartao TEXT NOT NULL DEFAULT ''
        );
    )";

    char *mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela 'hospedes': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    } else {
        std::cout << "Tabela 'hospedes' criada com sucesso!" << std::endl;
    }
}

void BancoDeDados::criarTabelaHoteis(sqlite3 *db) {
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS hoteis (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            endereco TEXT NOT NULL DEFAULT '',
            telefone TEXT NOT NULL DEFAULT '',
            codigo TEXT NOT NULL UNIQUE DEFAULT ''
        );
    )";

    char *mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela 'hoteis': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    } else {
        std::cout << "Tabela 'hoteis' criada com sucesso!" << std::endl;
    }
}

void BancoDeDados::criarTabelaQuartos(sqlite3 *db) {
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS quartos (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            numero TEXT NOT NULL DEFAULT '',
            id_hotel INTEGER,
            capacidade INTEGER NOT NULL DEFAULT 0,
            dinheiro INTEGER NOT NULL DEFAULT 0,
            ramal TEXT NOT NULL DEFAULT '',
            FOREIGN KEY (id_hotel) REFERENCES hoteis(id)
        );
    )";

    char *mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela 'quartos': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    } else {
        std::cout << "Tabela 'quartos' criada com sucesso!" << std::endl;
    }
}

void BancoDeDados::criarTabelaReservas(sqlite3 *db) {
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS reservas (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            id_quarto INTEGER,
            email_hospede TEXT,
            chegada TEXT NOT NULL DEFAULT '',
            partida TEXT NOT NULL DEFAULT '',
            dinheiro INTEGER NOT NULL DEFAULT 0,
            FOREIGN KEY (email_hospede) REFERENCES hospedes(email),
            FOREIGN KEY (id_quarto) REFERENCES quartos(id)
        );
    )";

    char *mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela 'reservas': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    } else {
        std::cout << "Tabela 'reservas' criada com sucesso!" << std::endl;
    }
}

void BancoDeDados::criarTabelaSolicitacoesHospedagem(sqlite3 *db) {
    // Comando SQL para criar a tabela
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS solicitacoes_hospedagem (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        email_hospede TEXT NOT NULL,
        id_hotel TEXT NOT NULL,
        id_quarto TEXT NOT NULL,
        chegada TEXT NOT NULL,
        partida TEXT NOT NULL,
        status INTEGER NOT NULL,
        motivo_recusa TEXT
        );
    )";

    char *mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela 'solicitacoes_hospedagem': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    } else {
        std::cout << "Tabela 'solicitacoes_hospedagem' criada com sucesso!" << std::endl;
    }
}