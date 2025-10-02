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

    Gerente(Nome nome, Email email)
    {
        setNome(nome);
        setEmail(email);
    };

    // seters -----------------
    void setNome(const Nome& valor)
    {
        Pessoa::setNome(valor);
    }

    void setEmail(const Email& valor)
    {
        Pessoa::setEmail(valor);
    }

    void setRamal(const string valor)
    {
        ramal.setValor(valor);
    }

    void setSenha(const string valor)
    {
        senha.setValor(valor);
    }

    void setTSV(string dados) override;

    // geters -----------------
    string getRamal() const;

    string getSenha() const;

    string getTSV() override;
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