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
    void setNome(const Nome& nome);

    void setEmail(const Email& email);

    string getNome() const;

    string getEmail() const;
};
#endif;