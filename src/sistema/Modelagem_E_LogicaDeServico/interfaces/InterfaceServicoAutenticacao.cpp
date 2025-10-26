//
// Created by caleb on 26/10/2025.
//

#ifndef SERVICO_AUTENTICACAO_GERENTE_H
#define SERVICO_AUTENTICACAO_GERENTE_H

#include "../../../../include/sistema/Modelagem_E_LogicaDeServico/interfaces/InterfaceServicoAutenticacao.h"
#include <map>

class ServicoAutenticacao : public InterfaceServicoAutenticacao {
private:
    std::map<std::string, std::string> credenciaisGerente;

public:
    ServicoAutenticacao();

    bool autenticar(const std::string& email, const std::string& senha) override;
};

#endif