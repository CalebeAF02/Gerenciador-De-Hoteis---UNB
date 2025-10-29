//
// Created by caleb on 25/10/2025.
//

#include "TestsQuarto.h"

void TestsQuarto::executar()
{
    testarNumero();
    testarNumeroInvalido();
    testarCapacidade();
    testarCapacidadeInvalida();
    testarDiaria();
    testarDiariaInvalida();
    testarRamal();
    testarRamalInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsQuarto::testarNumero()
{
    try
    {
        Quarto q;
        q.setNumero(Numero("101"));
        checar(true, "Numero valido aceito");
    }
    catch (...)
    {
        checar(false, "Numero valido rejeitado");
    }
}

void TestsQuarto::testarNumeroInvalido()
{
    try
    {
        Quarto q;
        q.setNumero(Numero("10A"));
        checar(false, "Numero invalido aceito");
    }
    catch (...)
    {
        checar(true, "Numero invalido rejeitado");
    }
}

void TestsQuarto::testarCapacidade()
{
    try
    {
        Quarto q;
        q.setCapacidade(Capacidade(2));
        checar(true, "Capacidade valida aceita");
    }
    catch (...)
    {
        checar(false, "Capacidade valida rejeitada");
    }
}

void TestsQuarto::testarCapacidadeInvalida()
{
    try
    {
        Quarto q;
        q.setCapacidade(Capacidade(0));
        checar(false, "Capacidade invalida aceita");
    }
    catch (...)
    {
        checar(true, "Capacidade invalida rejeitada");
    }
}

void TestsQuarto::testarDiaria()
{
    try
    {
        Quarto q;
        q.setDiaria(Dinheiro(5000)); // R$50,00
        checar(true, "Valor valido aceito");
    }
    catch (...)
    {
        checar(false, "Valor valido rejeitado");
    }
}

void TestsQuarto::testarDiariaInvalida()
{
    try
    {
        Quarto q;
        q.setDiaria(Dinheiro(0));
        checar(false, "Valor invalido aceito");
    }
    catch (...)
    {
        checar(true, "Valor invalido rejeitado");
    }
}

void TestsQuarto::testarRamal()
{
    try
    {
        Quarto q;
        q.setRamal(Ramal("1234"));
        checar(true, "Ramal valido aceito");
    }
    catch (...)
    {
        checar(false, "Ramal valido rejeitado");
    }
}

void TestsQuarto::testarRamalInvalido()
{
    try
    {
        Quarto q;
        q.setRamal(Ramal("12a4"));
        checar(false, "Ramal invalido aceito");
    }
    catch (...)
    {
        checar(true, "Ramal invalido rejeitado");
    }
}

void TestsQuarto::testarConstrucaoCompleta()
{
    try
    {
        Quarto q;
        q.setNumero(Numero("101"));
        q.setCapacidade(Capacidade(2));
        q.setDiaria(Dinheiro(5000));
        q.setRamal(Ramal("1234"));
        checar(true, "Quarto construido com todos os dados validos");
    }
    catch (...)
    {
        checar(false, "Falha ao construir quarto completo");
    }
}

void TestsQuarto::testarConstrucaoInvalida()
{
    try
    {
        Quarto q;
        q.setNumero(Numero("101"));
        q.setCapacidade(Capacidade(2));
        q.setDiaria(Dinheiro(0)); // invalido
        q.setRamal(Ramal("1234"));
        checar(false, "Quarto construido com valor invalido");
    }
    catch (...)
    {
        checar(true, "Falha esperada ao construir quarto com dado invalido");
    }
}

void TestsQuarto::testarGetters()
{
    Quarto q;
    Numero numero("101");
    Capacidade capacidade(2);
    Dinheiro diaria(5000);
    Ramal ramal("1234");

    q.setNumero(numero);
    q.setCapacidade(capacidade);
    q.setDiaria(diaria);
    q.setRamal(ramal);

    checar(q.getNumero() == numero.getValor(), "Getter de numero funcionando");
    checar(q.getCapacidade() == capacidade.getValor(), "Getter de capacidade funcionando");
    checar(q.getDiaria() == diaria.getValor(), "Getter de dinheiro funcionando");
    checar(q.getRamal() == ramal.getValor(), "Getter de ramal funcionando");
}