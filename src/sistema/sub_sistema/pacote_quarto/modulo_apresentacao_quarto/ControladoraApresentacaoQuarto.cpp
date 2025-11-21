//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoQuarto.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoQuarto::setControladoraServicoQuarto(
        InterfaceServicoQuarto *servico) {
        this->servico = servico;
    }

    void ControladoraApresentacaoQuarto::exibirMenuCRUD() {
        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Novo Hospede");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todos os Hospedes");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Hospede (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Hospede (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Hospedes (CRUD)");

            if (opcao == OPCAO_VOLTAR) {
                executando = false;
                IO::Println("Voltando ao menu de acesso.");
            } else if (opcao == OPCAO_CRIAR) {
                criar();
            } else if (opcao == OPCAO_LISTAR) {
                listar();
            } else if (opcao == OPCAO_ATUALIZAR) {
                atualizar();
            } else if (opcao == OPCAO_REMOVER) {
                remover();
            } else {
                IO::Println("Opcao Invalida! Tente novamente.");
            }
        }
    }

    void ControladoraApresentacaoQuarto::criar() {
        IO::Println("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    };

    void ControladoraApresentacaoQuarto::listar() {
        IO::Println("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    };

    void ControladoraApresentacaoQuarto::atualizar() {
        IO::Println("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    };

    void ControladoraApresentacaoQuarto::remover() {
        IO::Println("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    };
}