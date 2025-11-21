//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP

#include <string>

using namespace std;

namespace Hotelaria {
    class HospedeDTO {
    private:
        int id_hospede;
        string nome;
        string email;
        string endereco;
        string cartao;

    public:
        HospedeDTO() = default;

        HospedeDTO(int id_hospede, string nome, string email, string endereco, string cartao) : id_hospede(id_hospede),
            nome(nome), email(email), endereco(endereco), cartao(cartao) {
        };

        int getId() const {
            return id_hospede;
        }

        void setId(int valor) {
            this->id_hospede = valor;
        }

        string getNome() const {
            return nome;
        }

        void setNome(const string &valor) {
            this->nome = valor;
        }

        string getEmail() const {
            return email;
        }

        void setEmail(const string &valor) {
            this->email = valor;
        }

        string getEndereco() const {
            return endereco;
        }

        void setEndereco(const string &valor) {
            this->endereco = valor;
        }

        string getCartao() const {
            return cartao;
        }

        void setCartao(const string &valor) {
            this->cartao = valor;
        }
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP