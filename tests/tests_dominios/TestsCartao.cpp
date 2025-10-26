//
// Created by caleb on 25/10/2025.
//

#include "TestsCartao.h"

void TestsCartao::executar()
{
    testarCartoesValidos();
    testarCartoesComMenosDigitos();
    testarCartoesComMaisDigitos();
    testarCartoesComLetras();
    testarCartoesComSimbolos();
    testarCartoesComEspacos();
}

void TestsCartao::testarCartoesValidos()
{
    std::vector<std::string> cartoes = {
        "4111111111111111", // Visa
        "5500000000000004", // MasterCard
        "340000000000009", // American Express (15 digitos, se permitido)
        "6011000000000004", // Discover
        "3530111333300000" // JCB
    };

    for (const auto& cartao : cartoes)
    {
        try
        {
            Cartao c(cartao);
            checar(true, "Cartao valido aceito: " + cartao);
        }
        catch (...)
        {
            checar(false, "Cartao valido rejeitado: " + cartao);
        }
    }
}

void TestsCartao::testarCartoesComMenosDigitos()
{
    std::vector<std::string> cartoes = {
        "411111111111", "55000000", "1234567890123"
    };

    for (const auto& cartao : cartoes)
    {
        try
        {
            Cartao c(cartao);
            checar(false, "Cartao com poucos digitos aceito: " + cartao);
        }
        catch (...)
        {
            checar(true, "Cartao com poucos digitos rejeitado: " + cartao);
        }
    }
}

void TestsCartao::testarCartoesComMaisDigitos()
{
    std::vector<std::string> cartoes = {
        "41111111111111112222", "55000000000000040000"
    };

    for (const auto& cartao : cartoes)
    {
        try
        {
            Cartao c(cartao);
            checar(false, "Cartao com muitos digitos aceito: " + cartao);
        }
        catch (...)
        {
            checar(true, "Cartao com muitos digitos rejeitado: " + cartao);
        }
    }
}

void TestsCartao::testarCartoesComLetras()
{
    std::vector<std::string> cartoes = {
        "4111a11111111111", "5500b00000000004", "abcdabcdabcdabcd"
    };

    for (const auto& cartao : cartoes)
    {
        try
        {
            Cartao c(cartao);
            checar(false, "Cartao com letras aceito: " + cartao);
        }
        catch (...)
        {
            checar(true, "Cartao com letras rejeitado: " + cartao);
        }
    }
}

void TestsCartao::testarCartoesComSimbolos()
{
    std::vector<std::string> cartoes = {
        "4111-1111-1111-1111", "5500.0000.0000.0004", "6011@0000#0000$0004"
    };

    for (const auto& cartao : cartoes)
    {
        try
        {
            Cartao c(cartao);
            checar(false, "Cartao com simbolos aceito: " + cartao);
        }
        catch (...)
        {
            checar(true, "Cartao com simbolos rejeitado: " + cartao);
        }
    }
}

void TestsCartao::testarCartoesComEspacos()
{
    std::vector<std::string> cartoes = {
        "4111 1111 1111 1111", "5500 0000 0000 0004", "6011 0000 0000 0004"
    };

    for (const auto& cartao : cartoes)
    {
        try
        {
            Cartao c(cartao);
            checar(false, "Cartao com espacos aceito: " + cartao);
        }
        catch (...)
        {
            checar(true, "Cartao com espacos rejeitado: " + cartao);
        }
    }
}