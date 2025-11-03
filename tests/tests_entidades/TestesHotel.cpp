#include "TestesHotel.hpp"
#include "Smoke_Tests.hpp"

void TestesHotel::executar() {
    SmokeTest smoke_test;
    Hotel hotel1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: HOTEL");

    // =========================================================================
    // 1. VALIDACAO DE NOME
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "1. Validacao de Nome (4 a 30 caracteres, 1o maiusculo, Apenas 1 espaco)");

    // A. Casos Invalidos
    vector<string> nomesInvalidos = {
        "", "Cb", "Calebe Alves Freitas Madeira Alves", "Calebe  Alves",
        "calebe alves", "Calebe alves", "Calebe@alves", "Calebe Alves "
    };

    for (const string &nome: nomesInvalidos) {
        smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, nome);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Luan Freitas");

    // =========================================================================
    // 2. VALIDACAO DE ENDERECO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Endereco");

    // A. Casos Invalidos
    vector<string> enderecosInvalidos = {
        ""
    };

    for (const string &endereco: enderecosInvalidos) {
        smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, endereco);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Qd.52 Cs.02 Comercial DelLago");

    // =========================================================================
    // 3. VALIDACAO DE TELEFONE
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Telefone (12 a 16 digitos, iniciando com '+')");

    // A. Casos Invalidos
    vector<string> telefonesInvalidos = {
        "", "5161993009537", "+123456789987654321", "+5161A993009537", "+123"
    };

    for (const string &telefone: telefonesInvalidos) {
        smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, telefone);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "+5161993009537");

    // =========================================================================
    // 4. VALIDACAO DE CODIGO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Codigo (10 caracteres, alfanumerico)");

    // A. Casos Invalidos
    vector<string> codigosInvalidos = {
        "", "5161993009537", "abcdedghij9987654321", "abcde12!34"
    };

    for (const string &codigo: codigosInvalidos) {
        smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, codigo);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "1234567890");
}

//------------------------------------------------------------------------------------------------------------------
string TestesHotel::nomeDoTeste() const {
    return "Teste de Entidade: Hotel";
}

//------------------------------------------------------------------------------------------------------------------