//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_IAA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_IAA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;

class InterfaceApresentacaoAutenticavel {
public:
    virtual void sair() = 0;

    virtual bool autenticar(Email*) = 0; //  solicitado o serviço.

    virtual void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel*) = 0;

    virtual void setEstaAutenticado(bool estaAutenticado) = 0;

    virtual bool getEstaAutenticado() = 0;
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_IAA_HPP