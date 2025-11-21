//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSA_HPP
#define Hotelaria_UnB_TP1_CSA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "InterfaceApresentacaoAutenticavel.hpp"
#include "ControladoraPersistenciaGerente.hpp"
#include "Email.hpp"
#include "Senha.hpp"

#include "IO.hpp"
#include <iostream>

using namespace std;

namespace Hotelaria {
    class ControladoraServicoAutenticavel : public InterfaceServicoAutenticavel {
    public:
        bool autenticar(const Email &email, const Senha &senha) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSA_HPP