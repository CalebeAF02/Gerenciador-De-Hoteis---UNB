//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP

#include "InterfaceApresentacaoHospede.hpp"
#include "IO.hpp"
#include <iostream>

#include "InterfaceServicoHotel.hpp"
using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoHospede : public InterfaceApresentacaoHospede {
    private:
        InterfaceServicoHospede *controladora_servico_hospede;

    public:
        bool valor() override;

        void setControladoraServicoHospede(InterfaceServicoHospede *) override;
    };
}

#endif //Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP