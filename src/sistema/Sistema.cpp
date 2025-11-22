//
// Created by caleb on 28/09/2025.
//

#include "Sistema.hpp"

#include "sqlite3.h"
#include "Versao.hpp"

namespace Hotelaria {
    Sistema::Sistema() {
    }


    void Sistema::iniciar() {
        IO::Println("Versao " + Versao::getVersaoCompleta() + " Compilado em " + Versao::getData());

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

        this->apresentacao_acesso_gerente = &acessoGerente;
        this->apresentacao_acesso_hospede = &acessoHospede;

        while (executando) {
            exibirMenu();
        }
    }

    void Sistema::exibirMenu() {
        Menu menu;

        int OPCAO_SAIR_DO_SISTEMA = menu.adcionarItens("Sair");
        int OPCAO_ENTRAR_COMO_GERENTE = menu.adcionarItens("Entrar como Gerente");
        int OPCAO_ENTRAR_COMO_HOSPEDE = menu.adcionarItens("Entrar como Hospede");

        while (executando) {
            int opcao = menu.executa("Seja bem vindo ao Gerenciador de Hoteis");

            if (opcao == OPCAO_SAIR_DO_SISTEMA) {
                this->executando = false;
                IO::Println("Encerrando o sistema...");
            } else if (opcao == OPCAO_ENTRAR_COMO_GERENTE) {
                this->apresentacao_acesso_gerente->exibirMenu();
            } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
                this->apresentacao_acesso_hospede->exibirMenu();
            }
        }
    }

    void Sistema::setGerenteID(int valor) {
        this->gerente_id = valor;
    }

    void Sistema::setGerenteAutenticado(bool valor) {
        this->gerente_autenticado = valor;
    }

    bool Sistema::getGerenteID() {
        return gerente_id;
    }

    bool Sistema::getGerenteAutenticado() {
        return gerente_autenticado;
    }
}