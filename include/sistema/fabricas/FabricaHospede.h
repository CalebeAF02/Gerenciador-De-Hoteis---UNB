//
// Created by caleb on 14/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAHOSPEDE_H

#include "Pessoa.h"
#include "Hospede.h"
#include "FabricaPessoa.h"

class FabricaHospede : public FabricaPessoa
{
public:
    Pessoa* criarPessoa() const override
    {
        return new Hospede();
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAHOSPEDE_H