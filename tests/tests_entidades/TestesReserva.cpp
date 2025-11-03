#include "TestesReserva.hpp"
#include "Smoke_Tests.hpp"

void TestesReserva::executar() {
    SmokeTest smoke_test;
    Reserva reserva1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: RESERVA");

    // =========================================================================
    // 1. VALIDACAO DE DATA DE CHEGADA (STRING)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Validacao de Data de Chegada (DD/MM/AAAA)");

    // A. Casos Invalidos
    vector<string> datasInvalidas = {
        "33/55/5000", "-20/-30/-1000", "01/01/1999", "30/02/2023", ""
    };

    for (const string &data: datasInvalidas) {
        smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, data);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "23/03/2002");


    // =========================================================================
    // 2. VALIDACAO DE DATA DE PARTIDA (STRING)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Data de Partida (DD/MM/AAAA)");

    // A. Casos Invalidos
    vector<string> partidasInvalidas = {
        "33/55/5000", "-20/-30/-1000", "01/01/1999"
    };

    for (const string &data: partidasInvalidas) {
        smoke_test.testarValidadorPartida(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, data);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "01/03/2022");


    // =========================================================================
    // 3. VALIDACAO DE DINHEIRO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Dinheiro (Valor inteiro positivo)");

    // A. Casos Invalidos
    vector<int> dinheirosInvalidos = {
        -70, 0
    };

    for (const int &dinheiro: dinheirosInvalidos) {
        smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, dinheiro);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, 2000);

    // =========================================================================
    // 4. VALIDACAO DE CODIGO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Codigo (10 caracteres, alfanumerico)");

    // A. Casos Invalidos
    vector<string> codigosInvalidos = {
        "", "12345678901215168468", "abcde!fghi"
    };

    for (const string &codigo: codigosInvalidos) {
        smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, codigo);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "1234567890");
}

//------------------------------------------------------------------------------------------------------------------
string TestesReserva::nomeDoTeste() const {
    return "Teste de Entidade: Reserva";
}

//------------------------------------------------------------------------------------------------------------------