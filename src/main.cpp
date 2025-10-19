#include "Smoke_Tests.h"
#include "sistema/Sistema.h"

#include <iostream>
#include <string>
#include "sqlite/sqlite3.h"

#include "../include/utilitarios/TextoApresentacao.h"

using namespace std;

#define TESTANDO 0

#define PRODUCAO 1

#define ESTOU_TESTANDO TESTANDO

int main()
{
    /*
     * Edições a fazer :
     *
     * Funcionalidades do sistema
     *
     * Conta = LER; EDITAR; EXCLUIR;
     * Hotel = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hoteis;
     * Quarto = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os quartos;
     * Reserva = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos as reservas;
     * Hospede = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hospedes;
     *
     * 1) Não pode haver conflitos nas reservas!
     *
     * 2) Não pode editar as informações em CODIGO, que apresenta chave de registro "PK"!
     *
     * 3) Não permite exclusões que gerem inconcistencias!
     *
     */
#if ESTOU_TESTANDO == TESTANDO
    SmokeTest::testarEntradas();
    Sistema sistema;

    sqlite3* db;
    char* mensagemErro = nullptr;

    int rc = sqlite3_open("hotel.db", &db);

    if (rc)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Banco aberto com sucesso!" << std::endl;

        const char* sql = R"(
        CREATE TABLE IF NOT EXISTS gerentes (
            gerente_id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL DEFAULT '',
            email TEXT NOT NULL DEFAULT '',
            ramal TEXT NOT NULL DEFAULT '',
            senha TEXT NOT NULL DEFAULT ''
        );
    )";

        rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            std::cerr << "Erro ao criar tabela: " << mensagemErro << std::endl;
            sqlite3_free(mensagemErro);
        } else {
            std::cout << "Tabela 'gerentes' criada com sucesso!" << std::endl;
        }


    }

    sqlite3_close(db);

    cout << endl;
    sistema.menuSistema();

    /*
    TextoApresentacao::MostrarTituloEmCaixa("Login Programado");
    cout << "Entrada :" << "calebe@gmail.com" << endl << "Senha :" << "A1#a1" << endl << endl;

    if (sistema.fazerLoginSistema("calebe@gmail.com", "A1#a1"))
    {
        cout << endl;
        sistema.menuSistema();
    };
    */
#endif

#if ESTOU_TESTANDO == PRODUCAO
    Sistema sistema;
    while (sistema.getExecutandoSistema())
    {
        sistema.rodandoSistema();
    }
#endif


    return 0;
}