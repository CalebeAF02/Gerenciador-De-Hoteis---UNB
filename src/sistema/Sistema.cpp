//
// Created by caleb on 28/09/2025.
//

#include "Sistema.hpp"

#include "sqlite3.h"
#include "Versao.hpp"

namespace Hotelaria {
    bool Sistema::getExecutandoSistema() {
        return executando;
    };

    void Sistema::sair() {
        this->executando = false;
    }

    void Sistema::iniciar() {
        IO::Println("Versao " + Versao::getVersaoCompleta() + " Compilado em " + Versao::getData());
        while (getExecutandoSistema()) {
            exibirMenu();
        }
    }

    void Sistema::exibirMenu() {
        Menu menu;

        int OPCAO_SAIR_DO_SISTEMA = menu.adcionarItens("Sair");
        int OPCAO_ENTRAR_COMO_GERENTE = menu.adcionarItens("Entrar como Gerente");
        int OPCAO_ENTRAR_COMO_HOSPEDE = menu.adcionarItens("Entrar como Hospede");

        while (getExecutandoSistema()) {
            int opcao = menu.executa("Seja bem vindo ao Gerenciador de Hoteis");

            if (opcao == OPCAO_SAIR_DO_SISTEMA) {
                sair();
                IO::Println("Encerrando o sistema...");
            } else if (opcao == OPCAO_ENTRAR_COMO_GERENTE) {
                contoladoraApresentacaoAcessoGerente.exibirMenu();
            } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
                contoladoraApresentacaoAcessoHospede.exibirMenu();
            }
        }
    };
}