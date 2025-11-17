//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISA_HPP
#define Hotelaria_UnB_TP1_ISA_HPP

#include "Email.hpp"
#include "Senha.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceServicoAutenticavel {
    public:
        virtual bool autenticar(const Email, const Senha) = 0; //  por meio do qual é solicitado o serviço.
    };
}

#endif //Hotelaria_UnB_TP1_ISA_HPP