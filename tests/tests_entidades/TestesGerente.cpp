#include "TestesGerente.hpp"
#include "Smoke_Tests.hpp"

//------------------------------------------------------------------------------------------------------------------
void TestesGerente::executar() {
    SmokeTest smoke_test;
    Gerente gerente1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: GERENTE");

    // =========================================================================
    // 1. VALIDACAO DE NOME
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "1. Validacao de Nome (4 a 30 caracteres, 1o maiusculo, Apenas 1 espaco)");

    // A. Casos Invalidos
    vector<string> nomesInvalidos = {
        "", "Cb", "Calebe Alves Freitas Madeira Alves", "Calebe  Alves", "Calebe   ",
        "calebe alves", "Calebe alves", "Calebe@alves", "Calebe Alves "
    };

    for (const string &nome: nomesInvalidos) {
        smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, nome);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "Luan Freitas");

    // =========================================================================
    // 2. VALIDACAO DE EMAIL
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "2. Validacao de Email (Padrao: AAAA@BBBB.CCC, min 3, max 64 no local)");

    // A. Casos Invalidos
    vector<string> emailsInvalidos = {
        "", "Cb@gmail.com",
        "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com", // Usuario muito longo
        "calebe clves@gmail.com", "calebe  clves@gmail.com", ".cb@gmail.com", ".-cb@gmail.com",
        "c--b@gmail.com", "c..b@gmail.com",
        "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com"
        // Dominio muito longo
    };

    for (const string &email: emailsInvalidos) {
        smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, email);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "calebeclves@citex.eb.mil.com");


    // =========================================================================
    // 3. VALIDACAO DE RAMAL
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Ramal (2 digitos numericos, 00 a 50)");

    // A. Casos Invalidos
    vector<string> ramaisInvalidos = {
        "-1", "51", "abc", ""
    };

    for (const string &ramal: ramaisInvalidos) {
        smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, ramal);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "49");


    // =========================================================================
    // 4. VALIDACAO DE SENHA
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Senha (5 caracteres: M, m, d, #)");

    // A. Casos Invalidos
    vector<string> senhasInvalidas = {
        "AA1#2", "Aa1#2", "A12#3", "1#2#3", "A#B#C", "a#b#c", ""
    };

    for (const string &senha: senhasInvalidas) {
        smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, senha);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "A1!b2");
}

//------------------------------------------------------------------------------------------------------------------
string TestesGerente::nomeDoTeste() const {
    return "Teste de Entidade: Gerente";
}

//------------------------------------------------------------------------------------------------------------------
