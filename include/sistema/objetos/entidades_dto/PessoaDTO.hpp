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

        PessoaDTO(int pessoaId, string nome, string email) : pessoaId(pessoaId), nome(nome), email(email) {
        };

        int getPessoaId() const;

        void setPessoaId(int valor);

        string getNome() const;

        void setNome(const string &valor);

        string getEmail() const;

        void setEmail(const string &valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_PESSOADTO_HPP