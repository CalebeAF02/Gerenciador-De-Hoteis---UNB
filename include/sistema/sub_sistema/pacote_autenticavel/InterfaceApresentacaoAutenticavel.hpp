//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAA_HPP
#define Hotelaria_UnB_TP1_IAA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoAutenticavel {
    public:
        virtual void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *) = 0;

        virtual bool autenticar() = 0; //  solicitado o serviço.

        virtual void setEstaAutenticado(bool estaAutenticado) = 0;

        virtual bool getEstaAutenticado() = 0;

        virtual ~InterfaceApresentacaoAutenticavel() = default;
    };
}


#endif //Hotelaria_UnB_TP1_IAA_HPP