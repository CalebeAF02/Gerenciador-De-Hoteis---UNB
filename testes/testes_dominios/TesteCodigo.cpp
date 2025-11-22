#include "TesteCodigo.hpp"
#include <iostream>
#include <vector>
#include "SmokeTeste.hpp"
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
        "ABC@123###", // contém @ e #
        "X9Y#Z7$%-", // contém símbolos
        "Codigo!578", // contém !
        "A1B2*C3ccb", // contém *

        // Espaços
        "ABC 123456", // espaço no meio
        " X9Y123456", // espaço no início
        "ZXC123456 ", // espaço no fim

        // Tamanho (Curtos)
        "A1", // muito curto
        "X9", // muito curto
        "Z", // apenas 1 caractere

        // Tamanho (Longos)
        "ABC123XYZ789DEF456", // mais de 10 caracteres
        string(25, 'A') // 25 caracteres iguais
    };

    for (const string &codigo: codigosInvalidos) {
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            codigo,
            "Codigo",
            [&codigo]() { Codigo c(codigo); }
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade (Alfanuméricos, sem espaço)");

    vector<string> codigosValidos = {
        "HOTEL12345", // letras + números
        "ABC9876543", // letras + números
        "ZzYyXxWw09", // mistura maiúsculas/minúsculas + números
        "A1B2C3D4E5", // alternando letras e números
        "QTR5426873" // padrão já usado
    };

    for (const string &codigo: codigosValidos) {
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            codigo,
            "Codigo",
            [&codigo]() { Codigo c(codigo); }
        );
    }
}

//------------------------------------------------------------------------------------------------------------------