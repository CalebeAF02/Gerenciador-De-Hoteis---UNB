//
// Created by caleb on 28/09/2025.
//

#include "Sistema.hpp"

#include "sqlite3.h"
#include "Versao.hpp"

void Sistema::iniciar() {
    IO::Println("Versao " + Versao::getVersaoCompleta());
    while (getExecutandoSistema()) {
        exibirMenu();
    }
}

void Sistema::exibirMenu() {
    bool executando = true;
    Menu menu;

    int OPCAO_SAIR_DO_SISTEMA = menu.adcionarItens("Sair");
    int OPCAO_ENTRAR_COMO_GERENTE = menu.adcionarItens("Entrar como Gerente");
    int OPCAO_ENTRAR_COMO_HOSPEDE = menu.adcionarItens("Entrar como Hospede");

    while (executando) {
        int opcao = menu.executa("Seja bem vindo ao Gerenciador de Hoteis");

        if (opcao == OPCAO_SAIR_DO_SISTEMA) {
            executando = false;
            IO::Println("Encerrando o sistema...");
        } else if (opcao == OPCAO_ENTRAR_COMO_GERENTE) {
            Email emailAcessar;
            exibirMenuDoGerente();
        } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
            controladorHospede.exibirMenu();
        }
    }
};


void Sistema::exibirMenuDoGerente() {
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
            FabricaGerenciavel<ControladorInterfaceGerente> fabrica;
            fabrica.criar(); // apenas cria o gerente, sem abrir o menu
        } else if (opcao == OPCAO_FAZER_LOGIN) {
            controladorGerente.fazerLogin();
            if (controladorGerente.getEstaLogado()) {
                IO::Println("Agora Voce Possui Super-Poderes");
                controladorGerente.exibirMenu();
            }
        } else {
            IO::Println("Opcao Invalida!");
        }
    }
};