//
// Created by caleb on 25/10/2025.
//

#include "TestsHospede.h"

void TestsHospede::executar()
{
    testarNome();
    testarNomeInvalido();
    testarEmail();
    testarEmailInvalido();
    testarEndereco();
    testarEnderecoInvalido();
    testarCartao();
    testarCartaoInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsHospede::testarNome()
{
    try
    {
        Hospede h;
        h.setNome(Nome("Maria Clara"));
        checar(true, "Nome valido aceito");
    }
    catch (...)
    {
        checar(false, "Nome valido rejeitado");
    }
}

void TestsHospede::testarNomeInvalido()
{
    try
    {
        Hospede h;
        h.setNome(Nome("Maria@Clara"));
        checar(false, "Nome invalido aceito");
    }
    catch (...)
    {
        checar(true, "Nome invalido rejeitado");
    }
}

void TestsHospede::testarEmail()
{
    try
    {
        Hospede h;
        h.setEmail(Email("maria@exemplo.com"));
        checar(true, "Email valido aceito");
    }
    catch (...)
    {
        checar(false, "Email valido rejeitado");
    }
}

void TestsHospede::testarEmailInvalido()
{
    try
    {
        Hospede h;
        h.setEmail(Email("maria@.com"));
        checar(false, "Email invalido aceito");
    }
    catch (...)
    {
        checar(true, "Email invalido rejeitado");
    }
}

void TestsHospede::testarEndereco()
{
    try
    {
        Hospede h;
        h.setEndereco(Endereco("Rua das Flores, 123"));
        checar(true, "Endereco valido aceito");
    }
    catch (...)
    {
        checar(false, "Endereco valido rejeitado");
    }
}

void TestsHospede::testarEnderecoInvalido()
{
    try
    {
        Hospede h;
        h.setEndereco(Endereco("Rua das Flores @ 123"));
        checar(false, "Endereco invalido aceito");
    }
    catch (...)
    {
        checar(true, "Endereco invalido rejeitado");
    }
}

void TestsHospede::testarCartao()
{
    try
    {
        Hospede h;
        h.setCartao(Cartao("4111111111111111")); // Exemplo valido
        checar(true, "Cartao valido aceito");
    }
    catch (...)
    {
        checar(false, "Cartao valido rejeitado");
    }
}

void TestsHospede::testarCartaoInvalido()
{
    try
    {
        Hospede h;
        h.setCartao(Cartao("4111-1111-1111-1111")); // simbolo invalido
        checar(false, "Cartao invalido aceito");
    }
    catch (...)
    {
        checar(true, "Cartao invalido rejeitado");
    }
}

void TestsHospede::testarConstrucaoCompleta()
{
    try
    {
        Hospede h;
        h.setNome(Nome("Maria Clara"));
        h.setEmail(Email("maria@exemplo.com"));
        h.setEndereco(Endereco("Rua das Flores, 123"));
        h.setCartao(Cartao("4111111111111111"));
        checar(true, "Hospede construido com todos os dados validos");
    }
    catch (...)
    {
        checar(false, "Falha ao construir hospede completo");
    }
}

void TestsHospede::testarConstrucaoInvalida()
{
    try
    {
        Hospede h;
        h.setNome(Nome("Maria Clara"));
        h.setEmail(Email("maria@exemplo.com"));
        h.setEndereco(Endereco("Rua das Flores, 123"));
        h.setCartao(Cartao("4111-1111-1111-1111")); // invalido
        checar(false, "Hospede construido com cartao invalido");
    }
    catch (...)
    {
        checar(true, "Falha esperada ao construir hospede com dado invalido");
    }
}

void TestsHospede::testarGetters()
{
    Hospede h;
    Nome nome("Maria Clara");
    Email email("maria@exemplo.com");
    Endereco endereco("Rua das Flores, 123");
    Cartao cartao("4111111111111111");

    h.setNome(nome);
    h.setEmail(email);
    h.setEndereco(endereco);
    h.setCartao(cartao);

    checar(h.getNome() == nome.getValor(), "Getter de nome funcionando");
    checar(h.getEmail() == email.getValor(), "Getter de email funcionando");
    checar(h.getEndereco() == endereco.getValor(), "Getter de endereco funcionando");
    checar(h.getCartao() == cartao.getValor(), "Getter de cartao funcionando");
}