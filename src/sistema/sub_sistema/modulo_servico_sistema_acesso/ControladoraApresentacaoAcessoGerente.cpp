//
// Created by caleb on 15/11/2025.
//
#include "ControladoraApresentacaoAcessoGerente.hpp"

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
                controladorGerente.exibirMenu();
            }
        } else {
            IO::Println("Opcao Invalida!");
        }
    }
};