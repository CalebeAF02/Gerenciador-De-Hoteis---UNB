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
            servicosGerente.exibirMenu();
        } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
            servicosHospede.acessandoHospede();
        }
    }
};