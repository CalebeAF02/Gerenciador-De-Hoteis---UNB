//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IARESERVA_HPP
#define Hotelaria_UnB_TP1_IARESERVA_HPP
#include "InterfaceServicoReserva.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoReserva {
    public:
        virtual bool valor() = 0;

        virtual void setControladoraServicoReserva(InterfaceServicoReserva *controladora_servico_reserva) = 0;
    };
}

#endif //Hotelaria_UnB_TP1_IARESERVA_HPP