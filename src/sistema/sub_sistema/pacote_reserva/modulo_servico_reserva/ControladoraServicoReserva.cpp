//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoReserva.hpp"


namespace Hotelaria {
    void ControladoraServicoReserva::setControladoraPersistencia(InterfacePersistenciaReserva *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoReserva::exibirMenu() {
        return true;
    };

    bool ControladoraServicoReserva::exibirMenuCRUD() {
        return true;
    };

    bool ControladoraServicoReserva::criar(const Reserva &reserva) {
        return true;
    };

    bool ControladoraServicoReserva::editar(const int &id, const Reserva &reserva) {
        return true;
    };

    bool ControladoraServicoReserva::remover(const int &id) {
        return true;
    };

    optional<ReservaDTO> ControladoraServicoReserva::pesquisar(const int &id) {
        return nullopt;
    };

    vector<ReservaDTO> ControladoraServicoReserva::listarTodos() {
        vector<ReservaDTO> lista;
        return lista;
    }
}