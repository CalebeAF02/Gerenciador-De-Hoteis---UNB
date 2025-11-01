//
// Created by caleb on 01/11/2025.
//

#include "../../../include/sistema/controladores_entidades/ControladorInterfaceGerente.h"

#include "ControladorInterfaceGerente.h"

void ControladorInterfaceGerente::exibirMenu() {
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
    const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
    const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
    const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
    const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
    const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

    while (this->getEstaLogado()) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            this->sair();
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        } else if (opcao == OPCAO_GERENCIE_GERENTES) {
            exibirMenuCRUDGerentes();
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
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ControladorInterfaceGerente::exibirMenuCRUDGerentes() {
    bool status = true;
    while (this->getEstaLogado()) {
        FabricaGerenciavel<GerenteGerenciavel> fabrica;
        fabrica.executarMenu(status);
        if (status == false) {
            break;
        }
    };
}
