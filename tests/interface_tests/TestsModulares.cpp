//
// Created by caleb on 25/10/2025.
//

#include "TestsBase.h"

#include "interface_tests/InterfaceDeTeste.h"

#include "tests_dominios/TestsCapacidade.h"
#include "tests_dominios/TestsCartao.h"
#include "tests_dominios/TestsCodigo.h"
#include "tests_dominios/TestsData.h"
#include "tests_dominios/TestsDinheiro.h"
#include "tests_dominios/TestsEmail.h"
#include "tests_dominios/TestsEndereco.h"
#include "tests_dominios/TestsNome.h"
#include "tests_dominios/TestsNumero.h"
#include "tests_dominios/TestsRamal.h"
#include "tests_dominios/TestsSenha.h"
#include "tests_dominios/TestsTelefone.h"

#include "tests_entidades/TestsGerente.h"
#include "tests_entidades/TestsHospede.h"
#include "tests_entidades/TestsHotel.h"
#include "tests_entidades/TestsQuarto.h"
#include "tests_entidades/TestsReserva.h"

#include <vector>
#include <memory> // para usar smart pointers

#include "TestsSolicitacaoHospedagem.h"

using namespace std;

void executarTestsModulares()
{
    // Lista de testes
    std::vector<std::unique_ptr<TestsBase>> testes;

    // Adiciona cada teste à lista
    testes.push_back(std::make_unique<TestsNome>());
    /*
    testes.push_back(std::make_unique<TestsEmail>());
    testes.push_back(std::make_unique<TestsRamal>());
    testes.push_back(std::make_unique<TestsSenha>());
    testes.push_back(std::make_unique<TestsEndereco>());
    testes.push_back(std::make_unique<TestsCartao>());
    testes.push_back(std::make_unique<TestsTelefone>());
    testes.push_back(std::make_unique<TestsCodigo>());
    testes.push_back(std::make_unique<TestsNumero>());
    testes.push_back(std::make_unique<TestsCapacidade>());
    testes.push_back(std::make_unique<TestsDinheiro>());
    testes.push_back(std::make_unique<TestsData>());


    testes.push_back(std::make_unique<TestsGerente>());
    testes.push_back(std::make_unique<TestsHospede>());
    testes.push_back(std::make_unique<TestsHotel>());
    testes.push_back(std::make_unique<TestsQuarto>());
    testes.push_back(std::make_unique<TestsReserva>());
    */
    //testes.push_back(std::make_unique<TestsSolicitacaoHospedagem>());

    // Adicione os outros testes aqui...

    // Executa todos os testes
    for (const auto& teste : testes)
    {
        std::cout << "\nExecutando: " << teste->nome() << std::endl;
        teste->executar();
    }
}
