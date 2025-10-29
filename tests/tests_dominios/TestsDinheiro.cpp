//
// Created by caleb on 25/10/2025.
//

#include "TestsDinheiro.h"

void TestsDinheiro::executar()
{
    testarValoresValidos();
    testarValoresNegativos();
    testarValoresZero();
    testarValoresMuitoAltos();
}

void TestsDinheiro::testarValoresValidos()
{
    std::vector<int> valores = {
        1, // R$0,01
        100, // R$1,00
        9999, // R$99,99
        100000, // R$1.000,00
        99999999, // R$999.999,99
        100000000 // R$1.000.000,00
    };

    for (int valor : valores)
    {
        try
        {
            Dinheiro d(valor);
            checar(true, "Valor valido aceito: " + std::to_string(valor));
        }
        catch (...)
        {
            checar(false, "Valor valido rejeitado: " + std::to_string(valor));
        }
    }
}

void TestsDinheiro::testarValoresNegativos()
{
    std::vector<int> valores = {-1, -100, -99999999};

    for (int valor : valores)
    {
        try
        {
            Dinheiro d(valor);
            checar(false, "Valor negativo aceito: " + std::to_string(valor));
        }
        catch (...)
        {
            checar(true, "Valor negativo rejeitado: " + std::to_string(valor));
        }
    }
}

void TestsDinheiro::testarValoresZero()
{
    try
    {
        Dinheiro d(0);
        checar(false, "Valor zero aceito");
    }
    catch (...)
    {
        checar(true, "Valor zero rejeitado");
    }
}

void TestsDinheiro::testarValoresMuitoAltos()
{
    std::vector<int> valores = {100000001, 500000000, 999999999};

    for (int valor : valores)
    {
        try
        {
            Dinheiro d(valor);
            checar(false, "Valor muito alto aceito: " + std::to_string(valor));
        }
        catch (...)
        {
            checar(true, "Valor muito alto rejeitado: " + std::to_string(valor));
        }
    }
}