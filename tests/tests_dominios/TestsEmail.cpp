//
// Created by caleb on 25/10/2025.
//

#include "TestsEmail.h"

void TestsEmail::executar()
{
    testarEmailsValidos();
    testarEmailsInvalidosFormato();
    testarEmailsComCaracteresInvalidos();
    testarEmailsComParteLocalInvalida();
    testarEmailsComDominioInvalido();
    testarEmailsMuitoLongos();
}

void TestsEmail::testarEmailsValidos()
{
    std::vector<std::string> emails = {
        "joao.silva@empresa.com",
        "maria-clara@ufc.br",
        "user123@dominio.net",
        "a.b-c@sub.dominio.org",
        "nome@site.com.br"
    };

    for (const auto& email : emails)
    {
        try
        {
            Email e(email);
            checar(true, "Email valido aceito: " + email);
        }
        catch (...)
        {
            checar(false, "Email valido rejeitado: " + email);
        }
    }
}

void TestsEmail::testarEmailsInvalidosFormato()
{
    std::vector<std::string> emails = {
        "joao.silvaempresa.com", // falta @
        "joao@.com", // dominio invalido
        "@empresa.com", // parte local vazia
        "joao@", // dominio vazio
        "joao@empresa" // sem TLD
    };

    for (const auto& email : emails)
    {
        try
        {
            Email e(email);
            checar(false, "Email com formato invalido aceito: " + email);
        }
        catch (...)
        {
            checar(true, "Email com formato invalido rejeitado: " + email);
        }
    }
}

void TestsEmail::testarEmailsComCaracteresInvalidos()
{
    std::vector<std::string> emails = {
        "joao!@empresa.com",
        "maria#clara@ufc.br",
        "user$123@dominio.net",
        "a%bc@sub.dominio.org"
    };

    for (const auto& email : emails)
    {
        try
        {
            Email e(email);
            checar(false, "Email com caractere invalido aceito: " + email);
        }
        catch (...)
        {
            checar(true, "Email com caractere invalido rejeitado: " + email);
        }
    }
}

void TestsEmail::testarEmailsComParteLocalInvalida()
{
    std::vector<std::string> emails = {
        ".joao@empresa.com", // comeca com ponto
        "joao.@empresa.com", // termina com ponto
        "-maria@ufc.br", // comeca com hifen
        "maria-@ufc.br", // termina com hifen
        "joao..silva@empresa.com" // dois pontos seguidos
    };

    for (const auto& email : emails)
    {
        try
        {
            Email e(email);
            checar(false, "Email com parte local invalida aceito: " + email);
        }
        catch (...)
        {
            checar(true, "Email com parte local invalida rejeitado: " + email);
        }
    }
}

void TestsEmail::testarEmailsComDominioInvalido()
{
    std::vector<std::string> emails = {
        "joao@-empresa.com", // dominio comeca com hifen
        "joao@empresa-.com", // dominio termina com hifen
        "joao@empresa..com", // dois pontos seguidos
        "joao@empresa@com", // dois @
        "joao@.com.br" // dominio comeca com ponto
    };

    for (const auto& email : emails)
    {
        try
        {
            Email e(email);
            checar(false, "Email com dominio invalido aceito: " + email);
        }
        catch (...)
        {
            checar(true, "Email com dominio invalido rejeitado: " + email);
        }
    }
}

void TestsEmail::testarEmailsMuitoLongos()
{
    std::string parteLocal = std::string(65, 'a'); // 65 > 64
    std::string dominio = std::string(256, 'b'); // 256 > 255

    std::vector<std::string> emails = {
        parteLocal + "@empresa.com",
        "joao@" + dominio + ".com"
    };

    for (const auto& email : emails)
    {
        try
        {
            Email e(email);
            checar(false, "Email muito longo aceito: " + email);
        }
        catch (...)
        {
            checar(true, "Email muito longo rejeitado: " + email);
        }
    }
}