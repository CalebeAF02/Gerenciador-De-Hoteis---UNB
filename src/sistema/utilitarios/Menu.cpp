//
// Created by caleb on 19/10/2025.
//

#include "Menu.hpp"


int Menu::adcionarItens(string nome) {
    contador++;
    // emplace_back adiciona ao vinal do vetor.
    this->menuItens.emplace_back(nome, to_string(contador), contador);

    return contador;
};

vector<MenuItem> Menu::listar() {
    return menuItens;
}

int Menu::executa(string tituloStr) {
    TextoApresentacao::MostrarTituloEmCaixa(tituloStr);
    TextoApresentacao::MostrarTituloPergunta("Selecione a opcao:");

    for (int i = 0; i < menuItens.size(); i++) {
        TextoApresentacao::MostrarOpcaoEmCaixa(menuItens[i].getNome(), menuItens[i].getValor());
    }

    string opcao = TextoApresentacao::RecebeOpcao();
    int opcaoInt = -1;
    for (int i = 0; i < menuItens.size(); i++) {
        if (opcao == menuItens[i].getValor()) {
            opcaoInt = menuItens[i].getValorConstante();
            break;
        }
    }
    return opcaoInt;
}