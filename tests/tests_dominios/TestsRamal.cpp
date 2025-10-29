//
// Created by caleb on 25/10/2025.
//

#include "TestsRamal.h"

void TestsRamal::executar()
{
    testarRamaisValidos();
    testarRamaisComMenosDigitos();
    testarRamaisComMaisDigitos();
    testarRamaisComLetras();
    testarRamaisComSimbolos();
    testarRamaisComEspacos();
}

void TestsRamal::testarRamaisValidos()
{
    std::vector<std::string> ramais = {
        "0000", "1234", "9999", "0456", "7001"
    };

    for (const auto& ramal : ramais)
    {
        try
        {
            Ramal r(ramal);
            checar(true, "Ramal valido aceito: " + ramal);
        }
        catch (...)
        {
            checar(false, "Ramal valido rejeitado: " + ramal);
        }
    }
}

void TestsRamal::testarRamaisComMenosDigitos()
{
    std::vector<std::string> ramais = {
        "0", "12", "123"
    };

    for (const auto& ramal : ramais)
    {
        try
        {
            Ramal r(ramal);
            checar(false, "Ramal com menos de 4 digitos aceito: " + ramal);
        }
        catch (...)
        {
            checar(true, "Ramal com menos de 4 digitos rejeitado: " + ramal);
        }
    }
}

void TestsRamal::testarRamaisComMaisDigitos()
{
    std::vector<std::string> ramais = {
        "12345", "00001", "99999"
    };

    for (const auto& ramal : ramais)
    {
        try
        {
            Ramal r(ramal);
            checar(false, "Ramal com mais de 4 digitos aceito: " + ramal);
        }
        catch (...)
        {
            checar(true, "Ramal com mais de 4 digitos rejeitado: " + ramal);
        }
    }
}

void TestsRamal::testarRamaisComLetras()
{
    std::vector<std::string> ramais = {
        "12a4", "abcd", "9b9c"
    };

    for (const auto& ramal : ramais)
    {
        try
        {
            Ramal r(ramal);
            checar(false, "Ramal com letras aceito: " + ramal);
        }
        catch (...)
        {
            checar(true, "Ramal com letras rejeitado: " + ramal);
        }
    }
}

void TestsRamal::testarRamaisComSimbolos()
{
    std::vector<std::string> ramais = {
        "12@4", "99#9", "!000"
    };

    for (const auto& ramal : ramais)
    {
        try
        {
            Ramal r(ramal);
            checar(false, "Ramal com simbolo aceito: " + ramal);
        }
        catch (...)
        {
            checar(true, "Ramal com simbolo rejeitado: " + ramal);
        }
    }
}

void TestsRamal::testarRamaisComEspacos()
{
    std::vector<std::string> ramais = {
        " 123", "12 3", "123 ", "1 2 3 4"
    };

    for (const auto& ramal : ramais)
    {
        try
        {
            Ramal r(ramal);
            checar(false, "Ramal com espaco aceito: " + ramal);
        }
        catch (...)
        {
            checar(true, "Ramal com espaco rejeitado: " + ramal);
        }
    }
}