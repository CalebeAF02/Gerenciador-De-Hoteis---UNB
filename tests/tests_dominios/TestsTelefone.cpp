//
// Created by caleb on 25/10/2025.
//

#include "TestsTelefone.h"

void TestsTelefone::executar()
{
    testarTelefonesValidos();
    testarTelefonesComFormatoInvalido();
    testarTelefonesComPrefixoInvalido();
    testarTelefonesComCaracteresInvalidos();
    testarTelefonesComDigitosInvalidos();
}

void TestsTelefone::testarTelefonesValidos()
{
    std::vector<std::string> telefones = {
        "(61) 91234-5678",
        "(11) 98765-4321",
        "(85) 99999-0000",
        "(21) 95555-1234",
        "(31) 99888-7777"
    };

    for (const auto& telefone : telefones)
    {
        try
        {
            Telefone t(telefone);
            checar(true, "Telefone valido aceito: " + telefone);
        }
        catch (...)
        {
            checar(false, "Telefone valido rejeitado: " + telefone);
        }
    }
}

void TestsTelefone::testarTelefonesComFormatoInvalido()
{
    std::vector<std::string> telefones = {
        "61 91234-5678", // sem parenteses
        "(61)91234-5678", // sem espaco
        "(61)-91234-5678", // hifen fora do lugar
        "(61912345678)", // tudo junto
        "(61) 912345678" // sem hifen
    };

    for (const auto& telefone : telefones)
    {
        try
        {
            Telefone t(telefone);
            checar(false, "Telefone com formato invalido aceito: " + telefone);
        }
        catch (...)
        {
            checar(true, "Telefone com formato invalido rejeitado: " + telefone);
        }
    }
}

void TestsTelefone::testarTelefonesComPrefixoInvalido()
{
    std::vector<std::string> telefones = {
        "(61) 01234-5678",
        "(11) 12345-6789",
        "(85) 03456-7890",
        "(21) 00000-1234",
        "(31) 04567-8901"
    };

    for (const auto& telefone : telefones)
    {
        try
        {
            Telefone t(telefone);
            checar(false, "Telefone com prefixo invalido aceito: " + telefone);
        }
        catch (...)
        {
            checar(true, "Telefone com prefixo invalido rejeitado: " + telefone);
        }
    }
}

void TestsTelefone::testarTelefonesComCaracteresInvalidos()
{
    std::vector<std::string> telefones = {
        "(61) 91234@5678",
        "(11) 98765#4321",
        "(85) 99999*0000",
        "(21) 95555!1234"
    };

    for (const auto& telefone : telefones)
    {
        try
        {
            Telefone t(telefone);
            checar(false, "Telefone com caractere invalido aceito: " + telefone);
        }
        catch (...)
        {
            checar(true, "Telefone com caractere invalido rejeitado: " + telefone);
        }
    }
}

void TestsTelefone::testarTelefonesComDigitosInvalidos()
{
    std::vector<std::string> telefones = {
        "(61) 91234-567", // faltando digito
        "(11) 987654-3210", // digitos a mais
        "(85) 9999-0000", // formato fixo com digito inicial invalido
        "(21) 9555-1234" // formato fixo com digito a menos
    };

    for (const auto& telefone : telefones)
    {
        try
        {
            Telefone t(telefone);
            checar(false, "Telefone com quantidade de digitos invalida aceito: " + telefone);
        }
        catch (...)
        {
            checar(true, "Telefone com quantidade de digitos invalida rejeitado: " + telefone);
        }
    }
}