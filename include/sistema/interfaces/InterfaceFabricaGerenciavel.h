//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEFABRICAGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEFABRICAGERENCIAVEL_H

#include <memory>
#include "InterfaceGerenciavel.h"

class InterfaceFabricaGerenciavel
{
public:
    virtual std::unique_ptr<InterfaceGerenciavel> criar() = 0;
    virtual ~InterfaceFabricaGerenciavel() = default;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEFABRICAGERENCIAVEL_H