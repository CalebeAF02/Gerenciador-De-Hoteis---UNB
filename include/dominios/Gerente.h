#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.h"
#include "../validadoresAbstratos/ValidarRamal.h"
#include "../coisas/utilitarios/LinhaTSV.h"

#include <string>

using namespace std;

class Gerente : public Pessoa, public ValidarRamal, public LinhaTSV
{
private:
    string ramal;
    string senha;

public:
    static int const TIPO_RAMAL = 3;
    static int const TIPO_SENHA = 4;


    void validar(int tipo, string valor) override;

    void validarSenha(string senha);


    void setNome(const string nome)
    {
        Pessoa::validar(TIPO_NOME, nome);
        this->nome = nome;
    }

    void setEmail(const string email)
    {
        Pessoa::validar(TIPO_EMAIL, email);
        this->email = email;
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
    string getRamal();

    string getSenha();

    string getTSV() override;
    void setTSV(string dados) override;
};

inline string Gerente::getRamal()
{
    return ramal;
};

inline string Gerente::getSenha()
{
    return senha;
};
#endif
