//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ISHOTEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_ISHOTEL_HPP

#include "../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;

class InterfaceServicoHotel {
public:
    virtual bool valor() = 0;
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_ISHOTEL_HPP