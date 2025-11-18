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
        int hospedeId;
        string nome;
        string email;
        string endereco;
        string cartao;

    public:
        HospedeDTO() = default;

        HospedeDTO(int hospedeId, string nome, string email, string endereco, string cartao) : hospedeId(hospedeId), nome(nome), email(email), endereco(endereco), cartao(cartao) {
        };

        int getId() const {
            return hospedeId;
        }

        void setId(int valor) {
            this->hospedeId = valor;
        }

        string getNome() const {
            return nome;
        }

        void setNome(const string &valor) {
            this->nome = nome;
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
            return endereco;
        }

        void setCartao(const string &valor) {
            this->endereco = valor;
        }
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP