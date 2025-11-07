#include "SmokeTeste.hpp"
#include "sistema/Sistema.hpp"

#include <iostream>
#include <string>
#include "sqlite3.h"
#include "TestandoSmoke.hpp"
#include "../include/sistema/utilitarios/console/ConsoleFormatter.hpp"

#include "interface_testes/InterfaceDeTestes.hpp"
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

#define MODO_PRODUCAO 0
#define MODO_SMOKE 1

#define MODO_ATUAL MODO_SMOKE

void executandoNovoSmoke() {
    TestandoSmoke teste;
    teste.ExecutarSmokeTest();
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