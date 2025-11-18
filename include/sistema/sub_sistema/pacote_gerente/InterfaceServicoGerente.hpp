//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISP_HPP
#define Hotelaria_UnB_TP1_ISP_HPP

#include "Gerente.hpp"
#include "Email.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceServicoGerente {
    public:
        //  por meio dos quais são solicitados os serviços.
        virtual bool incluir(const Gerente) = 0;

        virtual bool remover(const Email email) = 0;

        virtual bool pesquisar(Gerente) = 0;

        virtual bool editar(const Gerente) = 0;

        virtual ~InterfaceServicoGerente() {
        } //  destrutor virtual.
    };
}


#endif //Hotelaria_UnB_TP1_ISP_HPP