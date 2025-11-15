#include "TesteTelefone.hpp"
#include <iostream>
#include <vector>
#include "../../libs/teste/SmokeTeste.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteTelefone::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: TELEFONE");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Formato, Prefixo, Símbolos, Dígitos)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> telefonesInvalidos = {
        // Formato Invalido (parênteses, espaço, hífen incorretos)
        "+5561912345678",
        "+5561912345678",
        "+5561912345678",
        "+5561912345678",
        "+5561912345678",

        // Prefixo Invalido (número após DDD deve ser 9 para celular, e não 0 ou 1)
        "+5561012345678",
        "+5511123456789",
        "+5585034567890",

        // Dígitos Inválidos / Comprimento
        "+556191234567",
        "+558599990000",
    };

    for (const string &telefone: telefonesInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(telefone),
            "Telefone",
            [&telefone]() { Telefone t(telefone); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade (Formato (DD) 9XXXX-XXXX)");

    vector<string> telefonesValidos = {
        "+55611299934567",
        "+55118769954321",
        "+55859999990000",
        "+55219955551234",
        "+55319998887777"
    };

    for (const string &telefone: telefonesValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(telefone),
            "Telefone",
            [&telefone]() { Telefone t(telefone); } // Lambda que executa a validação
        );
    }
}