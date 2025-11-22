#include "TesteDinheiro.hpp"
#include <iostream>
#include <vector>
#include "SmokeTeste.hpp"
//------------------------------------------------------------------------------------------------------------------
void TesteDinheiro::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: DINHEIRO");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Negativos, Zero, Limites Máximos)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<int> valoresInvalidos = {
        // Negativos
        -1, -100, -99999999,
        // Zero (Se o seu código original espera falha para 0, mantemos aqui)
        0,
        // Muito Altos
        100000001, 500000000, 999999999
    };

    for (const int &valor: valoresInvalidos) {
        string valor_log = to_string(valor);

        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(valor_log),
            "Dinheiro",
            [&valor]() { Dinheiro d(valor); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade (Positivos, dentro do limite)");

    vector<int> valoresValidos = {
        1, 100, 9999, 100000, 99999999, 100000000
    };

    for (const int &valor: valoresValidos) {
        string valor_log = to_string(valor);

        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(valor_log),
            "Dinheiro",
            [&valor]() { Dinheiro d(valor); } // Lambda que executa a validação
        );
    }
}

//------------------------------------------------------------------------------------------------------------------