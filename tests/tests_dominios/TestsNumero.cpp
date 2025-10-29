//
// Created by caleb on 25/10/2025.
//

#include "TestsNumero.h"

void TestsNumero::executar()
{
    testarNumerosValidos();
    testarNumerosNegativos();
    testarNumerosComLetras();
    testarNumerosComSimbolos();
    testarNumerosComEspacos();
    testarNumerosVazios();
}

void TestsNumero::testarNumerosValidos()
{
    std::vector<std::string> numeros = {
        "1", "123", "9999", "456", "789"
    };

    for (const auto& numero : numeros)
    {
        try
        {
            Numero n(numero);
            checar(true, "Numero valido aceito: " + numero);
        }
        catch (...)
        {
            checar(false, "Numero valido rejeitado: " + numero);
        }
    }
}

void TestsNumero::testarNumerosNegativos()
{
    std::vector<std::string> numeros = {
        "-1", "-123", "-9999"
    };

    for (const auto& numero : numeros)
    {
        try
        {
            Numero n(numero);
            checar(false, "Numero negativo aceito: " + numero);
        }
        catch (...)
        {
            checar(true, "Numero negativo rejeitado: " + numero);
        }
    }
}

void TestsNumero::testarNumerosComLetras()
{
    std::vector<std::string> numeros = {
        "12a3", "abc", "9b9c"
    };

    for (const auto& numero : numeros)
    {
        try
        {
            Numero n(numero);
            checar(false, "Numero com letras aceito: " + numero);
        }
        catch (...)
        {
            checar(true, "Numero com letras rejeitado: " + numero);
        }
    }
}

void TestsNumero::testarNumerosComSimbolos()
{
    std::vector<std::string> numeros = {
        "12@3", "99#9", "!000", "45.67"
    };

    for (const auto& numero : numeros)
    {
        try
        {
            Numero n(numero);
            checar(false, "Numero com simbolo aceito: " + numero);
        }
        catch (...)
        {
            checar(true, "Numero com simbolo rejeitado: " + numero);
        }
    }
}

void TestsNumero::testarNumerosComEspacos()
{
    std::vector<std::string> numeros = {
        " 123", "12 3", "123 ", "1 2 3 4"
    };

    for (const auto& numero : numeros)
    {
        try
        {
            Numero n(numero);
            checar(false, "Numero com espaco aceito: " + numero);
        }
        catch (...)
        {
            checar(true, "Numero com espaco rejeitado: " + numero);
        }
    }
}

void TestsNumero::testarNumerosVazios()
{
    std::vector<std::string> numeros = {
        "", " "
    };

    for (const auto& numero : numeros)
    {
        try
        {
            Numero n(numero);
            checar(false, "Numero vazio aceito: '" + numero + "'");
        }
        catch (...)
        {
            checar(true, "Numero vazio rejeitado: '" + numero + "'");
        }
    }
}