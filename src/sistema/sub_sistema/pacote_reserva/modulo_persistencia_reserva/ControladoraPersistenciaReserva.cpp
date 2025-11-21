//
// Created by caleb on 19/11/2025.
//

#include "ControladoraPersistenciaReserva.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaReserva::inserir(const Reserva &reserva) {
        // Ainda não Implementado
        return true;
    }

    bool ControladoraPersistenciaReserva::autenticar(const string &email, const string &senha) {
        // Ainda não Implementado
        return true;
    }

    vector<ReservaDTO> ControladoraPersistenciaReserva::listar() {
        vector<ReservaDTO> lista;
        return lista;
    }

    optional<ReservaDTO> ControladoraPersistenciaReserva::pesquisar(const int &id) {
        return nullopt;
    }

    bool ControladoraPersistenciaReserva::atualizar(const int &id, const Reserva &reserva) {
        return true;
    }

    bool ControladoraPersistenciaReserva::excluir(const int &id) {
        // Ainda não Implementado
        return true;
    }
}