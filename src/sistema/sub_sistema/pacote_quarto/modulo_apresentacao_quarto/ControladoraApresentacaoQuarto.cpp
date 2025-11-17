//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoQuarto.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoQuarto::setControladoraServicoQuarto(
        InterfaceServicoQuarto *controladora_servico_quarto) {
        this->controladora_servico_quarto = controladora_servico_quarto;
    }
}