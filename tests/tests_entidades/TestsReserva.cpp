//
// Created by caleb on 25/10/2025.
//

#include "TestsReserva.h"

void TestsReserva::executar()
{
    testarChegada();
    testarChegadaInvalida();
    testarPartida();
    testarPartidaInvalida();
    testarDinheiro();
    testarDinheiroInvalido();
    testarCodigo();
    testarCodigoInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsReserva::testarChegada()
{
    try
    {
        Reserva r;
        r.setChegada(Data("01/11/2025"));
        checar(true, "Data de chegada valida aceita");
    }
    catch (...)
    {
        checar(false, "Data de chegada valida rejeitada");
    }
}

void TestsReserva::testarChegadaInvalida()
{
    try
    {
        Reserva r;
        r.setChegada(Data("32/11/2025")); // dia invalido
        checar(false, "Data de chegada invalida aceita");
    }
    catch (...)
    {
        checar(true, "Data de chegada invalida rejeitada");
    }
}

void TestsReserva::testarPartida()
{
    try
    {
        Reserva r;
        r.setPartida(Data("05/11/2025"));
        checar(true, "Data de partida valida aceita");
    }
    catch (...)
    {
        checar(false, "Data de partida valida rejeitada");
    }
}

void TestsReserva::testarPartidaInvalida()
{
    try
    {
        Reserva r;
        r.setPartida(Data("00/11/2025")); // dia invalido
        checar(false, "Data de partida invalida aceita");
    }
    catch (...)
    {
        checar(true, "Data de partida invalida rejeitada");
    }
}

void TestsReserva::testarDinheiro()
{
    try
    {
        Reserva r;
        r.setDinheiro(Dinheiro(10000)); // R$100,00
        checar(true, "Valor valido aceito");
    }
    catch (...)
    {
        checar(false, "Valor valido rejeitado");
    }
}

void TestsReserva::testarDinheiroInvalido()
{
    try
    {
        Reserva r;
        r.setDinheiro(Dinheiro(0)); // invalido
        checar(false, "Valor invalido aceito");
    }
    catch (...)
    {
        checar(true, "Valor invalido rejeitado");
    }
}

void TestsReserva::testarCodigo()
{
    try
    {
        Reserva r;
        r.setCodigo(Codigo("RES123"));
        checar(true, "Codigo valido aceito");
    }
    catch (...)
    {
        checar(false, "Codigo valido rejeitado");
    }
}

void TestsReserva::testarCodigoInvalido()
{
    try
    {
        Reserva r;
        r.setCodigo(Codigo("RES@123"));
        checar(false, "Codigo invalido aceito");
    }
    catch (...)
    {
        checar(true, "Codigo invalido rejeitado");
    }
}

void TestsReserva::testarConstrucaoCompleta()
{
    try
    {
        Reserva r(
            Data("01/11/2025"),
            Data("05/11/2025"),
            Dinheiro(10000),
            Codigo("RES123")
        );
        checar(true, "Reserva construida com todos os dados validos");
    }
    catch (...)
    {
        checar(false, "Falha ao construir reserva completa");
    }
}

void TestsReserva::testarConstrucaoInvalida()
{
    try
    {
        Reserva r(
            Data("01/11/2025"),
            Data("05/11/2025"),
            Dinheiro(0), // invalido
            Codigo("RES123")
        );
        checar(false, "Reserva construida com valor invalido");
    }
    catch (...)
    {
        checar(true, "Falha esperada ao construir reserva com dado invalido");
    }
}

void TestsReserva::testarGetters()
{
    Data chegada("01/11/2025");
    Data partida("05/11/2025");
    Dinheiro dinheiro(10000);
    Codigo codigo("RES123");

    Reserva r;
    r.setChegada(chegada);
    r.setPartida(partida);
    r.setDinheiro(dinheiro);
    r.setCodigo(codigo);

    checar(r.getChegada().toString() == chegada.toString(), "Getter de chegada funcionando");
    checar(r.getPartida().toString() == partida.toString(), "Getter de partida funcionando");
    checar(r.getDinheiro() == dinheiro.getValor(), "Getter de dinheiro funcionando");
    checar(r.getCodigo() == codigo.getValor(), "Getter de codigo funcionando");
}