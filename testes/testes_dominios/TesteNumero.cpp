#include "TesteNumero.hpp"
#include <iostream>
#include <vector>
#include "SmokeTeste.hpp"
//------------------------------------------------------------------------------------------------------------------
void TesteNumero::executar() {
    SmokeTeste smoke_teste;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: NUMERO");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Casos de Invalidade (Vazio, Negativos, Letras, Símbolos, Espaços)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> numerosInvalidos = {
        // Vazios / Espaços
        "", " ", " 123", "12 3", "123 ", "1 2 3 4",

        // Negativos
        "-1", "-123", "-9999",

        // Letras
        "12a3", "abc", "9b9c",

        // Símbolos (incluindo ponto decimal, se o Domínio for inteiro)
        "12@3", "99#9", "!000", "45.67"
    };

    for (const string &numero: numerosInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(numero),
            "Numero",
            [&numero]() { Numero n(numero); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Casos de Validade (Apenas Dígitos Positivos)");

    vector<string> numerosValidos = {
        "001", "123", "999", "456", "789", "100" // Adicionei "0", que é geralmente válido
    };

    for (const string &numero: numerosValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(numero),
            "Numero",
            [&numero]() { Numero n(numero); } // Lambda que executa a validação
        );
    }
}