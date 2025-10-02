#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Entidades/Pessoa.h"
#include "validadoresAbstratos/ValidarEndereco.h"
#include "../validadoresPrincipais/ValidarString.h"

#include <iostream>
#include <string>

#include <stdexcept>

#include "Dominios/Cartao.h"
#include "Dominios/Endereco.h"

using namespace std;

class Hospede : public Pessoa, public ValidarEndereco
{
private:
    Endereco endereco;
    Cartao cartao;

public:
    Hospede() = default;

    Hospede(Nome nome, Email email)
    {
        setNome(nome);
        setEmail(email);
    };

    void setNome(const Nome& valor)
    {
        Pessoa::setNome(valor);
    };

    void setEmail(const Email& valor)
    {
        Pessoa::setEmail(valor);
    };

    void setEndereco(const string valor)
    {
        endereco.setValor(valor);
    };

    void setCartao(string valor)
    {
        endereco.setValor(valor);
    };

    //Get
    string getEndereco() const
    {
        return endereco.getValor();
    };

    string getCartao() const
    {
        return cartao.getValor();
    };
};
#endif