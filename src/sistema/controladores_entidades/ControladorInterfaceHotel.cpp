//
// Created by caleb on 10/10/2025.
//

#include "../../../include/sistema/controladores_entidades/ControladorInterfaceHotel.h"

void ControladorInterfaceHotel::exibirMenu() {
    Menu menu;

    const int OPCAO_VOLTAR_ANTERIOR = menu.adcionarItens("Voltar");
    const int OPCAO_CRIAR_HOTEL = menu.adcionarItens("Criar Hotel");

    bool executando = true;
    while (executando) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_ANTERIOR) {
            executando = false;
        } else if (opcao == OPCAO_CRIAR_HOTEL) {
            //criarHotel();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ControladorInterfaceHotel::exibirMenuCRUD() {
    TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo a central de servicos Hotel");
    TextoApresentacao::MostrarTituloPergunta("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
}