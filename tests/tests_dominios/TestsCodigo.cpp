//
// Created by caleb on 25/10/2025.
//

#include "TestsCodigo.h"

void TestsCodigo::executar()
{
    testarCodigosValidos();
    testarCodigosComCaracteresInvalidos();
    testarCodigosComEspacos();
    testarCodigosMuitoCurtos();
    testarCodigosMuitoLongos();
}

void TestsCodigo::testarCodigosValidos()
{
    std::vector<std::string> codigos = {
        "ABC123", "X9Y8Z7", "Codigo01", "A1B2C3", "ZXC987"
    };

    for (const auto& codigo : codigos)
    {
        try
        {
            Codigo c(codigo);
            checar(true, "Codigo valido aceito: " + codigo);
        }
        catch (...)
        {
            checar(false, "Codigo valido rejeitado: " + codigo);
        }
    }
}

void TestsCodigo::testarCodigosComCaracteresInvalidos()
{
    std::vector<std::string> codigos = {
        "ABC@123", "X9Y#Z7", "Codigo!", "A1B2*C3", "ZXC$987"
    };

    for (const auto& codigo : codigos)
    {
        try
        {
            Codigo c(codigo);
            checar(false, "Codigo com caractere invalido aceito: " + codigo);
        }
        catch (...)
        {
            checar(true, "Codigo com caractere invalido rejeitado: " + codigo);
        }
    }
}

void TestsCodigo::testarCodigosComEspacos()
{
    std::vector<std::string> codigos = {
        "ABC 123", " X9Y8Z7", "Codigo 01", "A1B2 C3", "ZXC987 "
    };

    for (const auto& codigo : codigos)
    {
        try
        {
            Codigo c(codigo);
            checar(false, "Codigo com espaco aceito: " + codigo);
        }
        catch (...)
        {
            checar(true, "Codigo com espaco rejeitado: " + codigo);
        }
    }
}

void TestsCodigo::testarCodigosMuitoCurtos()
{
    std::vector<std::string> codigos = {
        "A1", "X9", "C0", "Z", "1"
    };

    for (const auto& codigo : codigos)
    {
        try
        {
            Codigo c(codigo);
            checar(false, "Codigo muito curto aceito: " + codigo);
        }
        catch (...)
        {
            checar(true, "Codigo muito curto rejeitado: " + codigo);
        }
    }
}

void TestsCodigo::testarCodigosMuitoLongos()
{
    std::vector<std::string> codigos = {
        "ABC123XYZ789DEF456", // 18 caracteres
        std::string(25, 'A') // 25 caracteres
    };

    for (const auto& codigo : codigos)
    {
        try
        {
            Codigo c(codigo);
            checar(false, "Codigo muito longo aceito: " + codigo);
        }
        catch (...)
        {
            checar(true, "Codigo muito longo rejeitado: " + codigo);
        }
    }
}