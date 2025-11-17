//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAQUARTO_HPP
#define Hotelaria_UnB_TP1_IAQUARTO_HPP
#include "InterfaceServicoQuarto.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoQuarto {
    public:
        virtual bool valor() = 0;

        virtual void setControladoraServicoQuarto(InterfaceServicoQuarto *) = 0;
    };
}

#endif //Hotelaria_UnB_TP1_IAQUARTO_HPP