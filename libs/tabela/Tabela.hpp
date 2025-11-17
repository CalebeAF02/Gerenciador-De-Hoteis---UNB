//
// Created by caleb on 09/11/2025.
//

#ifndef Hotelaria_UnB_TP1_TABELA_HPP
#define Hotelaria_UnB_TP1_TABELA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Linha.hpp"

using namespace std;

namespace VisualizadorDeTabela {
    class Tabela {
    private:
        vector<shared_ptr<Linha> > linhas;

    public:
        Tabela() = default;

        Linha *criarObj();

        void exibirTabela(string titulo);
    };
};

#endif //Hotelaria_UnB_TP1_TABELA_HPP