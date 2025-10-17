#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Pessoa.h"

#include "Nome.h"
#include "Email.h"
#include "Cartao.h"
#include "Endereco.h"

#include <string>

#include "LinhaTSV.h"

using namespace std;

class Hospede : public Pessoa, public LinhaTSV
{
private:
    Endereco endereco;
    Cartao cartao;

public:
    // Construcutor -----------
    Hospede() = default;

    Hospede(Nome nome, Email email, Endereco endereco, Cartao cartao)
    {
        setNome(nome);
        setEmail(email);
        setEndereco(endereco);
        setCartao(cartao);
    };

    // virtuais ----------------
    void exibirInfo() const override
    {
        cout << "Sou um Gerente\n";
    };

    // seters -----------------
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
        this->endereco = newEndereco;
    };

    void setCartao(const Cartao& newCartao)
    {
        this->cartao = newCartao;
    };

    void setTSV(string dados); // Altera o setTSV do linhaTSV

    // geters -----------------
    string getEndereco() const
    {
        return endereco.getValor();
    };

    string getCartao() const
    {
        return cartao.getValor();
    };

    string getTSV(); // Altera o getTSV do linhaTSV
};

inline string Hospede::getTSV() // Transforma Gerente em uma linha de texto
{
    return string("HOSPEDE") + "\t" + getNome() + "\t" + getEmail() + "\t" + getEndereco() + "\t" + getCartao();
}

#endif
