//
// Created by caleb on 03/11/2025.
//

#include "GerenteTSV.hpp"
#include "Smoke_Tests.hpp"

//------------------------------------------------------------------------------------------------------------------
void GerenteTSV::executar() {
    SmokeTest smoke_test;
    Gerente g_teste;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE PERSISTENCIA: TSV");

    ConsoleFormatter::MostrarSeparadorCategoria("Validacao de Gerente TSV (SERIALIZACAO/DESSERIALIZACAO)");

    // Teste 1: Serializacao (Criar TSV)
    g_teste.setNome(Nome("Calebe"));
    g_teste.setEmail(Email("calebe.2324@gmail.com"));
    g_teste.setRamal(Ramal("22"));
    g_teste.setSenha(Senha("A1!b2"));

    // Caso 1 Valido (Serializacao)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido 1 (Criacao de TSV):");
    smoke_test.testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(),
                                     "GERENTE\tCalebe\tcalebe.2324@gmail.com\t22\tA1!b2");

    // Teste 2: Desserializacao (Ler TSV)
    Gerente g2;
    string dadosGerente = g_teste.getTSV();
    g2.setTSV(dadosGerente);

    // Caso 2 Valido (Leitura de TSV - Verifica se o objeto lido é igual ao original)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido 2 (Leitura de TSV):");
    smoke_test.testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(), g2.getTSV());
}

//------------------------------------------------------------------------------------------------------------------
string GerenteTSV::nomeDoTeste() const {
    return "Teste de Entidade: GerenteTSV";
}

//------------------------------------------------------------------------------------------------------------------