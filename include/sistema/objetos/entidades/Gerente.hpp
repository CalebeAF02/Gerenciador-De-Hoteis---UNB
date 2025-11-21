#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Ramal.hpp"
#include "Senha.hpp"
#include "GerenteDTO.hpp"
#include "IO.hpp"

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
                emailPessoaObj), ramal(ramal), senha(senha) {
        };

        Gerente(GerenteDTO &gerente_dto) : Pessoa(Nome(gerente_dto.getNome()), Email(gerente_dto.getEmail())) {
            setRamal(Ramal(gerente_dto.getRamal()));
        };

        void setNome(const Nome &newNome);

        void setEmail(const Email &newEmail);

        void setRamal(const Ramal &newRamal);

        void setSenha(const Senha &newSenha);

        // geters -----------------
        string getRamal() const;

        string getSenha() const;
    };
}

#endif