//
// Created by caleb on 19/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_MENU_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_MENU_H

#include <iostream>
#include <string>
#include <vector>

#include "../formato/Formato.hpp"
#include "../io/IO.hpp"

#include "MenuItem.hpp"

using namespace std;

namespace VisualizadorDeMenu {
    class Menu {
    private:
        vector<MenuItem> menuItens;
        int contador = -1;

    public:
        int adcionarItens(string nome);

        vector<MenuItem> listar();

        int executa(string tituloStr);
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_MENU_H
