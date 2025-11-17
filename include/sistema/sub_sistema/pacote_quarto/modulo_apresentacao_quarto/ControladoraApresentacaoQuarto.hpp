//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAQUARTO_HPP
#define Hotelaria_UnB_TP1_CAQUARTO_HPP

#include "InterfaceApresentacaoQuarto.hpp"
#include "InterfaceServicoQuarto.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoQuarto : public InterfaceApresentacaoQuarto {
    private:
        InterfaceServicoQuarto *controladora_servico_quarto;

    public:
        bool valor() override;

        void setControladoraServicoQuarto(InterfaceServicoQuarto *) override;
    };
}

#endif //Hotelaria_UnB_TP1_CAQUARTO_HPP