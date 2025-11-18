//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP

#include "Quarto.hpp"
#include "BancoDeDados.hpp"
#include "QuartoDTO.hpp"
#include <optional>

#include "iostream"
#include "sqlite3.h"

using namespace std;
namespace Hotelaria {
    class ControladoraPersistenciaQuarto {
    public:
        bool inserir(Quarto *hotel);

        vector<QuartoDTO *> listar();

        //optional<QuartoDTO> buscaHotelPorID(int id);

        bool atualizar(int id, const Quarto &quarto);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP