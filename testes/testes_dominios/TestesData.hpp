//
// Created by caleb on 03/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_TESTSDATA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_TESTSDATA_HPP

#include <iostream>
#include "InterfaceDeTestes.hpp"

using namespace std;

class TestesData : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_TESTSDATA_HPP