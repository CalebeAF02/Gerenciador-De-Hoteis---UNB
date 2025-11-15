#include "TesteSenha.hpp"
#include <iostream>
#include <vector>
#include "../../libs/teste/SmokeTeste.hpp"
//------------------------------------------------------------------------------------------------------------------
void TesteSenha::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: SENHA");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Regras de Composição e Sequências)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> senhasInvalidas = {
        // Muito Curtas
        "a1!B", "A1$", "b2!",

        // Sem Caractere Obrigatório
        "a1!bz", // Sem Maiúscula
        "A1!BZ", // Sem Minúscula
        "a!BZx", // Sem Dígito
        "a1BZx", // Sem Especial

        // Com Sequências Proibidas
        "aB!c1", // Letras seguidas
        "xY@z2",
        "a12!B", // Dígitos seguidos
        "C34@d"
    };

    for (const string &senha: senhasInvalidas) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(senha),
            "Senha",
            [&senha]() { Senha s(senha); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::TituloEmCaixa("2. Casos de Validade (Atende todas as regras)");

    vector<string> senhasValidas = {
        "a1!B3",
        "B2$a4", // Garante pelo menos 5 caracteres
        "c3%D1",
        "Z1!x2"
    };

    for (const string &senha: senhasValidas) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(senha),
            "Senha",
            [&senha]() { Senha s(senha); } // Lambda que executa a validação
        );
    }
}