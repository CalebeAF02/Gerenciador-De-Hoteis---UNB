//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACESERVICOAUTENTICACAO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACESERVICOAUTENTICACAO_H

#include <string>

class InterfaceServicoAutenticacao {
public:
    virtual bool autenticar(const std::string& email, const std::string& senha) = 0;
    virtual ~InterfaceServicoAutenticacao() = default;
};
#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACESERVICOAUTENTICACAO_H
