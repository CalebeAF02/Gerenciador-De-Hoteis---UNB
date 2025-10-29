//
// Created by caleb on 26/10/2025.
//

#include "../../../include/sistema/servicos/ServicosAutenticacao.h"

#include "../../../include/sistema/servicos/ServicosAutenticacao.h"

ServicosAutenticacao::ServicosAutenticacao()
{
    credenciais["gerente@hotel.com"] = "admin123";
    credenciais["calebe@hotel.com"] = "senhaSegura";
}

bool ServicosAutenticacao::autenticar(const std::string& email, const std::string& senha)
{
    auto it = credenciais.find(email);
    return it != credenciais.end() && it->second == senha;
}