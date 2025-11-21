//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAAUTENTICAVEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAAUTENTICAVEL_HPP

#include <iostream>

using namespace std;

namespace Hotelaria {
    class InterfacePersistenciaAutenticavel {
    public:
        virtual bool autenticar(const string &email, const string &senha) = 0;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAAUTENTICAVEL_HPP