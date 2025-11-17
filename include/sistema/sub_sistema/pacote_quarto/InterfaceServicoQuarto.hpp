//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ISQUARTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_ISQUARTO_HPP

#include "../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;
namespace Hotelaria {
    class InterfaceServicoQuarto {
    public:
        virtual bool valor() = 0;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_ISQUARTO_HPP