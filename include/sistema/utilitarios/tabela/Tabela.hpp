//
// Created by caleb on 09/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_TABELA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_TABELA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Linha.hpp"

using namespace std;

namespace VisualizadorDeTabela{

class Tabela {
private:
    vector <shared_ptr<Linha>> linhas;
public:
    Tabela() = default;

    Linha* criarObj();
    void exibirTabela(string titulo);
};

};

#endif //GERENCIADOR_DE_HOTEIS_UNB_TABELA_HPP