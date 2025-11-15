//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ISA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_ISA_HPP

#include "Email.hpp"
#include "Senha.hpp"
#include "../../../../libs/IO/IO.hpp"
#include <iostream>
using namespace std;

class InterfaceServicoAutenticavel {
public:
    virtual bool autenticar(const Email, const Senha) = 0; //  por meio do qual é solicitado o serviço.
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_ISA_HPP