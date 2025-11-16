//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoAutenticavel.hpp"

#include "PersistenciaGerente.hpp"
namespace Hotelaria {
    bool ControladoraServicoAutenticavel::autenticar(const Email email, const Senha senha) {
        PersistenciaGerente pg;
        return pg.autenticarGerente(email.getValor(), senha.getValor());
    }
}