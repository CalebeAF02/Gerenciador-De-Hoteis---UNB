// NO SEU TestesData.cpp (Refatorado para o Padrão Genérico)

#include "TestesData.hpp"
#include "SmokeTeste.hpp"
#include "ConsoleFormatter.hpp"
#include "ConsoleIO.hpp"
#include "../../include/sistema/dominios/Data.hpp"
#include <vector>
#include <string>

using namespace std;

void TestesData::executar() {
    SmokeTeste smoke_teste;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: DATA (DD/MM/AAAA)");

    // O valor de teste deve ser sempre a string completa da data.
    const string DOMINIO = "Data";

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Casos de Invalidade (Formato, Limites, Dias por Mes)");

    vector<string> datasInvalidas = {
        // Formato/Separador
        "01-01-2025",

        // Dias Inválidos (Regra: 1-31)
        "40/01/2025", "00/01/2025",

        // Meses Inválidos (Regra: 1-12)
        "01/13/2025", "01/00/2025",

        // Anos Inválidos (Regra: 2000-2999)
        "01/01/1999", "01/01/3000",

        // Regra Dias por Mês (Lógica Faltante: 31 em Abril/Fev, Bissexto)
        "31/04/2025", // Abril só tem 30 dias
        "31/06/2025", // Junho só tem 30 dias
        "29/02/2001", // 2001 não é bissexto
        "30/02/2024", // Fevereiro nunca tem 30
    };

    for (const string &dataStr: datasInvalidas) {
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            dataStr,
            DOMINIO,
            // Lambda que chama o construtor Data(string)
            [&dataStr]() { Data d(dataStr); }
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Casos de Validade (DD/MM/AAAA)");

    vector<string> datasValidas = {
        "01/01/2000",
        "31/12/2999", // Limite máximo
        "15/06/2025", // Data normal
        "29/02/2024", // 2024 é bissexto! (Seu validador deve permitir isso)
    };

    for (const string &dataStr: datasValidas) {
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            dataStr,
            DOMINIO,
            [&dataStr]() { Data d(dataStr); }
        );
    }
}
//------------------------------------------------------------------------------------------------------------------
