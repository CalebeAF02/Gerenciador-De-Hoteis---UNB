#include "TesteEmail.hpp"
#include <iostream>
#include <vector>
#include "../../libs/teste/SmokeTeste.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteEmail::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: EMAIL");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Formato, Caracteres, Local/Domínio, Tamanho)");

    // Consolida todos os casos que DEVEM FALHAR.
    vector<string> emailsInvalidos = {
        // Formato Invalido (@, .com)
        "joao.silvaempresa.com",
        "joao@.com",
        "@empresa.com",
        "joao@",

        // Caracteres Inválidos (símbolos não permitidos)
        "joao!@empresa.com",
        "maria#clara@ufc.br",
        "user$123@dominio.net",
        "a%bc@sub.dominio.org",

        // Parte Local Invalida (ponto/hífen no início/fim, duplo ponto)
        ".joao@empresa.com",
        "joao.@empresa.com",
        "-maria@ufc.br",
        "joao..silva@empresa.com",

        // Domínio Inválido (hífen no início/fim, duplo ponto)
        "joao@-empresa.com",
        "joao@empresa-.com",
        "joao@empresa..com",
        "joao@.com.br"
    };

    // Casos Muito Longos (construídos dinamicamente)
    string parteLocalMuitoLonga = string(65, 'a'); // Parte local > 64 caracteres
    string dominioMuitoLongo = string(256, 'b'); // Dominio muito longo
    emailsInvalidos.push_back(parteLocalMuitoLonga + "@empresa.com");
    emailsInvalidos.push_back("joao@" + dominioMuitoLongo + ".com");


    for (const string &email: emailsInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR ERRADO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(email),
            "Email",
            [&email]() { Email e(email); } // Lambda que executa a validação
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade");

    vector<string> emailsValidos = {
        "joao.silva@empresa.com",
        "maria-clara@ufc.br",
        "user123@dominio.net",
        "a.b-c@sub.dominio.org",
        "nome@site.com.br"
    };

    for (const string &email: emailsValidos) {
        //CHAMA A FUNÇÃO GENÉRICA (DEVE DAR CERTO)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(email),
            "Email",
            [&email]() { Email e(email); } // Lambda que executa a validação
        );
    }
}

//------------------------------------------------------------------------------------------------------------------