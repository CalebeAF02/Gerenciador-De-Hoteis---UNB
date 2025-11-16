//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CSA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CSA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "../../../../libs/io/IO.hpp"
#include <iostream>

#include "Email.hpp"
#include "InterfaceApresentacaoAutenticavel.hpp"
#include "Senha.hpp"
using namespace std;
namespace Hotelaria {
    class ControladoraServicoAutenticavel : public InterfaceServicoAutenticavel {
    public:
        bool autenticar(const Email, const Senha) override;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CSA_HPP