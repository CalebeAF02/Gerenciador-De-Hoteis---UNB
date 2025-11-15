//
// Created by caleb on 02/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_TESTANDOSMOKE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_TESTANDOSMOKE_HPP

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

class TestandoSmoke {
public:
    void executarSmokeTest();
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_TESTANDOSMOKE_HPP