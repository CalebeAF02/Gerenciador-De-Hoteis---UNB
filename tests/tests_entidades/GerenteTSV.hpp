//
// Created by caleb on 03/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_GERENTETSV_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_GERENTETSV_HPP

#include <iostream>
#include "InterfaceDeTeste.hpp"

using namespace std;

class GerenteTSV : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_GERENTETSV_HPP