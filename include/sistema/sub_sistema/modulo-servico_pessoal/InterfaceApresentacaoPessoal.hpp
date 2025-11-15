//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_IAP_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_IAP_HPP

#include "Email.hpp"
#include "InterfaceServicoPessoal.hpp"

#include "../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;

class InterfaceApresentacaoPessoal {
    virtual void executar(const Email email) = 0; //  por meio do qual é solicitado o serviço.
    virtual void setControladoraServicoPessoal(InterfaceServicoPessoal *) = 0;

    //  para estabelecer ligação (link) com a controladora de serviço.
    //virtual ~InterfaceApresentacaoPessoal();
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_IAP_HPP
