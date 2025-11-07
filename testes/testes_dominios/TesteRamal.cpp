#include "TesteRamal.hpp"
#include <iostream>
#include <vector>
#include "SmokeTeste.hpp"

void TesteRamal::executar() {
    SmokeTeste smoke_teste;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: RAMAL");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Casos de Invalidade (Tamanho, Letras, Símbolos, Espaços)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> ramaisInvalidos = {
        // Tamanho (Menos e Mais Dígitos)
        "1", "123", // Menos e mais de 2

        // Ramais fora do Range (Maiores que 50)
        "51", "99",

        // Letras/Símbolos/Espaços (Mantidos, mas garantindo 2 caracteres para falhar no dígito)
        "1a", "b2", "@@", " 2", "2 ",
    };

    for (const string &ramal: ramaisInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(ramal),
            "Ramal",
            [&ramal]() { Ramal r(ramal); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Casos de Validade (4 Dígitos, Apenas Números)");

    vector<string> ramaisValidos = {
        "00", "01", "15", "49", "50" // ✅ Ramais de 2 dígitos no range 00-50
    };

    for (const string &ramal: ramaisValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(ramal),
            "Ramal",
            [&ramal]() { Ramal r(ramal); } // Lambda que executa a validação
        );
    }
}