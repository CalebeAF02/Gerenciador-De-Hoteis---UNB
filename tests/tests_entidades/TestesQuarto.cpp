#include "TestesQuarto.hpp"
#include "Smoke_Tests.hpp"

void TestesQuarto::executar() {
    SmokeTest smoke_test;
    Quarto quarto1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: QUARTO");

    // =========================================================================
    // 1. VALIDACAO DE NUMERO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Validacao de Numero (3 digitos, > 000)");

    // A. Casos Invalidos
    vector<string> numerosInvalidos = {
        "-300", "000", "Ab$", ""
    };

    for (const string &numero: numerosInvalidos) {
        smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, numero);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "001");

    // =========================================================================
    // 2. VALIDACAO DE CAPACIDADE
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Capacidade (1 a 4 pessoas)");

    // A. Casos Invalidos
    vector<int> capacidadesInvalidas = {
        0, 5, -1
    };

    for (const int &capacidade: capacidadesInvalidas) {
        smoke_test.testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, capacidade);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 4);

    // =========================================================================
    // 3. VALIDACAO DE DIARIA (DINHEIRO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Diaria (Valor inteiro positivo)");

    // A. Casos Invalidos
    vector<int> diariasInvalidas = {
        -50, 0
    };

    for (const int &diaria: diariasInvalidas) {
        smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, diaria);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 120000);

    // =========================================================================
    // 4. VALIDACAO DE RAMAL
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Ramal (2 digitos, 10 a 99)");

    // A. Casos Invalidos
    vector<string> ramaisInvalidos = {
        "0", "100", ""
    };

    for (const string &ramal: ramaisInvalidos) {
        smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, ramal);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "10");
}

//------------------------------------------------------------------------------------------------------------------
string TestesQuarto::nomeDoTeste() const {
    return "Teste de Entidade: Quarto";
}

//------------------------------------------------------------------------------------------------------------------