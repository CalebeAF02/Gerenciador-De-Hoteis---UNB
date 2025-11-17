//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSA_HPP
#define Hotelaria_UnB_TP1_CSA_HPP

#include "../InterfaceServicoAutenticavel.hpp"
#include "../../../../../libs/io/IO.hpp"
#include <iostream>

#include "Email.hpp"
#include "../InterfaceApresentacaoAutenticavel.hpp"
#include "Senha.hpp"
using namespace std;
namespace Hotelaria {
    class ControladoraServicoAutenticavel : public InterfaceServicoAutenticavel {
    public:
        bool autenticar(const Email, const Senha) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSA_HPP