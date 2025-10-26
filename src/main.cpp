#include "Smoke_Tests.h"
#include "sistema/Sistema.h"

#include <iostream>
#include <string>
#include "sqlite/sqlite3.h"

#include "../include/utilitarios/TextoApresentacao.h"
#include "interface_tests/TestsModulares.h"

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

using namespace std;

#define MODO_TESTES 0
#define MODO_PRODUCAO 1
#define MODO_SMOKE 2

#define MODO_ATUAL MODO_TESTES

void executarSmokeTests()
{
    SmokeTest::testarEntradas();
}

void executarSistema()
{
    Sistema sistema;
    sistema.criandoBancoDeDados();
    sistema.menuSistema();
}

int main()
{
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
    switch (MODO_ATUAL)
    {
    case MODO_SMOKE:
        {
            SmokeTest::testarEntradas();
            Sistema sistemaModoSmokeTestes;

            sistemaModoSmokeTestes.criandoBancoDeDados();

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
        }
    case MODO_TESTES:
        {
            executarTestsModulares();
            Sistema sistemaModoTestes;

            sistemaModoTestes.criandoBancoDeDados();

            sistemaModoTestes.menuSistema();
            break;
        }
    case MODO_PRODUCAO:
        {
            Sistema sistemaProducao;
            while (sistemaProducao.getExecutandoSistema())
            {
                sistemaProducao.rodandoSistema();
            }
            break;
        }
    }
    return 0;
};