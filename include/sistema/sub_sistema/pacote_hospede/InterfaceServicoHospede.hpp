//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP

#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceServicoHospede {
    public:
        virtual bool valor() = 0;
    };
}

#endif //Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP