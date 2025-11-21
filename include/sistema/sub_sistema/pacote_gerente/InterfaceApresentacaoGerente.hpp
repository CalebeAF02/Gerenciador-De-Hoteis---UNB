//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAP_HPP
#define Hotelaria_UnB_TP1_IAP_HPP

#include "InterfaceServicoGerente.hpp"

namespace Hotelaria {
    class InterfaceApresentacaoGerente {
    public:
        virtual void setControladoraServicoPessoal(InterfaceServicoGerente *) = 0;

        virtual void exibirMenuCRUD() = 0;

        virtual ~InterfaceApresentacaoGerente() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAP_HPP