//
// Created by caleb on 28/09/2025.
//

#include "Sistema.h"

#include "sqlite3.h"

void Sistema::rodandoSistema()
{
    Menu menu;

    int OPCAO_SAIR_DO_SISTEMA = menu.adcionarItens("Sair");
    int OPCAO_ENTRAR_COMO_GERENTE = menu.adcionarItens("Entrar como Gerente");
    int OPCAO_ENTRAR_COMO_HOSPEDE = menu.adcionarItens("Entrar como Hospede");

    while (executando == true)
    {
        int opcao = menu.executa("Seja bem vindo ao gerenciador de hoteis");

        if (opcao == OPCAO_SAIR_DO_SISTEMA)
        {
            executando = false;
            cout << "Encerrando o sistema..." << endl;
        }
        else if (opcao == OPCAO_ENTRAR_COMO_GERENTE)
        {
            servicosGerente.acessandoGerente();
        }
        else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE)
        {
            servicosHospede.acessandoHospede();
        }
    }
};

void Sistema::iniciandoBancoDeDados()
{
    sqlite3* db;
    char* mensagemErro = nullptr;

    int rc = sqlite3_open("hotel.db", &db);

    if (rc)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    cout << "\nBanco aberto com sucesso!\n" << endl;

    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, &mensagemErro);

    criarTabelaGerentes(db);
    criarTabelaHospedes(db);
    criarTabelaHoteis(db);
    criarTabelaQuartos(db);
    criarTabelaReservas(db);
    criarTabelaSolicitacoesHospedagem(db);

    sqlite3_close(db);

    cout << endl;
};

void Sistema::criarTabelaGerentes(sqlite3* db)
{
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS gerentes (
            gerente_id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            email TEXT NOT NULL DEFAULT '',
            ramal TEXT NOT NULL DEFAULT '',
            senha TEXT NOT NULL DEFAULT ''
        );
    )";

    char* mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela 'gerentes': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
    else
    {
        std::cout << "Tabela 'gerentes' criada com sucesso!" << std::endl;
    }
}

void Sistema::criarTabelaHospedes(sqlite3* db)
{
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS hospedes (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            email TEXT NOT NULL UNIQUE DEFAULT '',
            endereco TEXT NOT NULL DEFAULT '',
            cartao TEXT NOT NULL DEFAULT ''
        );
    )";

    char* mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela 'hospedes': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
    else
    {
        std::cout << "Tabela 'hospedes' criada com sucesso!" << std::endl;
    }
}

void Sistema::criarTabelaHoteis(sqlite3* db)
{
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS hoteis (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            endereco TEXT NOT NULL DEFAULT '',
            telefone TEXT NOT NULL DEFAULT '',
            codigo TEXT NOT NULL UNIQUE DEFAULT ''
        );
    )";

    char* mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela 'hoteis': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
    else
    {
        std::cout << "Tabela 'hoteis' criada com sucesso!" << std::endl;
    }
}

void Sistema::criarTabelaQuartos(sqlite3* db)
{
    const char* sql = R"(
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

    char* mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela 'quartos': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
    else
    {
        std::cout << "Tabela 'quartos' criada com sucesso!" << std::endl;
    }
}

void Sistema::criarTabelaReservas(sqlite3* db)
{
    const char* sql = R"(
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

    char* mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela 'reservas': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
    else
    {
        std::cout << "Tabela 'reservas' criada com sucesso!" << std::endl;
    }
}

void Sistema::criarTabelaSolicitacoesHospedagem(sqlite3* db)
{
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS solicitacoes_hospedagem (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            email_hospede TEXT NOT NULL DEFAULT '',
            status TEXT DEFAULT '',
            FOREIGN KEY (email_hospede) REFERENCES hospedes(email)
        );
    )";

    char* mensagemErro = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao criar tabela 'solicitacoes_hospedagem': " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
    else
    {
        std::cout << "Tabela 'solicitacoes_hospedagem' criada com sucesso!" << std::endl;
    }
}
