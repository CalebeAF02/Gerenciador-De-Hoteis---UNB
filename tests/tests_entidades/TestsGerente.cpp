//

// Created by caleb on 25/10/2025.
//
#include "TestsGerente.h"

void TestsGerente::executar()
{
    testarNome();
    testarNomeInvalido();
    testarEmail();
    testarEmailInvalido();
    testarSenha();
    testarSenhaInvalida();
    testarRamal();
    testarRamalInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsGerente::testarNome()
{
    try
    {
        Gerente g;
        g.setNome(Nome("Joao Silva"));
        checar(true, "Nome valido aceito");
    }
    catch (...)
    {
        checar(false, "Nome valido rejeitado");
    }
}

void TestsGerente::testarNomeInvalido()
{
    try
    {
        Gerente g;
        g.setNome(Nome("Joao@Silva"));
        checar(false, "Nome invalido aceito");
    }
    catch (...)
    {
        checar(true, "Nome invalido rejeitado");
    }
}

void TestsGerente::testarEmail()
{
    try
    {
        Gerente g;
        g.setEmail(Email("joao@empresa.com"));
        checar(true, "Email valido aceito");
    }
    catch (...)
    {
        checar(false, "Email valido rejeitado");
    }
}

void TestsGerente::testarEmailInvalido()
{
    try
    {
        Gerente g;
        g.setEmail(Email("joao@.com"));
        checar(false, "Email invalido aceito");
    }
    catch (...)
    {
        checar(true, "Email invalido rejeitado");
    }
}

void TestsGerente::testarSenha()
{
    try
    {
        Gerente g;
        g.setSenha(Senha("A1#a1a1a"));
        checar(true, "Senha valida aceita");
    }
    catch (...)
    {
        checar(false, "Senha valida rejeitada");
    }
}

void TestsGerente::testarSenhaInvalida()
{
    try
    {
        Gerente g;
        g.setSenha(Senha("123")); // muito curta e sem requisitos
        checar(false, "Senha invalida aceita");
    }
    catch (...)
    {
        checar(true, "Senha invalida rejeitada");
    }
}

void TestsGerente::testarRamal()
{
    try
    {
        Gerente g;
        g.setRamal(Ramal("1234"));
        checar(true, "Ramal valido aceito");
    }
    catch (...)
    {
        checar(false, "Ramal valido rejeitado");
    }
}

void TestsGerente::testarRamalInvalido()
{
    try
    {
        Gerente g;
        g.setRamal(Ramal("12a4"));
        checar(false, "Ramal invalido aceito");
    }
    catch (...)
    {
        checar(true, "Ramal invalido rejeitado");
    }
}

void TestsGerente::testarConstrucaoCompleta()
{
    try
    {
        Gerente g;
        g.setNome(Nome("Joao Silva"));
        g.setEmail(Email("joao@empresa.com"));
        g.setSenha(Senha("A1#a1a1a"));
        g.setRamal(Ramal("1234"));
        checar(true, "Gerente construido com todos os dados validos");
    }
    catch (...)
    {
        checar(false, "Falha ao construir gerente completo");
    }
}

void TestsGerente::testarConstrucaoInvalida()
{
    try
    {
        Gerente g;
        g.setNome(Nome("Joao Silva"));
        g.setEmail(Email("joao@empresa.com"));
        g.setSenha(Senha("123")); // invalida
        g.setRamal(Ramal("1234"));
        checar(false, "Gerente construido com senha invalida");
    }
    catch (...)
    {
        checar(true, "Falha esperada ao construir gerente com dado invalido");
    }
}

void TestsGerente::testarGetters()
{
    Gerente g;
    Nome nome("Joao Silva");
    Email email("joao@empresa.com");
    Senha senha("A1#a1a1a");
    Ramal ramal("1234");

    g.setNome(nome);
    g.setEmail(email);
    g.setSenha(senha);
    g.setRamal(ramal);

    checar(g.getNome() == nome.getValor(), "Getter de nome funcionando");
    checar(g.getEmail() == email.getValor(), "Getter de email funcionando");
    checar(g.getSenha() == senha.getValor(), "Getter de senha funcionando");
    checar(g.getRamal() == ramal.getValor(), "Getter de ramal funcionando");
}