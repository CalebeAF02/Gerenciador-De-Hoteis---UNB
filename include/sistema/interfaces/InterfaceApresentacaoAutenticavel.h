//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H

#include <string>

class InterfaceApresentacaoAutenticavel
{
public:
    virtual void autenticar() = 0;
    virtual void exibirMenu(const std::string& email) = 0;
    virtual ~InterfaceApresentacaoAutenticavel() = default;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEAPRESENTACAOAUTENTICAVEL_H