//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "ServicosGerente.h"
#include "ServicosHospede.h"
#include "../utilitarios/Menu.h"

#include "TextoApresentacao.h"
#include <iostream>
#include <string>

#include "sqlite3.h"

using namespace std;

class Sistema
{
private:
    bool executando = true;
    ServicosGerente servicosGerente;
    ServicosHospede servicosHospede;

public:
    void menuSistema()
    {
        Sistema::rodandoSistema();
    };

    void rodandoSistema();

    void iniciandoBancoDeDados();

    void criarTabelaGerentes(sqlite3* db);
    void criarTabelaHospedes(sqlite3* db);
    void criarTabelaHoteis(sqlite3* db);
    void criarTabelaQuartos(sqlite3* db);
    void criarTabelaReservas(sqlite3* db);
    void criarTabelaSolicitacoesHospedagem(sqlite3* db);

    bool getExecutandoSistema();

    // Metodo Para Fazer um login pre-programado)
    bool fazerLoginSistemaGerente(const string& emailLoginProgramado, const string& senhaLoginProgramada)
    {
        return servicosGerente.fazerLoginGerente(emailLoginProgramado, senhaLoginProgramada);
    };

    bool fazerLoginSistemaHospede(const string& emailLoginProgramado, const string& senhaLoginProgramada)
    {
        return servicosHospede.fazerLoginHospede(emailLoginProgramado);
    };
};

inline bool Sistema::getExecutandoSistema()
{
    return executando;
};
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H