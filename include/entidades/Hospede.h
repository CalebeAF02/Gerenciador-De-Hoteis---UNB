#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Pessoa.h"

#include "Nome.h"
#include "Email.h"
#include "Cartao.h"
#include "Endereco.h"

#include <string>

using namespace std;

class Hospede : public Pessoa
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