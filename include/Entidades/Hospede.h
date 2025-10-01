#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Entidades/Pessoa.h"
#include "../validadoresAbstratos/ValidarNome.h"
#include "../validadoresAbstratos/ValidarEndereco.h"
#include "../validadoresPrincipais/ValidarString.h"

#include <iostream>
#include <string>

#include <stdexcept>

using namespace std;

class Hospede : public Pessoa, public ValidarString
{
private:
    string endereco;
    string cartao;

public:
    static int const TIPO_ENDERECO = 1;
    static int const TIPO_CARTAO = 2;

    // Regras específicas de validação do hóspede
    void validar(int tipo, string valor) override;

    void validarCartao(string cartao);

    void setNome(const string nome)
    {
        Pessoa::validar(TIPO_NOME, nome);
        this->nome = nome;
    };

    void setEmail(const string email)
    {
        Pessoa::validar(TIPO_EMAIL, email);
        this->email = email;
    };

    void setEndereco(const string endereco)
    {
        validar(TIPO_ENDERECO, endereco);
        this->endereco = endereco;
    };

    void setCartao(string cartao)
    {
        validar(TIPO_CARTAO, cartao);
        this->cartao = cartao;
    };

    //Get
    string getEndereco();

    string getCartao();
};

inline string Hospede::getEndereco()
{
    return endereco;
};

inline string Hospede::getCartao()
{
    return cartao;
};
#endif