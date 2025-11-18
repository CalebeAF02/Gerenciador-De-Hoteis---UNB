//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_PESSOADTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_PESSOADTO_HPP


#include <string>

using namespace std;
namespace Hotelaria {
    class PessoaDTO {
    private:
        int pessoaId;
        string nome;
        string email;

    public:
        PessoaDTO() = default;

        PessoaDTO(int pessoaId, string nome, string email) : pessoaId(pessoaId), nome(nome), email(email) {};

        int getPessoaId() const {
            return pessoaId;
        }

        void setPessoaId(int valor) {
            this->pessoaId = valor;
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
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_PESSOADTO_HPP