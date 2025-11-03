#include "Smoke_Tests.hpp"
#include "sistema/Sistema.hpp"

#include <iostream>
#include <string>
#include "sqlite3.h"
#include "TestandoSmoke.hpp"
#include "../include/sistema/utilitarios/console/ConsoleFormatter.hpp"

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

#include "tests_entidades/TestesGerente.hpp"
#include "tests_entidades/TestesHospede.hpp"
#include "tests_entidades/TestesHotel.hpp"
#include "tests_entidades/TestesQuarto.hpp"
#include "tests_entidades/TestesReserva.hpp"

using namespace std;

#define MODO_PRODUCAO 0
#define MODO_SMOKE 1

#define MODO_ATUAL MODO_SMOKE

void executandoNovoSmoke() {
    TestandoSmoke testando_smoke;
    testando_smoke.ExecutarSmokeTest();
}

void executarSistema() {
    BancoDeDados banco;
    banco.criandoBancoDeDados();

    Sistema sistema;
    sistema.menuSistema();
}

int main() {
    switch (MODO_ATUAL) {
        case MODO_SMOKE: {
            //SmokeTest::testarEntradas();

            executandoNovoSmoke();
            InterfaceDeTeste::mostrarSumarioGeral();

            BancoDeDados bancoModoSmokeTestes;
            bancoModoSmokeTestes.criandoBancoDeDados();

            Sistema sistemaModoSmokeTestes;
            sistemaModoSmokeTestes.menuSistema();
            break;
        }
        case MODO_PRODUCAO: {
            InterfaceDeTeste::mostrarSumarioGeral();

            BancoDeDados bancoModoTestes;
            bancoModoTestes.criandoBancoDeDados();

            Sistema sistemaProducao;
            while (sistemaProducao.getExecutandoSistema()) {
                sistemaProducao.rodandoSistema();
            }
            break;
        }
    }
    return 0;
};
/*
 * Edicoes a fazer :
 *
 * Funcionalidades do sistema
 *
 * Conta = LER; EDITAR; EXCLUIR;
 * Hotel = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hoteis;
 * Quarto = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os quartos;
 * Reserva = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos as reservas;
 * Hospede = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hospedes;
 *
 * 1) Nao pode haver conflitos nas reservas!
 *
 * 2) Nao pode editar as informacoes em CODIGO, que apresenta chave de registro "PK"!
 *
 * 3) Nao permite exclusoes que gerem inconcistencias!
 *
 */