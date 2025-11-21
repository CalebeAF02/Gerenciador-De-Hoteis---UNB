#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Ramal.hpp"
#include "Senha.hpp"
#include "GerenteDTO.hpp"
#include "../../../libs/io/IO.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    class Gerente : public Pessoa {
    private:
        Ramal ramal;
        Senha senha;

    public:
        Gerente() : Pessoa(Nome(), Email()) {
        };

        Gerente(Nome nomePessoaObj, Email emailPessoaObj, Ramal ramal, Senha senha) : Pessoa(nomePessoaObj,
                emailPessoaObj),
            ramal(ramal), senha(senha) {
        };

        Gerente(GerenteDTO &gerente_dto) : Pessoa(Nome(gerente_dto.getNome()), Email(gerente_dto.getEmail())) {
            setRamal(Ramal(gerente_dto.getRamal()));
        };

        void setNome(const Nome &newNome) {
            Pessoa::setPessoaNome(newNome);
        }

        void setEmail(const Email &newEmail) {
            Pessoa::setPessoaEmail(newEmail);
        }

        void setRamal(const Ramal &newRamal) {
            this->ramal = newRamal;
        }

        void setSenha(const Senha &newSenha) {
            this->senha = newSenha;
        }

        // geters -----------------
        string getRamal() const;

        string getSenha() const;
    };

    inline string Gerente::getRamal() const {
        return ramal.getValor();
    }

    inline string Gerente::getSenha() const {
        return senha.getValor();
    }
}

#endif