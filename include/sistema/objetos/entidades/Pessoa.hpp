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
        // Construcutor ----------
        Pessoa(Nome nomeObj, Email emailObj) : nome(nomeObj), email(emailObj) {
        };

        // Virtuais --------------
        virtual void exibirInfo() const = 0;

        virtual ~Pessoa() = default;

        // seters ----------------
        void setPessoaNome(const Nome &valor) {
            this->nome = valor;
        };

        void setPessoaEmail(const Email &valor) {
            this->email = valor;
        };

        // geters ----------------
        string getNome() const;

        string getEmail() const;
    };

    inline string Pessoa::getNome() const {
        return nome.getValor();
    }

    inline string Pessoa::getEmail() const {
        return email.getValor();
    }
}

#endif