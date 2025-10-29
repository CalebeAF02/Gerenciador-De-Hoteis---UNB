//
// Created by caleb on 25/10/2025.
//

#include "TestsEndereco.h"

void TestsEndereco::executar()
{
    testarEnderecosValidos();
    testarEnderecosComCaracteresInvalidos();
    testarEnderecosComInicioOuFimInvalido();
    testarEnderecosMuitoLongos();
}

void TestsEndereco::testarEnderecosValidos()
{
    std::vector<std::string> enderecos = {
        "Rua das Flores, 123",
        "Av. Brasil - Bloco A",
        "Praca Central 45",
        "Rua Joao Goulart, 789",
        "Alameda dos Anjos - Casa 10"
    };

    for (const auto& endereco : enderecos)
    {
        try
        {
            Endereco e(endereco);
            checar(true, "Endereco valido aceito: " + endereco);
        }
        catch (...)
        {
            checar(false, "Endereco valido rejeitado: " + endereco);
        }
    }
}

void TestsEndereco::testarEnderecosComCaracteresInvalidos()
{
    std::vector<std::string> enderecos = {
        "Rua das Flores @ 123",
        "Av. Brasil # Bloco A",
        "Praca Central * 45",
        "Rua Joao Goulart ! 789"
    };

    for (const auto& endereco : enderecos)
    {
        try
        {
            Endereco e(endereco);
            checar(false, "Endereco com caractere invalido aceito: " + endereco);
        }
        catch (...)
        {
            checar(true, "Endereco com caractere invalido rejeitado: " + endereco);
        }
    }
}

void TestsEndereco::testarEnderecosComInicioOuFimInvalido()
{
    std::vector<std::string> enderecos = {
        ".Rua das Flores", // comeca com ponto
        "Rua das Flores.", // termina com ponto
        "-Av. Brasil", // comeca com hifen
        "Praca Central-" // termina com hifen
    };

    for (const auto& endereco : enderecos)
    {
        try
        {
            Endereco e(endereco);
            checar(false, "Endereco com inicio/fim invalido aceito: " + endereco);
        }
        catch (...)
        {
            checar(true, "Endereco com inicio/fim invalido rejeitado: " + endereco);
        }
    }
}

void TestsEndereco::testarEnderecosMuitoLongos()
{
    std::vector<std::string> enderecos = {
        std::string(101, 'A'), // 101 caracteres
        "Rua " + std::string(97, 'B') // ultrapassa 100
    };

    for (const auto& endereco : enderecos)
    {
        try
        {
            Endereco e(endereco);
            checar(false, "Endereco muito longo aceito: " + endereco);
        }
        catch (...)
        {
            checar(true, "Endereco muito longo rejeitado: " + endereco);
        }
    }
}