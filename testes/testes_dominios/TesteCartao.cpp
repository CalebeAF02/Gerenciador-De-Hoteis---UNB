#include "TesteCartao.hpp"
#include <iostream>
#include <vector>
#include "../../libs/teste/SmokeTeste.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteCartao::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: CARTAO");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Tamanho, Letras, Símbolos, Espaços)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> cartoesInvalidos = {
        // Menos e Mais Dígitos
        "411111111111", // Menos dígitos
        "41111111111111112222", // Mais dígitos

        // Símbolos e Espaços
        "4111-1111-1111-1111", // Contém hífen
        "5500 0000 0000 0004", // Contém espaços
        "60110 0000 - 0004-5245620004", // Contém símbolos
    };

    for (const string &cartao: cartoesInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(cartao),
            "Cartao",
            [&cartao]() { Cartao c(cartao); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade");

    vector<string> cartoesValidos = {
        "4111111111111111", // Visa (16 dígitos)
        "5500000000000004", // Mastercard (16 dígitos)
        "3400000000000049", // Amex (15 dígitos)
        "6011000000000004", // Discover (16 dígitos)
        "3530111333300000" // JCB (16 dígitos)
    };

    for (const string &cartao: cartoesValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(cartao),
            "Cartao",
            [&cartao]() { Cartao c(cartao); } // Lambda que executa a validação
        );
    }
}

//------------------------------------------------------------------------------------------------------------------