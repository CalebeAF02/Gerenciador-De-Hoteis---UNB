//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoReserva.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoReserva::setControladoraServicoReserva(
        InterfaceServicoReserva *controladora_servico_reserva) {
        this->controladora_servico_reserva = controladora_servico_reserva;
    }
}
