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

    Hospede(Nome nome, Email email, Endereco endereco, Cartao cartao)
    {
        setNome(nome);
        setEmail(email);
        setEndereco(endereco);
        setCartao(cartao);

    };

    void setNome(const Nome& newNome)
    {
        Pessoa::setPessoaNome(newNome);
    };

    void setEmail(const Email& newEmail)
    {
        Pessoa::setPessoaEmail(newEmail);
    };

    void setEndereco(const Endereco& newEndereco)
    {
        this->endereco=newEndereco;
    };

    void setCartao(const Cartao& newCartao)
    {
        this->cartao=newCartao;
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