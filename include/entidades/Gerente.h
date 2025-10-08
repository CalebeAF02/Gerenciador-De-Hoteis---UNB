#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.h"

#include "Nome.h"
#include "Email.h"
#include "Ramal.h"
#include "Senha.h"

#include "LinhaTSV.h"

#include <string>

using namespace std;

class Gerente : public Pessoa, public LinhaTSV
{
private:
    Ramal ramal;
    Senha senha;

public:
    // Construcutor -----------
    Gerente() = default;

    Gerente(Nome nome, Email email, Ramal ramal, Senha senha)
    {
        setNome(nome);
        setEmail(email);
        setRamal(ramal);
        setSenha(senha);
    };

    // seters -----------------
    void setNome(const Nome& newNome)
    {
        Pessoa::setPessoaNome(newNome);
    }

    void setEmail(const Email& newEmail)
    {
        Pessoa::setPessoaEmail(newEmail);
    }

    void setRamal(const Ramal& newRamal)
    {
        this->ramal=newRamal;
    }

    void setSenha(const Senha& newSenha)
    {
        this->senha=newSenha;
    }

    void setTSV(string dados) override;// Altera o setTSV do linhaTSV

    // geters -----------------
    string getRamal() const;

    string getSenha() const;

    string getTSV() override;// Altera o getTSV do linhaTSV
};

inline string Gerente::getTSV() // Transforma Gerente em uma linha de texto
{
    return string("GERENTE") + "\t" + getNome() + "\t" + getEmail() + "\t" + getRamal() + "\t" + getSenha();
}

inline string Gerente::getRamal() const
{
    return ramal.getValor();
}

inline string Gerente::getSenha() const
{
    return senha.getValor();
}
#endif