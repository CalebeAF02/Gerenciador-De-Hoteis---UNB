//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CARESERVA_HPP
#define Hotelaria_UnB_TP1_CARESERVA_HPP

#include "../../../../../libs/formato/Formato.hpp"
#include "../../../../../libs/menu/ExibirMenu.hpp"
#include "../InterfaceApresentacaoReserva.hpp"
#include "../../../../../libs/io/IO.hpp"
#include <iostream>

#include "InterfaceServicoReserva.hpp"

using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoReserva : public InterfaceApresentacaoReserva {
    private:
        InterfaceServicoReserva *controladora_servico_reserva;

    public:
        bool valor() override;

        void setControladoraServicoReserva(InterfaceServicoReserva *) override;

        void exibirMenu();

        void exibirMenuCRUD();
    };
}

#endif //Hotelaria_UnB_TP1_CARESERVA_HPP