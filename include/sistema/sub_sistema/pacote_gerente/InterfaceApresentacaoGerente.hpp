//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAP_HPP
#define Hotelaria_UnB_TP1_IAP_HPP

#include "Email.hpp"
#include "InterfaceServicoGerente.hpp"

#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoGerente {
        virtual void executar(const Email email) = 0; //  por meio do qual é solicitado o serviço.
        virtual void setControladoraServicoPessoal(InterfaceServicoGerente *) = 0;

        //  para estabelecer ligação (link) com a controladora de serviço.
        //virtual ~InterfaceApresentacaoPessoal();
    };
}

#endif //Hotelaria_UnB_TP1_IAP_HPP