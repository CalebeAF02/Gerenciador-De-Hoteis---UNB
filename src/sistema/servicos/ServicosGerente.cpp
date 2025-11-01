//
// Created by caleb on 10/10/2025.
//

#include "ServicosGerente.h"

#include "FabricaGerenciavel.h"
#include "GerenteGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "ServicosHospede.h"
#include "ServicosHotel.h"
#include "ServicosQuarto.h"
#include "ServicosReserva.h"
#include "sqlite3.h"

void ServicosGerente::exibirMenu() {
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
            fazerLogin();
            if (getEstaLogado()) {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                exibirCentralDeServicos();
            }
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

void ServicosGerente::exibirCentralDeServicos() {
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
            exibirCentralDeServicosGerentes();
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
            HospedeGerenciavel crud;
            crud.avaliarSolicitacoes();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ServicosGerente::exibirCentralDeServicosGerentes() {
    bool status = true;
    while (this->getEstaLogado()) {
        FabricaGerenciavel<GerenteGerenciavel> fabrica;
        fabrica.executarMenu(status);
        if (status == false) {
            break;
        }
    };
}

/*
void ServicosGerente::excluirMeuCadastro()
{
    if (!gerenteEstaLogado)
    {
        cout << "Voce precisa estar logado para excluir seu cadastro.\n";
        return;
    }
    PersistenciaGerente persistencia;
    bool sucesso = persistencia.excluirPorEmailDoBD(logGerente);

    if (sucesso)
    {
        gerenteEstaLogado = false;
        logGerente = nullptr;
        executando = false; // ou redireciona para menu principal
    }
    else
    {
        cout << "Nao foi possivel excluir seu cadastro.\n";
    }
}
*/