//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAA_HPP
#define Hotelaria_UnB_TP1_CAA_HPP

#include "../InterfaceServicoAutenticavel.hpp"
#include "../InterfaceApresentacaoAutenticavel.hpp"

#include "Email.hpp"
#include "Senha.hpp"
#include "../../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoAutenticavel : public InterfaceApresentacaoAutenticavel {
    private:
        InterfaceServicoAutenticavel *controladora_servico_autenticavel;

        bool estaAutenticado = false;

    public:
        void sair() override;

        bool autenticar(Email *) override;

        void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *) override;

        void setEstaAutenticado(bool estaAutenticado) override;

        bool getEstaAutenticado() override;

        InterfaceServicoAutenticavel *getHacke();
    };
}

#endif //Hotelaria_UnB_TP1_CAA_HPP