//
// Created by caleb on 25/10/2025.
//

#include "TestsSenha.h"

void TestsSenha::executar()
{
    testarSenhasValidas();
    testarSenhasMuitoCurtas();
    testarSenhasSemMaiuscula();
    testarSenhasSemMinuscula();
    testarSenhasSemDigito();
    testarSenhasSemEspecial();
    testarSenhasComInicioInvalido();
}

void TestsSenha::testarSenhasValidas()
{
    std::vector<std::string> senhas = {
        "Abcdef1@", "Senha123!", "Teste@2023", "Valid@Senha1", "Xyz#7890"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(true, "Senha valida aceita: " + senha);
        }
        catch (...)
        {
            checar(false, "Senha valida rejeitada: " + senha);
        }
    }
}

void TestsSenha::testarSenhasMuitoCurtas()
{
    std::vector<std::string> senhas = {
        "Ab1@", "S1!", "aB3#", "Xy9*"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(false, "Senha curta aceita: " + senha);
        }
        catch (...)
        {
            checar(true, "Senha curta rejeitada: " + senha);
        }
    }
}

void TestsSenha::testarSenhasSemMaiuscula()
{
    std::vector<std::string> senhas = {
        "senha123@", "teste@2023", "abcde1#", "valid@senha1"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(false, "Senha sem maiuscula aceita: " + senha);
        }
        catch (...)
        {
            checar(true, "Senha sem maiuscula rejeitada: " + senha);
        }
    }
}

void TestsSenha::testarSenhasSemMinuscula()
{
    std::vector<std::string> senhas = {
        "SENHA123@", "TESTE@2023", "ABCDE1#", "VALID@SENHA1"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(false, "Senha sem minuscula aceita: " + senha);
        }
        catch (...)
        {
            checar(true, "Senha sem minuscula rejeitada: " + senha);
        }
    }
}

void TestsSenha::testarSenhasSemDigito()
{
    std::vector<std::string> senhas = {
        "Senha@", "Teste@!", "Valid@Senha", "Abcdef@"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(false, "Senha sem digito aceita: " + senha);
        }
        catch (...)
        {
            checar(true, "Senha sem digito rejeitada: " + senha);
        }
    }
}

void TestsSenha::testarSenhasSemEspecial()
{
    std::vector<std::string> senhas = {
        "Senha123", "Teste2023", "ValidSenha1", "Xyz7890"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(false, "Senha sem caractere especial aceita: " + senha);
        }
        catch (...)
        {
            checar(true, "Senha sem caractere especial rejeitada: " + senha);
        }
    }
}

void TestsSenha::testarSenhasComInicioInvalido()
{
    std::vector<std::string> senhas = {
        "@Senha123", "#Teste2023", "!ValidSenha1", "*Xyz7890"
    };

    for (const auto& senha : senhas)
    {
        try
        {
            Senha s(senha);
            checar(false, "Senha iniciando com caractere especial aceita: " + senha);
        }
        catch (...)
        {
            checar(true, "Senha iniciando com caractere especial rejeitada: " + senha);
        }
    }
}