#include "Sistema.hpp"
#include "SistemaHacker.hpp"

#include <iostream>
#include <string>
#include "sqlite3.h"

#include "Formato.hpp"

#include "SmokeTeste.hpp"
#include "TestandoSmoke.hpp"
#include "InterfaceDeTestes.hpp"
#include "BancoDeDados.hpp"
#include "TesteCapacidade.hpp"
#include "TesteCartao.hpp"
#include "TesteCodigo.hpp"
#include "TesteDinheiro.hpp"
#include "TesteEmail.hpp"
#include "TesteEndereco.hpp"
#include "TesteNome.hpp"
#include "TesteNumero.hpp"
#include "TesteRamal.hpp"
#include "TesteSenha.hpp"
#include "TesteTelefone.hpp"

#include "TesteGerente.hpp"
#include "TesteHospede.hpp"
#include "TesteHotel.hpp"
#include "TesteQuarto.hpp"
#include "TesteReserva.hpp"

#include "InterfaceApresentacaoAutenticavel.hpp"
#include "InterfaceApresentacaoGerente.hpp"
#include "ControladoraApresentacaoAutenticavel.hpp"
#include "ControladoraApresentacaoGerente.hpp"

using namespace std;
using namespace Hotelaria;

#define MODO_PRODUCAO 0
#define MODO_SMOKE 1
#define MODO_HACKER 2

#define MODO_ATUAL MODO_PRODUCAO

void executandoNovoSmoke() {
    TestandoSmoke teste;
    teste.executarSmokeTest();
    InterfaceDeTeste::mostrarRelatorioDeTestes();
}

void executarSistema() {
    BancoDeDados banco;
    banco.iniciar();

    Hotelaria::Sistema sistema;
    sistema.iniciar();
}

void burlandoSistema() {
    BancoDeDados banco;
    banco.iniciar();

    SistemaHacker sistema_hacker;
    sistema_hacker.iniciar();
}

int main() {
    switch (MODO_ATUAL) {
        case MODO_SMOKE: {
            executandoNovoSmoke();
            break;
        }
        case MODO_PRODUCAO: {
            executarSistema();
            break;
        }
        case MODO_HACKER: {
            burlandoSistema();
            break;
        }
    }
    return 0;
}; /*
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