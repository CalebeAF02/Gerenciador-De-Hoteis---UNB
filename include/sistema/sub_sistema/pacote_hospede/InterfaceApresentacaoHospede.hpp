//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP
#include "InterfaceServicoHospede.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoHospede {
    public:
        virtual bool valor() = 0;

        virtual void setControladoraServicoHospede(InterfaceServicoHospede *) = 0;
    };
}

#endif //Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP