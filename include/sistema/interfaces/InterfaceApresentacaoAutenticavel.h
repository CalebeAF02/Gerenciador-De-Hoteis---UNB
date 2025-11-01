//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H

#include <string>
#include "Email.h"
#include "Senha.h"

// InterfaceApresentacaoAutenticavel == IAA

class InterfaceApresentacaoAutenticavel {
public:
    virtual ~InterfaceApresentacaoAutenticavel() = default;

    virtual bool autenticar(Email &, Senha &) = 0;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H