#include "Sistema.hpp"

#include <iostream>
#include <string>
#include "sqlite3.h"

#include "../libs/formato/Formato.hpp"
#include "SistemaHacker.hpp"

#include "../libs/teste/SmokeTeste.hpp"
#include "../testes/TestandoSmoke.hpp"
#include "../libs/teste/InterfaceDeTestes.hpp"

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

#include "InterfaceApresentacaoAutenticavel.hpp"
#include "InterfaceApresentacaoPessoal.hpp"
#include "ControladoraApresentacaoAutenticavel.hpp"
#include "ControladoraApresentacaoPessoal.hpp"

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