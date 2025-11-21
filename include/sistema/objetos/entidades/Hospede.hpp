#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Cartao.hpp"
#include "Endereco.hpp"

#include "HospedeDTO.hpp"
#include <string>
#include "IO.hpp"

using namespace std;

namespace Hotelaria {
    class Hospede : public Pessoa {
    private:
        Endereco endereco;
        Cartao cartao;

    public:
        Hospede() : Pessoa(Nome(), Email()) {
        };

        Hospede(Nome nomePessoaObj, Email emailPessoaObj, Endereco endereco, Cartao cartao) : Pessoa(nomePessoaObj,
                emailPessoaObj), endereco(endereco), cartao(cartao) {
        };

        Hospede(HospedeDTO &hospede_dto) : Pessoa(Nome(hospede_dto.getNome()), Email(hospede_dto.getEmail())) {
            setEndereco(Endereco(hospede_dto.getEndereco()));
        };

        void setNome(const Nome &newNome);

        void setEmail(const Email &newEmail);

        void setEndereco(const Endereco &newEndereco);

        void setCartao(const Cartao &newCartao);

        string getEndereco() const;

        string getCartao() const;
    };
}

#endif