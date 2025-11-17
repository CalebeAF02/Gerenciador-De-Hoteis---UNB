//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSP_HPP
#define Hotelaria_UnB_TP1_CSP_HPP

#include "../InterfaceServicoPessoal.hpp"
#include "../../../../../libs/io/IO.hpp"
#include <iostream>

using namespace std;
namespace Hotelaria {
    class ControladoraServicoPessoal : public InterfaceServicoPessoal {
    public:
        //  por meio dos quais são solicitados os serviços.
        bool incluir(const Gerente);

        bool remover(const Email email);

        bool pesquisar(Gerente);

        bool editar(const Gerente);
    };
}

#endif //Hotelaria_UnB_TP1_CSP_HPP