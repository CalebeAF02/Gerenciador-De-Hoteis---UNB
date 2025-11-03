//
// Created by caleb on 02/11/2025.
//

#include "TestandoSmoke.hpp"
#include <memory>

#include "tests_dominios/TestsCapacidade.hpp"
#include "tests_dominios/TestsCartao.hpp"
#include "tests_dominios/TestsCodigo.hpp"
#include "tests_dominios/TestsData.hpp"
#include "tests_dominios/TestsDinheiro.hpp"
#include "tests_dominios/TestsEmail.hpp"
#include "tests_dominios/TestsEndereco.hpp"
#include "tests_dominios/TestsNome.hpp"
#include "tests_dominios/TestsNumero.hpp"
#include "tests_dominios/TestsRamal.hpp"
#include "tests_dominios/TestsSenha.hpp"
#include "tests_dominios/TestsTelefone.hpp"

#include "tests_entidades/TestesGerente.hpp"
#include "tests_entidades/TestesHospede.hpp"
#include "tests_entidades/TestesHotel.hpp"
#include "tests_entidades/TestesQuarto.hpp"
#include "tests_entidades/TestesReserva.hpp"

using namespace std;

void TestandoSmoke::ExecutarSmokeTest() {
    ConsoleFormatter::MostrarTituloEmCaixa("TESTE FUMACA (SMOKE TEST) - EXECUCAO INTEGRADA");

    // Lista de testes
    vector<unique_ptr<InterfaceDeTeste> > testes;

    /*
    testes.push_back(make_unique<TestsNome>());
    testes.push_back(make_unique<TestsEmail>());
    testes.push_back(make_unique<TestsRamal>());
    testes.push_back(make_unique<TestsSenha>());
    testes.push_back(make_unique<TestsEndereco>());
    testes.push_back(make_unique<TestsCartao>());
    testes.push_back(make_unique<TestsTelefone>());
    testes.push_back(make_unique<TestsCodigo>());
    testes.push_back(make_unique<TestsNumero>());
    testes.push_back(make_unique<TestsCapacidade>());
    testes.push_back(make_unique<TestsDinheiro>());
    testes.push_back(make_unique<TestsData>());
    */

    testes.push_back(make_unique<TestesGerente>());
    testes.push_back(make_unique<TestesHospede>());
    testes.push_back(make_unique<TestesHotel>());
    testes.push_back(make_unique<TestesQuarto>());
    testes.push_back(make_unique<TestesReserva>());

    // Executa todos os testes
    for (unique_ptr<InterfaceDeTeste> &teste: testes) {
        cout << "\nExecutando: " << teste->nomeDoTeste() << endl;
        teste->executar();
    }
}

//------------------------------------------------------------------------------------------------------------------

void TestandoSmoke::ResultadoTSV(string titulo, string contador) {
    // Este metodo agora simplesmente delega a responsabilidade para a InterfaceDeTeste
    InterfaceDeTeste::mostrarSumarioGeral();
}

//------------------------------------------------------------------------------------------------------------------