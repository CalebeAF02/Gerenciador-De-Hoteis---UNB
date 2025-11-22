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

// Testes de domínios
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

// Testes de entidades
#include "TesteGerente.hpp"
#include "TesteHospede.hpp"
#include "TesteHotel.hpp"
#include "TesteQuarto.hpp"
#include "TesteReserva.hpp"

// Controladoras de apresentação
#include "ControladoraApresentacaoAcessoGerente.hpp"
#include "ControladoraApresentacaoAcessoHospede.hpp"
#include "ControladoraApresentacaoAutenticavel.hpp"
#include "ControladoraApresentacaoGerente.hpp"
#include "ControladoraApresentacaoHospede.hpp"
#include "ControladoraApresentacaoHotel.hpp"
#include "ControladoraApresentacaoQuarto.hpp"
#include "ControladoraApresentacaoReserva.hpp"

// Controladoras de servico
#include "ControladoraServicoAutenticavel.hpp"
#include "ControladoraServicoGerente.hpp"
#include "ControladoraServicoHospede.hpp"
#include "ControladoraServicoHotel.hpp"
#include "ControladoraServicoQuarto.hpp"
#include "ControladoraServicoReserva.hpp"

// Controladoras de Persistencia
#include "ControladoraPersistenciaAutenticavel.hpp"
#include "ControladoraPersistenciaGerente.hpp"
#include "ControladoraPersistenciaHospede.hpp"
#include "ControladoraPersistenciaHotel.hpp"
#include "ControladoraPersistenciaQuarto.hpp"
#include "ControladoraPersistenciaReserva.hpp"
#include "ControladoraPersistenciaSolicitacaoHospedagem.hpp"


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

void executarSistema(ControladoraApresentacaoAcessoGerente *acessoGerente,
                     ControladoraApresentacaoAcessoHospede *acessoHospede) {
    BancoDeDados banco;
    banco.iniciar();

    Sistema sistema(acessoGerente, acessoHospede);
    sistema.iniciar();
}

void burlandoSistema() {
    BancoDeDados banco;
    banco.iniciar();

    SistemaHacker sistema_hacker;
    sistema_hacker.iniciar();
}

int main() {
    // Instanciando todas as controladoras
    ControladoraApresentacaoAcessoGerente acessoGerente;
    ControladoraApresentacaoAutenticavel autenticador;
    ControladoraApresentacaoGerente apresentacaoGerente;
    ControladoraApresentacaoHospede apresentacaoHospede;
    ControladoraApresentacaoHotel apresentacaoHotel;
    ControladoraApresentacaoQuarto apresentacaoQuarto;
    ControladoraApresentacaoReserva apresentacaoReserva;

    ControladoraApresentacaoAcessoHospede acessoHospede;

    // Injetando dependências
    acessoGerente.setControladoraApresentacao(&autenticador);
    acessoGerente.setControladoraApresentacao(&apresentacaoGerente);
    acessoGerente.setControladoraApresentacao(&apresentacaoHospede);
    // aqui é válido porque a classe implementa a interface
    acessoGerente.setControladoraApresentacao(&apresentacaoHotel);
    acessoGerente.setControladoraApresentacao(&apresentacaoQuarto);
    acessoGerente.setControladoraApresentacao(&apresentacaoReserva);

    acessoHospede.setControladoraApresentacao(&apresentacaoHospede);

    // Instanciando serviços e persistências
    ControladoraServicoAutenticavel servAutenticavel;
    ControladoraPersistenciaAutenticavel perAutenticavel;
    servAutenticavel.setControladoraPersistencia(&perAutenticavel);
    autenticador.setControladoraServicoAutenticavel(&servAutenticavel);

    ControladoraServicoGerente servGerente;
    ControladoraPersistenciaGerente perGerente;
    servGerente.setControladoraPersistencia(&perGerente);
    apresentacaoGerente.setControladoraServicoGerente(&servGerente);

    ControladoraServicoHospede servHospede;
    ControladoraPersistenciaHospede perHospede;
    servHospede.setControladoraPersistencia(&perHospede);
    apresentacaoHospede.setControladoraServicoHospede(&servHospede);

    ControladoraServicoHotel servHotel;
    ControladoraPersistenciaHotel perHotel;
    servHotel.setControladoraPersistencia(&perHotel);
    apresentacaoHotel.setControladoraServicoHotel(&servHotel);

    ControladoraServicoQuarto servQuarto;
    ControladoraPersistenciaQuarto perQuarto;
    servQuarto.setControladoraPersistencia(&perQuarto);
    apresentacaoQuarto.setControladoraServicoQuarto(&servQuarto);

    ControladoraServicoReserva servReserva;
    ControladoraPersistenciaReserva perReserva;
    servReserva.setControladoraPersistencia(&perReserva);
    apresentacaoReserva.setControladoraServicoReserva(&servReserva);

    // Escolhendo modo de execução
    switch (MODO_ATUAL) {
        case MODO_SMOKE: {
            executandoNovoSmoke();
            break;
        }
        case MODO_PRODUCAO: {
            executarSistema(&acessoGerente, &acessoHospede);
            break;
        }
        case MODO_HACKER: {
            burlandoSistema();
            break;
        }
    }
    return 0;
}

/*
 * Edicoes a fazer :
 *
 * Funcionalidades do sistema
 *
 * Conta = LER; EDITAR; EXCLUIR;
 * Hotel = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hoteis);
 * Quarto = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os quartos);
 * Reserva = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todas as reservas);
 * Hospede = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hospedes);
 *
 * 1) Nao pode haver conflitos nas reservas!
 * 2) Nao pode editar as informacoes em CODIGO, que apresenta chave de registro "PK"!
 * 3) Nao permite exclusoes que gerem inconcistencias!
 */