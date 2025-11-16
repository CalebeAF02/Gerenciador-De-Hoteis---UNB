#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Cartao.hpp"
#include "Endereco.hpp"

#include <string>
#include "../../../libs/io/IO.hpp"

using namespace std;

namespace Hotelaria {
    class Hospede : public Pessoa {
    private:
        Endereco endereco;
        Cartao cartao;

    public:
        // Construcutor -----------
        Hospede() : Pessoa(Nome(), Email()) {
        };

        Hospede(Nome nomePessoaObj, Email emailPessoaObj, Endereco endereco, Cartao cartao) : Pessoa(nomePessoaObj,
                emailPessoaObj), endereco(endereco), cartao(cartao) {
        };


        // seters -----------------
        void setNome(const Nome &newNome) {
            Pessoa::setPessoaNome(newNome);
        };

        void setEmail(const Email &newEmail) {
            Pessoa::setPessoaEmail(newEmail);
        };

        void setEndereco(const Endereco &newEndereco) {
            this->endereco = newEndereco;
        };

        void setCartao(const Cartao &newCartao) {
            this->cartao = newCartao;
        };

        // geters -----------------
        string getEndereco() const {
            return endereco.getValor();
        };

        string getCartao() const {
            return cartao.getValor();
        };
    };
}

#endif