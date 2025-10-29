//
// Created by caleb on 25/10/2025.
//

#include "TestsHotel.h"

void TestsHotel::executar()
{
    testarNome();
    testarNomeInvalido();
    testarEndereco();
    testarEnderecoInvalido();
    testarTelefone();
    testarTelefoneInvalido();
    testarCodigo();
    testarCodigoInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsHotel::testarNome()
{
    try
    {
        Hotel h;
        h.setNome(Nome("Hotel Central"));
        checar(true, "Nome valido aceito");
    }
    catch (...)
    {
        checar(false, "Nome valido rejeitado");
    }
}

void TestsHotel::testarNomeInvalido()
{
    try
    {
        Hotel h;
        h.setNome(Nome("Hotel@Central"));
        checar(false, "Nome invalido aceito");
    }
    catch (...)
    {
        checar(true, "Nome invalido rejeitado");
    }
}

void TestsHotel::testarEndereco()
{
    try
    {
        Hotel h;
        h.setEndereco(Endereco("Av. Brasil, 1000"));
        checar(true, "Endereco valido aceito");
    }
    catch (...)
    {
        checar(false, "Endereco valido rejeitado");
    }
}

void TestsHotel::testarEnderecoInvalido()
{
    try
    {
        Hotel h;
        h.setEndereco(Endereco("Av. Brasil @ 1000"));
        checar(false, "Endereco invalido aceito");
    }
    catch (...)
    {
        checar(true, "Endereco invalido rejeitado");
    }
}

void TestsHotel::testarTelefone()
{
    try
    {
        Hotel h;
        h.setTelefone(Telefone("(61) 91234-5678"));
        checar(true, "Telefone valido aceito");
    }
    catch (...)
    {
        checar(false, "Telefone valido rejeitado");
    }
}

void TestsHotel::testarTelefoneInvalido()
{
    try
    {
        Hotel h;
        h.setTelefone(Telefone("(61) 01234-5678")); // prefixo invalido
        checar(false, "Telefone invalido aceito");
    }
    catch (...)
    {
        checar(true, "Telefone invalido rejeitado");
    }
}

void TestsHotel::testarCodigo()
{
    try
    {
        Hotel h;
        h.setCodigo(Codigo("ABC123"));
        checar(true, "Codigo valido aceito");
    }
    catch (...)
    {
        checar(false, "Codigo valido rejeitado");
    }
}

void TestsHotel::testarCodigoInvalido()
{
    try
    {
        Hotel h;
        h.setCodigo(Codigo("ABC@123"));
        checar(false, "Codigo invalido aceito");
    }
    catch (...)
    {
        checar(true, "Codigo invalido rejeitado");
    }
}

void TestsHotel::testarConstrucaoCompleta()
{
    try
    {
        Hotel h;
        h.setNome(Nome("Hotel Central"));
        h.setEndereco(Endereco("Av. Brasil, 1000"));
        h.setTelefone(Telefone("(61) 91234-5678"));
        h.setCodigo(Codigo("ABC123"));
        checar(true, "Hotel construido com todos os dados validos");
    }
    catch (...)
    {
        checar(false, "Falha ao construir hotel completo");
    }
}

void TestsHotel::testarConstrucaoInvalida()
{
    try
    {
        Hotel h;
        h.setNome(Nome("Hotel Central"));
        h.setEndereco(Endereco("Av. Brasil, 1000"));
        h.setTelefone(Telefone("(61) 91234-5678"));
        h.setCodigo(Codigo("ABC@123")); // invalido
        checar(false, "Hotel construido com codigo invalido");
    }
    catch (...)
    {
        checar(true, "Falha esperada ao construir hotel com dado invalido");
    }
}

void TestsHotel::testarGetters()
{
    Hotel h;
    Nome nome("Hotel Central");
    Endereco endereco("Av. Brasil, 1000");
    Telefone telefone("(61) 91234-5678");
    Codigo codigo("ABC123");

    h.setNome(nome);
    h.setEndereco(endereco);
    h.setTelefone(telefone);
    h.setCodigo(codigo);

    checar(h.getNome() == nome.getValor(), "Getter de nome funcionando");
    checar(h.getEndereco() == endereco.getValor(), "Getter de endereco funcionando");
    checar(h.getTelefone() == telefone.getValor(), "Getter de telefone funcionando");
    checar(h.getCodigo() == codigo.getValor(), "Getter de codigo funcionando");
}