#include "Smoke_Tests.hpp"
#include "sistema/Sistema.hpp"

#include <iostream>
#include <string>
#include "sqlite3.h"

#include "TextoApresentacao.hpp"
#include "interface_tests/TestsModulares.hpp"

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

using namespace std;

#define MODO_TESTES 0
#define MODO_PRODUCAO 1
#define MODO_SMOKE 2

#define MODO_ATUAL MODO_TESTES

void executarSmokeTests() {
    SmokeTest::testarEntradas();
}

void executarSistema() {
    BancoDeDados banco;
    banco.criandoBancoDeDados();

    Sistema sistema;
    sistema.menuSistema();
}

int main() {
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
    switch (MODO_ATUAL) {
        case MODO_SMOKE: {
            SmokeTest::testarEntradas();

            BancoDeDados bancoModoSmokeTestes;
            bancoModoSmokeTestes.criandoBancoDeDados();

            Sistema sistemaModoSmokeTestes;
            sistemaModoSmokeTestes.menuSistema();

            /*
            TextoApresentacao::MostrarTituloEmCaixa("Login Programado");
            cout << "Entrada :" << "calebe@gmail.com" << endl << "Senha :" << "A1#a1" << endl << endl;

            if (sistema.fazerLoginSistema("calebe@gmail.com", "A1#a1"))
            {
                cout << endl;
                sistema.menuSistema();
            };
            */
            break;
        }
        case MODO_TESTES: {
            executarTestsModulares();

            BancoDeDados bancoModoTestes;
            bancoModoTestes.criandoBancoDeDados();

            Sistema sistemaModoTestes;
            sistemaModoTestes.menuSistema();

            break;
        }
        case MODO_PRODUCAO: {
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
