//
// Created by caleb on 15/11/2025.
//

#ifndef HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP
#define HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP
#include "InterfaceServicoAcesso.hpp"

namespace Hotelaria {
    class InterfaceApresentacaoAcesso {
    public:
        virtual void exibirMenu() = 0;

        virtual void setControladoraServicoAcesso(InterfaceServicoAcesso *) = 0;
    };
}
#endif //HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP