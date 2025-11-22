//
// Created by caleb on 15/11/2025.
//

#ifndef HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP
#define HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP

#include "InterfaceApresentacaoAutenticavel.hpp"
#include "InterfaceApresentacaoHospede.hpp"
#include "InterfaceApresentacaoGerente.hpp"
#include "InterfaceApresentacaoHotel.hpp"
#include "InterfaceApresentacaoQuarto.hpp"
#include "InterfaceApresentacaoReserva.hpp"

namespace Hotelaria {
    class InterfaceApresentacaoAcesso {
    public:

        virtual void exibirMenu() = 0;

        virtual ~InterfaceApresentacaoAcesso() = default;
    };
}
#endif //HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP