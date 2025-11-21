//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoAutenticavel.hpp"

namespace Hotelaria {
    bool ControladoraServicoAutenticavel::autenticar(const Email &email, const Senha &senha) {
        ControladoraPersistenciaGerente pg;
        return pg.autenticar(email.getValor(), senha.getValor());
    }
}