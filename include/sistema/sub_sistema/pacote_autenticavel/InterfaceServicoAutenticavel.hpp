//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISA_HPP
#define Hotelaria_UnB_TP1_ISA_HPP

#include "InterfacePersistenciaAutenticavel.hpp"
#include "Email.hpp"
#include "Senha.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceServicoAutenticavel {
    public:
        virtual void setControladoraPersistencia(InterfacePersistenciaAutenticavel *persistencia) = 0;

        virtual bool autenticar(const Email &email, const Senha &senha) = 0;

        virtual ~InterfaceServicoAutenticavel() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISA_HPP