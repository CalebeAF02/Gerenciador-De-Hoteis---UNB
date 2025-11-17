//
// Created by caleb on 15/11/2025.
//
#include "ControladoraApresentacaoAcessoGerente.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoAcessoGerente::setControladoraServicoAcesso(
        InterfaceServicoAcesso *controladora_servico_acesso_gerente) {
        this->controladora_servico_acesso_gerente = controladora_servico_acesso_gerente;
    }

    void ControladoraApresentacaoAcessoGerente::exibirMenu() {
        bool executando = true;

        Menu menu;
        Email emailObj;

        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_CRIAR_UM_GERENTE = menu.adcionarItens("Criar Gerente");
        const int OPCAO_FAZER_LOGIN = menu.adcionarItens("Fazer Login");

        while (executando) {
            int opcao = menu.executa("Faca o acesso para liberar os servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                executando = false;
                IO::Println("Voltando a selecao de usuario!");
            } else if (opcao == OPCAO_CRIAR_UM_GERENTE) {
                FabricaGerenciavel<ControladorInterfaceGerente> fabrica;
                fabrica.criar(); // apenas cria o gerente, sem abrir o menu
            } else if (opcao == OPCAO_FAZER_LOGIN) {
                bool estaAutenticado = controladorGerente.autenticar(&emailObj);
                controladorGerente.setEstaAutenticado(estaAutenticado);
                if (estaAutenticado) {
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

        while (controladorGerente.getEstaAutenticado()) {
            int opcao = menu.executa("Seja bem vindo a central de servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                controladorGerente.sair();
                IO::Println("Voce Saiu da Central de servicos e foi deslogado!");
            } else if (opcao == OPCAO_GERENCIE_GERENTES) {
                controladorGerente.exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_HOSPEDES) {
                ControladorInterfaceHospede servicosHospede;
                servicosHospede.exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_HOTEIS) {
                ControladorInterfaceHotel servicosHotel;
                servicosHotel.exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_QUARTOS) {
                ControladorInterfaceQuarto servicosQuarto;
                servicosQuarto.exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_RESERVAS) {
                ControladorInterfaceReserva servicosReserva;
                servicosReserva.exibirMenuCRUD();
            } else if (opcao == OPCAO_AVALIAR_SOLICITACOES) {
                ControladorInterfaceHospede servicosHospede;
                servicosHospede.avaliarSolicitacoes();
            } else {
                IO::Println("Opcao Invalida!");
            }
        }
    }
};
