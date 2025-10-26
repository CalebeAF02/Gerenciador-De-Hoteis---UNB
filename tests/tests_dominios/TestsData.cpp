//
// Created by caleb on 25/10/2025.
//

#include "TestsData.h"

void TestsData::executar()
{
    testarDatasValidas();
    testarDatasComFormatoInvalido();
    testarDatasComDiaInvalido();
    testarDatasComMesInvalido();
    testarDatasComAnoInvalido();
    testarDatasBissextas();
}

void TestsData::testarDatasValidas()
{
    std::vector<std::string> datas = {
        "01/01/2000",
        "15/06/2025",
        "31/12/2099",
        "30/04/2023",
        "28/02/2024"
    };

    for (const auto& dataStr : datas)
    {
        try
        {
            Data d(dataStr);
            checar(true, "Data valida aceita: " + dataStr);
        }
        catch (...)
        {
            checar(false, "Data valida rejeitada: " + dataStr);
        }
    }
}

void TestsData::testarDatasComFormatoInvalido()
{
    std::vector<std::string> datas = {
        "01-01-2000", // separador errado
        "01012000", // sem separador
        "01/01/00", // ano incompleto
        "1/1/2000", // sem zeros
        "01/01/2000 " // espaco extra
    };

    for (const auto& dataStr : datas)
    {
        try
        {
            Data d(dataStr);
            checar(false, "Data com formato invalido aceita: " + dataStr);
        }
        catch (...)
        {
            checar(true, "Data com formato invalido rejeitada: " + dataStr);
        }
    }
}

void TestsData::testarDatasComDiaInvalido()
{
    std::vector<std::string> datas = {
        "32/01/2025", // dia > 31
        "00/05/2025", // dia 0
        "31/04/2025", // abril tem 30
        "29/02/2023" // nao e bissexto
    };

    for (const auto& dataStr : datas)
    {
        try
        {
            Data d(dataStr);
            checar(false, "Data com dia invalido aceita: " + dataStr);
        }
        catch (...)
        {
            checar(true, "Data com dia invalido rejeitada: " + dataStr);
        }
    }
}

void TestsData::testarDatasComMesInvalido()
{
    std::vector<std::string> datas = {
        "15/00/2025", // mes 0
        "10/13/2025", // mes > 12
        "01/-1/2025" // mes negativo
    };

    for (const auto& dataStr : datas)
    {
        try
        {
            Data d(dataStr);
            checar(false, "Data com mes invalido aceita: " + dataStr);
        }
        catch (...)
        {
            checar(true, "Data com mes invalido rejeitada: " + dataStr);
        }
    }
}

void TestsData::testarDatasComAnoInvalido()
{
    std::vector<std::string> datas = {
        "01/01/1999", // abaixo do limite
        "31/12/2100", // acima do limite
        "15/06/0000" // ano invalido
    };

    for (const auto& dataStr : datas)
    {
        try
        {
            Data d(dataStr);
            checar(false, "Data com ano invalido aceita: " + dataStr);
        }
        catch (...)
        {
            checar(true, "Data com ano invalido rejeitada: " + dataStr);
        }
    }
}

void TestsData::testarDatasBissextas()
{
    std::vector<std::string> datas = {
        "29/02/2024", // valido
        "29/02/2020", // valido
        "29/02/2023", // invalido
        "29/02/2100" // invalido (ano nao bissexto)
    };

    for (const auto& dataStr : datas)
    {
        try
        {
            Data d(dataStr);
            bool isBissexto = (dataStr == "29/02/2024" || dataStr == "29/02/2020");
            checar(isBissexto, "Teste de bissexto: " + dataStr);
        }
        catch (...)
        {
            checar(dataStr == "29/02/2023" || dataStr == "29/02/2100", "Data bissexta invalida rejeitada: " + dataStr);
        }
    }
}