#ifndef PESSOA_INCLUDE
#define PESSOA_INCLUDE

#include "Nome.hpp"
#include "Email.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    class Pessoa {
    protected:
        Nome nome;
        Email email;

    public:
        Pessoa(Nome nomeObj, Email emailObj) : nome(nomeObj), email(emailObj) {
        };

        void setPessoaNome(const Nome &valor);

        void setPessoaEmail(const Email &valor);

        string getNome() const;

        string getEmail() const;
    };
}

#endif