//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoHospede.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoHospede::setControladoraServicoHospede(
        InterfaceServicoHospede *controladora_servico_hospede) {
        this->controladora_servico_hospede = controladora_servico_hospede;
    }
}