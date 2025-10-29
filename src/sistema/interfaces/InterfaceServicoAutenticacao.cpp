//
// Created by caleb on 26/10/2025.
//

#ifndef SERVICO_AUTENTICACAO_GERENTE_H
#define SERVICO_AUTENTICACAO_GERENTE_H

#include "../../../include/sistema/interfaces/InterfaceServicoAutenticacao.h"
#include <map>

class ServicosAutenticacao : public InterfaceServicoAutenticacao
{
private:
    std::map<std::string, std::string> credenciaisGerente;

public:
    ServicosAutenticacao();

    bool autenticar(const std::string& email, const std::string& senha) override;
};

#endif