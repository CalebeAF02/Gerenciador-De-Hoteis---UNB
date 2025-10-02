#ifndef PESSOA_INCLUDE
#define PESSOA_INCLUDE

#include "../Dominios/Nome.h"
#include "../Dominios/Email.h"

#include <sstream>
#include <string>

using namespace std;

class Pessoa
{
protected:
    Nome nome;
    Email email;

public:
    // Construcutor ----------
    Pessoa() : nome(Nome()), email(Email())
    {
    };

    // seters ----------------
    void setNome(const Nome& valor)
    {
        this->nome = valor;
    };

    void setEmail(const Email& valor)
    {
        this->email = valor;
    };

    // geters ----------------
    string getNome() const;

    string getEmail() const;
};

inline string Pessoa::getNome() const
{
    return nome.getValor();
}

inline string Pessoa::getEmail() const
{
    return email.getValor();
}
#endif