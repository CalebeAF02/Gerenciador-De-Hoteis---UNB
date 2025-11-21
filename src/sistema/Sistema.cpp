//
// Created by caleb on 28/09/2025.
//

#include "Sistema.hpp"

#include "sqlite3.h"
#include "Versao.hpp"

namespace Hotelaria {
    void Sistema::iniciar() {
        IO::Println("Versao " + Versao::getVersaoCompleta() + " Compilado em " + Versao::getData());
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
                this->contoladoraApresentacaoAcessoGerente->exibirMenu();
            } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
                this->contoladoraApresentacaoAcessoHospede->exibirMenu();
            }
        }
    };
}