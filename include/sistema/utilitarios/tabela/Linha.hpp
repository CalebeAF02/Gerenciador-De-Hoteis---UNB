//
// Created by caleb on 09/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_LINHA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_LINHA_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Atributo.hpp"

using namespace std;

namespace VisualizadorDeTabela {
    class Linha {
    private:
        vector<shared_ptr<Atributo> > atributos;

    public:
        Linha() = default;

        void atributo(string nome, string valor);

        void atributo(string nome, int valor);

        vector<shared_ptr<Atributo> > getAtributos() {
            return atributos;
        };
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_LINHA_HPP