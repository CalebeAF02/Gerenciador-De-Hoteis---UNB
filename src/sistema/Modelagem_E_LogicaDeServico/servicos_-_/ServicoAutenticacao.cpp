//
// Created by caleb on 26/10/2025.
//

#include "../../../../include/sistema/Modelagem_E_LogicaDeServico/servicos_-_/ServicoAutenticacao.h"

#include "ServicoAutenticacao.h"

ServicoAutenticacao::ServicoAutenticacao() {
    credenciais["gerente@hotel.com"] = "admin123";
    credenciais["calebe@hotel.com"] = "senhaSegura";
}

bool ServicoAutenticacao::autenticar(const std::string& email, const std::string& senha) {
    auto it = credenciais.find(email);
    return it != credenciais.end() && it->second == senha;
}