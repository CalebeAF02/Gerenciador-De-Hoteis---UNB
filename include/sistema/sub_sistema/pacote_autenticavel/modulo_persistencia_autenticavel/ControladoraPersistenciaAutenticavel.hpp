//
// Created by caleb on 21/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAAUTENTICAVEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAAUTENTICAVEL_HPP

#include "InterfacePersistenciaAutenticavel.hpp"

namespace Hotelaria {
    class ControladoraPersistenciaAutenticavel : public InterfacePersistenciaAutenticavel {
    public:
        bool autenticar(const string &email, const string &senha) override;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAAUTENTICAVEL_HPP
