//
// Created by caleb on 25/10/2025.
//


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

using namespace std;

void executarTestsModulares() {
    // Lista de testes
    vector<unique_ptr<InterfaceDeTeste> > testes;

    // Adiciona cada teste à lista
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

    testes.push_back(make_unique<TestsGerente>());
    testes.push_back(make_unique<TestsHospede>());
    testes.push_back(make_unique<TestsHotel>());
    testes.push_back(make_unique<TestsQuarto>());
    testes.push_back(make_unique<TestsReserva>());


    // Adicione os outros testes aqui...

    // Executa todos os testes
    for (std::unique_ptr<InterfaceDeTeste> &teste: testes) {
        std::cout << "\nExecutando: " << teste->nomeDoTeste() << std::endl;
        teste->executar();
    }
}