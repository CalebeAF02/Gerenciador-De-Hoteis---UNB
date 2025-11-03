#include "TestesHospede.hpp"
#include "Smoke_Tests.hpp"

//------------------------------------------------------------------------------------------------------------------
void TestesHospede::executar() {
    SmokeTest smoke_test;
    Hospede hospede1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: HOSPEDE");

    // =========================================================================
    // 1. VALIDACAO DE NOME (Compartilhado com Gerente)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "1. Validacao de Nome (4 a 30 caracteres, 1o maiusculo, Apenas 1 espaco)");

    // A. Casos Invalidos
    vector<string> nomesInvalidos = {
        "", "Cb", "Calebe Alves Freitas Madeira Alves", "Calebe  Alves",
        "calebe alves", "Calebe alves", "Calebe@alves", "Calebe Alves "
    };

    for (const string &nome: nomesInvalidos) {
        smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, nome);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Kaio Rodrigues");


    // =========================================================================
    // 2. VALIDACAO DE EMAIL (Compartilhado com Gerente)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Email (Padrao: AAAA@BBBB.CCC)");

    // A. Casos Invalidos
    vector<string> emailsInvalidos = {
        "", "Cb@gmail.com",
        "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com",
        "calebe clves@gmail.com", "calebe  clves@gmail.com", ".cb@gmail.com", ".-cb@gmail.com",
        "c--b@gmail.com", "c..b@gmail.com",
        "calebeclves@123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com"
    };

    for (const string &email: emailsInvalidos) {
        smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, email);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "luanfreitas@gmai.com");

    // =========================================================================
    // 3. VALIDACAO DE ENDERECO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "3. Validacao de Endereco (1 a 20 caracteres alfanumericos, inclui . e espacos)");

    // A. Casos Invalidos
    vector<string> enderecosInvalidos = {
        "", "Endereco com Caractere Invalido!"
    };

    for (const string &endereco: enderecosInvalidos) {
        smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, endereco);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Qd.52 Cs.02 Comercial DelLago");

    // =========================================================================
    // 4. VALIDACAO DE CARTAO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Cartao (16 digitos numericos)");

    // A. Casos Invalidos
    vector<string> cartoesInvalidos = {
        "", "123456789012345", "12345678901234567", "123456789012A456"
    };

    for (const string &cartao: cartoesInvalidos) {
        smoke_test.testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, cartao);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "1234567890123456");
}

//------------------------------------------------------------------------------------------------------------------
string TestesHospede::nomeDoTeste() const {
    return "Teste de Entidade: Hospede";
}

//------------------------------------------------------------------------------------------------------------------