//
// Created by caleb on 19/10/2025.
//

#include "Menu.hpp"

//-----------------------------------------------------------------------------------------------------------
int Menu::adcionarItens(string nome) {
    contador++;
    // emplace_back adiciona ao vinal do vetor.
    this->menuItens.emplace_back(nome, to_string(contador), contador);

    return contador;
};
//-----------------------------------------------------------------------------------------------------------
vector<MenuItem> Menu::listar() {
    return menuItens;
}

//-----------------------------------------------------------------------------------------------------------
int Menu::executa(string tituloStr) {
    ConsoleFormatter::MostrarTituloEmCaixa(tituloStr);
    ConsoleIO::PrintMensagem("Selecione a opcao:");

    for (int i = 0; i < menuItens.size(); i++) {
        ConsoleFormatter::MostrarOpcaoEmCaixa(menuItens[i].getNome(), menuItens[i].getValor());
    }

    string opcao = ConsoleIO::ReceberOpcao();
    int opcaoInt = -1;
    for (int i = 0; i < menuItens.size(); i++) {
        if (opcao == menuItens[i].getValor()) {
            opcaoInt = menuItens[i].getValorConstante();
            break;
        }
    }
    return opcaoInt;
}

//-----------------------------------------------------------------------------------------------------------