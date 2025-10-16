//
// Created by caleb on 14/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAPESSOA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAPESSOA_H

#include "Pessoa.h"

class FabricaPessoa
{
public:
    virtual Pessoa* criarPessoa() const = 0;
    virtual ~FabricaPessoa() = default;
};


#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAPESSOA_H
