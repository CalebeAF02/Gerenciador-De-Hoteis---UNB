//
// Created by caleb on 14/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAHOSPEDE_H

#include "InterfaceFabricaGerenciavel.h"
#include "HospedeGerenciavel.h"

class FabricaHospedeGerenciavel : public InterfaceFabricaGerenciavel
{
public:
    std::unique_ptr<InterfaceGerenciavel> criar() override
    {
        return std::make_unique<HospedeGerenciavel>();
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAHOSPEDE_H