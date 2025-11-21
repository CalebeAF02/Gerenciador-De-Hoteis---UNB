#include "Pessoa.hpp"

namespace Hotelaria {
    void Pessoa::setPessoaNome(const Nome &valor) {
        this->nome = valor;
    };

    void Pessoa::setPessoaEmail(const Email &valor) {
        this->email = valor;
    };

    string Pessoa::getNome() const {
        return nome.getValor();
    }

    string Pessoa::getEmail() const {
        return email.getValor();
    }
}