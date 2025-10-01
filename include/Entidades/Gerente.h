#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.h"
#include "validadoresPrincipais/ValidarString.h"
#include "../validadoresAbstratos/ValidarRamal.h"
#include "../coisas/utilitarios/LinhaTSV.h"

#include "Dominios/Email.h"
#include "Dominios/Nome.h"

#include <string>

using namespace std;

class Gerente : public Pessoa, public ValidarString, public ValidarRamal, public LinhaTSV
{
private:
    string ramal;
    string senha;

public:
    Gerente();

    Gerente(Nome nome, Email email);
    static int const TIPO_RAMAL = 1;
    static int const TIPO_SENHA = 2;


    void validar(int tipo, string valor) override;

    void validarSenha(string senha);


    void setNome(const Nome& nome)
    {
        Pessoa::setNome(nome);
    }

    void setEmail(const Email& email)
    {
        Pessoa::setEmail(email);
    }

    void setRamal(const string ramal)
    {
        validar(TIPO_RAMAL, ramal);
        this->ramal = ramal;
    }

    void setSenha(const string senha)
    {
        validar(TIPO_SENHA, senha);
        this->senha = senha;
    }

    //Get
    string getRamal() const
    {
        return ramal;
    };

    string getSenha() const
    {
        return senha;
    };

    string getTSV() override;
    void setTSV(string dados) override;
};
#endif