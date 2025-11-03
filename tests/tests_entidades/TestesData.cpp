//
// Created by caleb on 03/11/2025.
//

#include "TestesData.hpp"
#include "Smoke_Tests.hpp"

void TestesData::executar() {
    SmokeTest smoke_test;
    Data data1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: DATA (Membros internos)");

    // =========================================================================
    // 1. VALIDACAO DE DIA, MES, ANO (Membros internos)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Validacao de Dia, Mes, Ano");

    // A. Casos Invalidos
    vector<int> diasInvalidos = {40, 0, -5};
    vector<int> mesesInvalidos = {22, 0, -1};
    vector<int> anosInvalidos = {5000, 1999, 10000};

    ConsoleIO::PrintMensagem("-> Testando Dias Invalidos:");
    for (const int &dia: diasInvalidos) {
        smoke_test.testarValidadorDia(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, dia);
    }

    ConsoleIO::PrintMensagem("-> Testando Meses Invalidos:");
    for (const int &mes: mesesInvalidos) {
        smoke_test.testarValidadorMes(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, mes);
    }

    ConsoleIO::PrintMensagem("-> Testando Anos Invalidos:");
    for (const int &ano: anosInvalidos) {
        smoke_test.testarValidadorAno(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, ano);
    }

    // B. Caso Valido (Apenas 1 de cada)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Casos Validos Unicos (Referencia Correta):");
    smoke_test.testarValidadorDia(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 23);
    smoke_test.testarValidadorMes(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 3);
    smoke_test.testarValidadorAno(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 2002);
}

//------------------------------------------------------------------------------------------------------------------
string TestesData::nomeDoTeste() const {
    return "Teste de Entidade: Data";
}

//------------------------------------------------------------------------------------------------------------------