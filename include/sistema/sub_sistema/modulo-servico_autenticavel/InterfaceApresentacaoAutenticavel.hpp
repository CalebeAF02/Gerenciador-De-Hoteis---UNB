//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_IAA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_IAA_HPP

#include "IO.hpp"
#include <iostream>
using namespace std;

class InterfaceApresentacaoAutenticavel {
public:
    virtual bool autenticar(Email *) = 0; //  solicitado o serviço.
    virtual void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *) = 0;

    // estabelecer ligação (link) com a controladora na camada de serviço.
    virtual ~InterfaceApresentacaoAutenticavel() {
    } // destrutor virtual.
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_IAA_HPP