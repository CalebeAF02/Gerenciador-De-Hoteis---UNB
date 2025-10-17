//
// Created by caleb on 14/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENTE_H

#include "InterfaceFabricaGerenciavel.h"
#include "GerenteGerenciavel.h"

class FabricaGerenteGerenciavel : public InterfaceFabricaGerenciavel
{
public:
    std::unique_ptr<InterfaceGerenciavel> criar() override
    {
        return std::make_unique<GerenteGerenciavel>();
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENTE_H
