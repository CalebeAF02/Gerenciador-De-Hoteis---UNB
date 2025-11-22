//
// Created by caleb on 15/11/2025.
//
#include "ControladoraApresentacaoAcessoGerente.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoAcessoGerente::setControladoraApresentacao(
        InterfaceApresentacaoAutenticavel *apresentacao_autenticavel) {
        this->apresentacao_autenticavel = apresentacao_autenticavel;
    }

    void ControladoraApresentacaoAcessoGerente::setControladoraApresentacao(
        InterfaceApresentacaoGerente *apresentacao_gerente) {
        this->apresentacao_gerente = apresentacao_gerente;
    }

    void ControladoraApresentacaoAcessoGerente::setControladoraApresentacao(
        InterfaceApresentacaoHospede *apresentacao_hospede) {
        this->apresentacao_hospede = apresentacao_hospede;
    }

    void ControladoraApresentacaoAcessoGerente::setControladoraApresentacao(
        InterfaceApresentacaoHotel *apresentacao_hotel) {
        this->apresentacao_hotel = apresentacao_hotel;
    }

    void ControladoraApresentacaoAcessoGerente::setControladoraApresentacao(
        InterfaceApresentacaoQuarto *apresentacao_quarto) {
        this->apresentacao_quarto = apresentacao_quarto;
    }

    void ControladoraApresentacaoAcessoGerente::setControladoraApresentacao(
        InterfaceApresentacaoReserva *apresentacao_reserva) {
        this->apresentacao_reserva = apresentacao_reserva;
    }

    void ControladoraApresentacaoAcessoGerente::exibirMenu() {
        bool executando = true;

        Menu menu;

        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_CRIAR_UM_GERENTE = menu.adcionarItens("Criar Gerente");
        const int OPCAO_FAZER_LOGIN = menu.adcionarItens("Fazer Login");

        while (executando) {
            int opcao = menu.executa("Faca o acesso para liberar os servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                executando = false;
                IO::Println("Voltando a selecao de usuario!");
            } else if (opcao == OPCAO_CRIAR_UM_GERENTE) {
                this->apresentacao_gerente->criar();
            } else if (opcao == OPCAO_FAZER_LOGIN) {
                if (this->apresentacao_autenticavel->autenticar()) {
                    this->estaAutenticado = true;
                }
                if (this->estaAutenticado) {
                    IO::Println("Agora Voce Possui Super-Poderes");
                    exibirMenuGerenciador();
                }
            } else {
                IO::Println("Opcao Invalida!");
            }
        }
    }

    void ControladoraApresentacaoAcessoGerente::exibirMenuGerenciador() {
        Menu menu;
        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
        const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
        const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
        const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
        const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
        const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

        while (estaAutenticado) {
            int opcao = menu.executa("Seja bem vindo a central de servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                this->estaAutenticado = false;
                IO::Println("Voce Saiu da Central de servicos e foi deslogado!");
            } else if (opcao == OPCAO_GERENCIE_GERENTES) {
                apresentacao_gerente->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_HOSPEDES) {
                //ControladorInterfaceHospede servicosHospede;
                //servicosHospede.exibirMenuCRUD();
                apresentacao_hospede->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_HOTEIS) {
                //ControladorInterfaceHotel servicosHotel;
                //servicosHotel.exibirMenuCRUD();
                apresentacao_hotel->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_QUARTOS) {
                //ControladorInterfaceQuarto servicosQuarto;
                //servicosQuarto.exibirMenuCRUD();
                apresentacao_quarto->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_RESERVAS) {
                //ControladorInterfaceReserva servicosReserva;
                //servicosReserva.exibirMenuCRUD();
                apresentacao_reserva->exibirMenuCRUD();
            } else if (opcao == OPCAO_AVALIAR_SOLICITACOES) {
                //ControladorInterfaceHospede servicosHospede;
                //servicosHospede.avaliarSolicitacoes();
                //interface_apresentacao_solicitacao_hospedagem->exibirMenuCRUD();
            } else {
                IO::Println("Opcao Invalida!");
            }
        }
    }
}