#include "TesteEndereco.hpp"
#include <iostream>
#include <vector>
#include "../../libs/teste/SmokeTeste.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteEndereco::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: ENDERECO");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Caracteres, Início/Fim Invalido, Tamanho)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> enderecosInvalidos = {
        // Caracteres Inválidos (símbolos não permitidos)
        "Rua das Flores @ 123",
        "Av. Brasil # Bloco A",
        "Praca Central * 45",
        "Rua Joao Goulart ! 789",

        // Início ou Fim Inválido (ponto/hífen no início/fim)
        ".Rua das Flores",
        "Rua das Flores.",
        "Av.s Brasil ",
        ",Praca Central,",

        // Muito Longos
        string(101, 'A'),
        "Rua " + string(97, 'B')
    };

    for (const string &endereco: enderecosInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(endereco),
            "Endereco",
            [&endereco]() { Endereco e(endereco); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade");

    vector<string> enderecosValidos = {
        "Rua das Flores, 123",
        "Av. Brasil. Bloco A",
        "Praca Central 45",
        "Rua Joao Goulart, 789",
        "Alameda dos Anjos. Casa 10"
    };

    for (const string &endereco: enderecosValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(endereco),
            "Endereco",
            [&endereco]() { Endereco e(endereco); } // Lambda que executa a validação
        );
    }
}

//------------------------------------------------------------------------------------------------------------------