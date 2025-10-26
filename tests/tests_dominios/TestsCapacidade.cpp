//
// Created by caleb on 25/10/2025.
//

#include "TestsCapacidade.h"

void TestsCapacidade::executar()
{
    testarCapacidadesValidas();
    testarCapacidadesNegativas();
    testarCapacidadesZero();
    testarCapacidadesMuitoAltas();
}

void TestsCapacidade::testarCapacidadesValidas()
{
    std::vector<int> capacidades = {1, 2, 4, 10, 999};

    for (int capacidade : capacidades)
    {
        try
        {
            Capacidade c(capacidade);
            checar(true, "Capacidade valida aceita: " + std::to_string(capacidade));
        }
        catch (...)
        {
            checar(false, "Capacidade valida rejeitada: " + std::to_string(capacidade));
        }
    }
}

void TestsCapacidade::testarCapacidadesNegativas()
{
    std::vector<int> capacidades = {-1, -10, -999};

    for (int capacidade : capacidades)
    {
        try
        {
            Capacidade c(capacidade);
            checar(false, "Capacidade negativa aceita: " + std::to_string(capacidade));
        }
        catch (...)
        {
            checar(true, "Capacidade negativa rejeitada: " + std::to_string(capacidade));
        }
    }
}

void TestsCapacidade::testarCapacidadesZero()
{
    try
    {
        Capacidade c(0);
        checar(false, "Capacidade zero aceita");
    }
    catch (...)
    {
        checar(true, "Capacidade zero rejeitada");
    }
}

void TestsCapacidade::testarCapacidadesMuitoAltas()
{
    std::vector<int> capacidades = {1000, 5000, 99999};

    for (int capacidade : capacidades)
    {
        try
        {
            Capacidade c(capacidade);
            checar(false, "Capacidade muito alta aceita: " + std::to_string(capacidade));
        }
        catch (...)
        {
            checar(true, "Capacidade muito alta rejeitada: " + std::to_string(capacidade));
        }
    }
}