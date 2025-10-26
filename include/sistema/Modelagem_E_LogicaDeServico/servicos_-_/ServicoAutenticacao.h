//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOAUTENTICACAO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOAUTENTICACAO_H

#include "InterfaceServicoAutenticacao.h"
#include <map>

class ServicoAutenticacao : public InterfaceServicoAutenticacao {
private:
    std::map<std::string, std::string> credenciais;

public:
    ServicoAutenticacao();

    bool autenticar(const std::string& email, const std::string& senha) override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOAUTENTICACAO_H
