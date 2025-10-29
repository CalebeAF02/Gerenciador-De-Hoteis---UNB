//
// Created by caleb on 26/10/2025.
//

#include "ApresentacaoAutenticavel.h"
#include <iostream>

ApresentacaoAutenticavel::ApresentacaoAutenticavel(InterfaceServicoAutenticacao* servico)
    : servicoAutenticacao(servico)
{
}

void ApresentacaoAutenticavel::autenticar()
{
    std::string email, senha;
    std::cout << "Email do gerente: ";
    std::getline(std::cin, email);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    if (servicoAutenticacao->autenticar(email, senha))
    {
        std::cout << "Autenticacao bem-sucedida!\n";
        exibirMenu(email);
    }
    else
    {
        std::cout << "Credenciais invalidas.\n";
    }
}

void ApresentacaoAutenticavel::exibirMenu(const std::string& email)
{
    std::cout << "Bem-vindo, gerente " << email << "!\n";
    // ... opções específicas para o gerente
}