//
// Created by caleb on 14/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENTE_H

#include "Pessoa.h"
#include "Gerente.h"
#include "FabricaPessoa.h"

class FabricaGerente : public FabricaPessoa
{
public:
    Pessoa* criarPessoa() const override
    {
        return new Gerente();
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENTE_H
