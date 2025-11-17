//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoHotel.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoHotel::setControladoraServicoHotel(InterfaceServicoHotel *controladora_servico_hotel) {
        this->controladora_servico_hotel = controladora_servico_hotel;
    }
}