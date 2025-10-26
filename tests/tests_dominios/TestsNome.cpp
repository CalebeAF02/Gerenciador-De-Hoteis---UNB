//
// Created by caleb on 25/10/2025.
//
#include "TestsNome.h"

#include <vector>

void TestsNome::executar()
{
    testarNomesValidos();
    testarNomesInvalidos();
    testarNomesComNumeros();
    testarNomesMuitoLongos();
    testarNomesSemMaiusculaInicial();
    testarNomesComEspacoInvalido();
    testarNomesComCaracteresEspeciais();
}

void TestsNome::testarNomesValidos()
{
    std::vector<std::string> nomes = {
        "Joao da Silva",
        "Maria Clara",
        "Carlos Eduardo",
        "Ana Beatriz",
        "Fernanda Lima"
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(true, "Nome valido aceito: " + nome);
        }
        catch (...)
        {
            checar(false, "Nome valido rejeitado: " + nome);
        }
    }
}

void TestsNome::testarNomesInvalidos()
{
    std::vector<std::string> nomes = {
        "J@o",
        "Joao#Silva",
        "Joao!",
        "Joao..Silva",
        "Joao--Silva"
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(false, "Nome invalido aceito: " + nome);
        }
        catch (...)
        {
            checar(true, "Nome invalido rejeitado: " + nome);
        }
    }
}

void TestsNome::testarNomesComNumeros()
{
    std::vector<std::string> nomes = {
        "Joao123",
        "Maria 2",
        "Carlos99",
        "Ana1Beatriz"
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(false, "Nome com numeros aceito: " + nome);
        }
        catch (...)
        {
            checar(true, "Nome com numeros rejeitado: " + nome);
        }
    }
}

void TestsNome::testarNomesMuitoLongos()
{
    std::vector<std::string> nomes = {
        std::string(101, 'A'),
        "Joao da Silva " + std::string(90, 'B')
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(false, "Nome muito longo aceito: " + nome);
        }
        catch (...)
        {
            checar(true, "Nome muito longo rejeitado: " + nome);
        }
    }
}

void TestsNome::testarNomesSemMaiusculaInicial()
{
    std::vector<std::string> nomes = {
        "joao da Silva",
        "maria clara",
        "carlos eduardo"
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(false, "Nome sem maiuscula inicial aceito: " + nome);
        }
        catch (...)
        {
            checar(true, "Nome sem maiuscula inicial rejeitado: " + nome);
        }
    }
}

void TestsNome::testarNomesComEspacoInvalido()
{
    std::vector<std::string> nomes = {
        " Joao",
        "Joao ",
        " Joao Silva "
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(false, "Nome com espaco invalido aceito: " + nome);
        }
        catch (...)
        {
            checar(true, "Nome com espaco invalido rejeitado: " + nome);
        }
    }
}

void TestsNome::testarNomesComCaracteresEspeciais()
{
    vector<std::string> nomes = {
        "Joao@Silva",
        "Maria*Clara",
        "Carlos&Eduardo",
        "Ana#Beatriz"
    };

    for (const auto& nome : nomes)
    {
        try
        {
            Nome n(nome);
            checar(false, "Nome com caractere especial aceito: " + nome);
        }
        catch (...)
        {
            checar(true, "Nome com caractere especial rejeitado: " + nome);
        }
    }
}