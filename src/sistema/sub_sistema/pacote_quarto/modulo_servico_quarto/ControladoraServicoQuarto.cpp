//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoQuarto.hpp"

namespace Hotelaria {
    void ControladoraServicoQuarto::setControladoraPersistencia(InterfacePersistenciaQuarto *persistencia) {
        this->persistencia = persistencia;
    }

    void ControladoraServicoQuarto::exibirMenu() {
    }

    void ControladoraServicoQuarto::exibirMenuCRUD() {
    }

    bool ControladoraServicoQuarto::criar(const Quarto &quarto) {
        return true;
    }

    bool ControladoraServicoQuarto::editar(const int &id, const Quarto &quarto) {
        return true;
    }

    bool ControladoraServicoQuarto::remover(const int &id) {
        return true;
    }

    vector<QuartoDTO> ControladoraServicoQuarto::listarTodos() {
        vector<QuartoDTO> lista;
        return lista;
    }

    optional<QuartoDTO> ControladoraServicoQuarto::pesquisar(const int &id) {
        return nullopt;
    }
}