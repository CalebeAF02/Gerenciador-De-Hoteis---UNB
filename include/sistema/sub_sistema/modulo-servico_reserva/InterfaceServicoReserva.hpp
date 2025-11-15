//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ISRESERVA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_ISRESERVA_HPP

#include "../../../../libs/IO/IO.hpp"
#include <iostream>
using namespace std;

class InterfaceServicoReserva {
public:
    virtual bool valor() = 0;
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_ISRESERVA_HPP