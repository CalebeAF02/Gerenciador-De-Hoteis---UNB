//
// Created by caleb on 02/11/2025.
//

#include "TestandoSmoke.hpp"
#include <memory>

#include "../testes_dominios/TestesData.hpp"
#include "testes_dominios/TesteCapacidade.hpp"
#include "testes_dominios/TesteCartao.hpp"
#include "testes_dominios/TesteCodigo.hpp"
#include "testes_dominios/TesteDinheiro.hpp"
#include "testes_dominios/TesteEmail.hpp"
#include "testes_dominios/TesteEndereco.hpp"
#include "testes_dominios/TesteNome.hpp"
#include "testes_dominios/TesteNumero.hpp"
#include "testes_dominios/TesteRamal.hpp"
#include "testes_dominios/TesteSenha.hpp"
#include "testes_dominios/TesteTelefone.hpp"

#include "testes_entidades/TesteGerente.hpp"
#include "testes_entidades/TesteHospede.hpp"
#include "testes_entidades/TesteHotel.hpp"
#include "testes_entidades/TesteQuarto.hpp"
#include "testes_entidades/TesteReserva.hpp"

using namespace std;

void TestandoSmoke::ExecutarSmokeTest() {
    ConsoleFormatter::MostrarTituloEmCaixa("TESTE FUMACA (SMOKE TEST) - EXECUCAO INTEGRADA");

    // Lista de testes_dominios
    vector<unique_ptr<InterfaceDeTeste> > testes_dominios;
    //------------------------------------------------------------------------------------------------------------------
    testes_dominios.push_back(make_unique<TesteNome>());
    testes_dominios.push_back(make_unique<TesteEmail>());
    testes_dominios.push_back(make_unique<TesteRamal>());
    testes_dominios.push_back(make_unique<TesteSenha>());
    testes_dominios.push_back(make_unique<TesteEndereco>());
    testes_dominios.push_back(make_unique<TesteCartao>());
    testes_dominios.push_back(make_unique<TesteTelefone>());
    testes_dominios.push_back(make_unique<TesteCodigo>());
    testes_dominios.push_back(make_unique<TesteNumero>());
    testes_dominios.push_back(make_unique<TesteCapacidade>());
    testes_dominios.push_back(make_unique<TesteDinheiro>());
    testes_dominios.push_back(make_unique<TestesData>());

    // Executa todos os testes_dominios
    for (unique_ptr<InterfaceDeTeste> &teste: testes_dominios) {
        cout << "\nExecutando: " << teste->nomeDoTeste() << endl;
        teste->executar();
    }
    //------------------------------------------------------------------------------------------------------------------
    /*
    // Lista de testes_entidades
    vector<unique_ptr<InterfaceDeTeste> > testes_entidades;

    testes_entidades.push_back(make_unique<TesteGerente>());
    testes_entidades.push_back(make_unique<TesteHospede>());
    testes_entidades.push_back(make_unique<TesteHotel>());
    testes_entidades.push_back(make_unique<TesteQuarto>());
    testes_entidades.push_back(make_unique<TesteReserva>());

    // Executa todos os testes_entidades
    for (unique_ptr<InterfaceDeTeste> &teste: testes_entidades) {
        cout << "\nExecutando: " << teste->nomeDoTeste() << endl;
        teste->executar();
    }
    */
    //------------------------------------------------------------------------------------------------------------------
}

//------------------------------------------------------------------------------------------------------------------