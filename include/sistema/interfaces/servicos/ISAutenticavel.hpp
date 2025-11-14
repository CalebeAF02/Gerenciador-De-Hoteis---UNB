//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H
#define ISAutenticavelANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H

#include <string>
#include "Email.hpp"
#include "Senha.hpp"

// InterfaceApresentacaoAutenticavel == IAA

class ISAutenticavel {
public:
    virtual bool autenticar(Email &, Senha &) = 0;

    virtual void sair() = 0;

    virtual bool getEstaLogado() = 0;

    virtual ~ISAutenticavel() = default;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H