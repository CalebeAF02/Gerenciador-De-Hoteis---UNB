//
// Created by caleb on 28/09/2025.
//

#include "Sistema.hpp"

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
            controladorHospede.exibirMenu();
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
            FabricaGerenciavel<ControladorInterfaceGerente> fabrica;
            fabrica.criar(); // apenas cria o gerente, sem abrir o menu
        } else if (opcao == OPCAO_FAZER_LOGIN) {
            controladorGerente.fazerLogin();
            if (controladorGerente.getEstaLogado()) {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                controladorGerente.exibirMenu();
            }
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    }
};