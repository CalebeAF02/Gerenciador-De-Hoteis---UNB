//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoAutenticavel.hpp"

namespace Hotelaria {
    void ControladoraServicoAutenticavel::setControladoraPersistencia(InterfacePersistenciaAutenticavel *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoAutenticavel::autenticar(const Email &email, const Senha &senha) {
        return persistencia->autenticar(email.getValor(), senha.getValor());
    }
}