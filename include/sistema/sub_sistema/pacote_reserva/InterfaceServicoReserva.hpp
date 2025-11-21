//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISRESERVA_HPP
#define Hotelaria_UnB_TP1_ISRESERVA_HPP

#include "InterfacePersistenciaReserva.hpp"
#include "ReservaDTO.hpp"
#include "Reserva.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    class InterfaceServicoReserva {
    public:
        virtual void setControladoraPersistencia(InterfacePersistenciaReserva *persistencia) = 0;

        virtual bool criar(const Reserva &reserva) = 0;

        virtual bool editar(const int &id, const Reserva &reserva) = 0;

        virtual bool remover(const int id) = 0;

        virtual vector<ReservaDTO> listarTodos() = 0;

        virtual optional<ReservaDTO> pesquisar(const int id) = 0;

        virtual ~InterfaceServicoReserva() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISRESERVA_HPP