//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_PERSISTENCIAHOTEL_H
#define GERENCIADOR_DE_HOTEIS_UNB_PERSISTENCIAHOTEL_H

#include "Hotel.hpp"
#include "BancoDeDados.hpp"
#include "HotelDTO.hpp"
#include <optional>

#include "iostream"
#include "sqlite3.h"

using namespace std;

class PersistenciaHotel {
public:
    bool inserir(Hotel *hotel);

    vector<HotelDTO *> listar();

    optional<HotelDTO> buscaHotelPorID(int id);

    bool atualizar(int id, const Hotel &hotel);
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_PERSISTENCIAHOTEL_H