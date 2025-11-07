//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_PERSISTENCIAHOTEL_H
#define GERENCIADOR_DE_HOTEIS_UNB_PERSISTENCIAHOTEL_H

#include "Hotel.hpp"
#include "BancoDeDados.hpp"

#include "iostream"
#include "sqlite3.h"

using namespace std;

class PersistenciaHotel {
public:
    bool inserirAoBD(Hotel *hotel);
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_PERSISTENCIAHOTEL_H