#include "TesteCodigo.hpp"
#include <iostream>
#include <vector>
#include "../../libs/teste/SmokeTeste.hpp"
//------------------------------------------------------------------------------------------------------------------
void TesteCodigo::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: CODIGO");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Tamanho, Caracteres Inválidos, Espaços)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> codigosInvalidos = {
        // Caracteres Inválidos
        "ABC@123###", "X9Y#Z7#$%-", "Codigo!578", "A1B2*C3ccb",

        // Espaços
        "ABC 123456", " X9Y123456", "ZXC123456 ",

        // Tamanho (Curtos)
        "A1", "X9", "Z",

        // Tamanho (Longos)
        "ABC123XYZ789DEF456",
        string(25, 'A')
    };

    for (const string &codigo: codigosInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(codigo),
            "Codigo",
            [&codigo]() { Codigo c(codigo); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade (Alfanuméricos, sem espaço)");

    vector<string> codigosValidos = {
        "QTR1234567", "QTR4561287", "QTR9997845", "QTR9451267", "QTR5426873"
    };

    for (const string &codigo: codigosValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(codigo),
            "Codigo",
            [&codigo]() { Codigo c(codigo); } // Lambda que executa a validação
        );
    }
}
//------------------------------------------------------------------------------------------------------------------