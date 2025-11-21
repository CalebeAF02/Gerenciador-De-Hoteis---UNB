//
// Created by caleb on 18/11/2025.
//

#include "ControladoraPersistenciaQuarto.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaQuarto::inserir(const Quarto &quarto) {
        // Ainda não Implementado
        return true;
    }

    bool ControladoraPersistenciaQuarto::autenticar(const string &email, const string &senha) {
        // Ainda não Implementado
        return true;
    }

    bool ControladoraPersistenciaQuarto::atualizar(const int &id, const Quarto &quarto) {
        // Ainda não Implementado
        return true;
    }

    bool ControladoraPersistenciaQuarto::excluir(const int &id) {
        // Ainda não Implementado
        return true;
    }

    vector<QuartoDTO> ControladoraPersistenciaQuarto::listar() {
        vector<QuartoDTO> lista;
        return lista;
    }

    optional<QuartoDTO> ControladoraPersistenciaQuarto::pesquisar(const int &id) {
        return nullopt;
    }
}