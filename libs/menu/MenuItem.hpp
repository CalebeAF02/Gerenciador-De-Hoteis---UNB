//
// Created by caleb on 19/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_MENUITEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_MENUITEM_H

#include <iostream>
#include <string>

using namespace std;

namespace VisualizadorDeMenu {
    class MenuItem {
    private:
        string nome;
        string valor;
        int valorConstante;

    public:
        MenuItem(string nomeStr, string valorStr, int valorConstanteInt) : nome(nomeStr), valor(valorStr),
                                                                           valorConstante(valorConstanteInt) {
        };

        string getNome();

        string getValor();

        int getValorConstante();
    };

    inline string MenuItem::getNome() {
        return nome;
    }

    inline string MenuItem::getValor() {
        return valor;
    }

    inline int MenuItem::getValorConstante() {
        return valorConstante;
    }
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_MENUITEM_H