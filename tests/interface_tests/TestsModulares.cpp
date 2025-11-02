//
// Created by caleb on 25/10/2025.
//


#include "interface_tests/InterfaceDeTeste.hpp"

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

#include "tests_entidades/TestsGerente.hpp"
#include "tests_entidades/TestsHospede.hpp"
#include "tests_entidades/TestsHotel.hpp"
#include "tests_entidades/TestsQuarto.hpp"
#include "tests_entidades/TestsReserva.hpp"

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

    //testes.push_back(make_unique<TestsGerente>());
    //testes.push_back(make_unique<TestsHospede>());
    testes.push_back(make_unique<TestsHotel>());
    testes.push_back(make_unique<TestsQuarto>());
    testes.push_back(make_unique<TestsReserva>());


    // Adicione os outros testes aqui...

    // Executa todos os testes
    for (unique_ptr<InterfaceDeTeste> &teste: testes) {
        cout << "\nExecutando: " << teste->nomeDoTeste() << endl;
        teste->executar();
    }
}
