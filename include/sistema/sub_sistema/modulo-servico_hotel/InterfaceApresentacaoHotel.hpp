//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_IAHOTEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_IAHOTEL_HPP

#include "../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;
namespace Hotelaria {
    class InterfaceApresentacaoHotel {
    public:
        virtual bool valor() = 0;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_IAHOTEL_HPP