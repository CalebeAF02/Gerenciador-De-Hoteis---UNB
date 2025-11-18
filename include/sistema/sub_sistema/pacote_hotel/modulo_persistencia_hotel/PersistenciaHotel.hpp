//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_PERSISTENCIAHOTEL_H
#define Hotelaria_UnB_TP1_PERSISTENCIAHOTEL_H

#include "Hotel.hpp"
#include "BancoDeDados.hpp"
#include "HotelDTO.hpp"
#include <optional>

#include "iostream"
#include "sqlite3.h"

using namespace std;
namespace Hotelaria {
    class PersistenciaHotel {
    public:
        bool inserir(Hotel *hotel);

        vector<HotelDTO *> listar();

        optional<HotelDTO> buscaHotelPorID(int id);

        bool atualizar(int id, const Hotel &hotel);
    };
}


#endif //Hotelaria_UnB_TP1_PERSISTENCIAHOTEL_H