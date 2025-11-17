//
// Created by caleb on 19/10/2025.
//
#include "MenuItem.hpp"

namespace VisualizadorDeMenu {
    string MenuItem::getNome() {
        return nome;
    }

    string MenuItem::getValor() {
        return valor;
    }

    int MenuItem::getValorConstante() {
        return valorConstante;
    }
}