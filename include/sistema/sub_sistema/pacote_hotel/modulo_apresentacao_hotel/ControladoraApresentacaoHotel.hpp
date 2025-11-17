//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAHOTEL_HPP
#define Hotelaria_UnB_TP1_CAHOTEL_HPP
#include "InterfaceApresentacaoHotel.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoHotel : public InterfaceApresentacaoHotel {
    private:
        InterfaceServicoHotel *controladora_servico_hotel;

    public:
        bool valor() override;

        void setControladoraServicoHotel(InterfaceServicoHotel *) override;
    };
}


#endif //Hotelaria_UnB_TP1_CAHOTEL_HPP