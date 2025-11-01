//
// Created by caleb on 28/09/2025.
//

#include "Sistema.h"

#include "sqlite3.h"

void Sistema::rodandoSistema() {
    Menu menu;

    int OPCAO_SAIR_DO_SISTEMA = menu.adcionarItens("Sair");
    int OPCAO_ENTRAR_COMO_GERENTE = menu.adcionarItens("Entrar como Gerente");
    int OPCAO_ENTRAR_COMO_HOSPEDE = menu.adcionarItens("Entrar como Hospede");

    while (executando == true) {
        int opcao = menu.executa("Seja bem vindo ao gerenciador de hoteis");

        if (opcao == OPCAO_SAIR_DO_SISTEMA) {
            executando = false;
            cout << "Encerrando o sistema..." << endl;
        } else if (opcao == OPCAO_ENTRAR_COMO_GERENTE) {
            Email emailAcessar;
            exibirMenu();
        } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
            servicosHospede.acessandoHospede();
        }
    }
};


void Sistema::exibirMenu() {
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_CRIAR_UM_GERENTE = menu.adcionarItens("Criar Gerente");
    const int OPCAO_FAZER_LOGIN = menu.adcionarItens("Fazer Login");

    while (executando == true) {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        } else if (opcao == OPCAO_CRIAR_UM_GERENTE) {
            FabricaGerenciavel<GerenteGerenciavel> fabrica;
            fabrica.criar(); // apenas cria o gerente, sem abrir o menu
        } else if (opcao == OPCAO_FAZER_LOGIN) {
            servicosGerente.fazerLogin();
            if (servicosGerente.getEstaLogado()) {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                exibirCentralDeServicos();
            }
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

void Sistema::exibirCentralDeServicos() {
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
    const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
    const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
    const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
    const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
    const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

    while (this->servicosGerente.getEstaLogado()) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            this->servicosGerente.sair();
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        } else if (opcao == OPCAO_GERENCIE_GERENTES) {
            servicosGerente.exibirCentralDeServicosGerentes();
        } else if (opcao == OPCAO_GERENCIE_HOSPEDES) {
            ServicosHospede servicosHospede;
            servicosHospede.exibirCentralDeServicosHospedes();
        } else if (opcao == OPCAO_GERENCIE_HOTEIS) {
            ServicosHotel servicosHotel;
            servicosHotel.exibirCentralDeServicosHotel();
        } else if (opcao == OPCAO_GERENCIE_QUARTOS) {
            ServicosQuarto servicosQuarto;
            servicosQuarto.exibirCentralDeServicosQuartos();
        } else if (opcao == OPCAO_GERENCIE_RESERVAS) {
            ServicosReserva servicosReserva;
            servicosReserva.exibirCentralDeServicosReservas();
        } else if (opcao == OPCAO_AVALIAR_SOLICITACOES) {
            ServicosHospede servicosHospede;
            servicosHospede.avaliarSolicitacoes();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    };
}