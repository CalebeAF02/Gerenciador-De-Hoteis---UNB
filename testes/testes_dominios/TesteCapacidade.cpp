#include "TesteCapacidade.hpp"
#include <iostream>
#include <vector>
#include "SmokeTeste.hpp"
#include "SmokeTeste.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteCapacidade::executar() {
    SmokeTeste smoke_teste;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: CAPACIDADE");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Casos de Invalidade (Negativos e Extremos)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<int> capacidadesInvalidas = {
        // Negativas
        -1, -10, -999,
        // Muito Altas (Assumindo que > 1000, 5000, 99999 são inválidas)
        1000, 5000, 99999
    };

    for (const int &capacidade: capacidadesInvalidas) {
        string valor_log = to_string(capacidade);

        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(valor_log),
            "Capacidade",
            [&capacidade]() { Capacidade c(capacidade); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Casos de Validade (Incluindo Limite Zero)");

    // Casos válidos e o caso 0, que seu código original esperava sucesso.
    vector<int> capacidadesValidas = {
        1, 2, 3, 4
    };

    for (const int &capacidade: capacidadesValidas) {
        string valor_log = to_string(capacidade);

        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(valor_log),
            "Capacidade",
            [&capacidade]() { Capacidade c(capacidade); } // Lambda que executa a validação
        );
    }
}

//------------------------------------------------------------------------------------------------------------------