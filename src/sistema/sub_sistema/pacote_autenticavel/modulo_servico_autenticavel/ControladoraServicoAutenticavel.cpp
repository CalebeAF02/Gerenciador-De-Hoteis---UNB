//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoAutenticavel.hpp"

#include "../../../../../include/sistema/sub_sistema/pacote_gerente/modulo_persistencia_gerente/ControladoraPersistenciaGerente.hpp"
namespace Hotelaria {
    bool ControladoraServicoAutenticavel::autenticar(const Email email, const Senha senha) {
        ControladoraPersistenciaGerente pg;
        return pg.autenticarGerente(email.getValor(), senha.getValor());
    }
}