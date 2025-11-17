//
// Created by caleb on 02/11/2025.
//

#ifndef Hotelaria_UnB_TP1_TESTANDOSMOKE_HPP
#define Hotelaria_UnB_TP1_TESTANDOSMOKE_HPP

#include "Gerente.hpp"
#include "Hospede.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"

#include "../libs/io/IO.hpp"
#include "../libs/formato/Formato.hpp"

#include "../libs/teste/SmokeTeste.hpp"
#include "../libs/teste/InterfaceDeTestes.hpp"

#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace Hotelaria;

class TestandoSmoke {
public:
    void executarSmokeTest();
};


#endif //Hotelaria_UnB_TP1_TESTANDOSMOKE_HPP