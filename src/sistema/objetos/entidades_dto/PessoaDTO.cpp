//
// Created by caleb on 18/11/2025.
//

#include "PessoaDTO.hpp"

namespace Hotelaria {
    int PessoaDTO::getPessoaId() const {
        return pessoaId;
    }

    void PessoaDTO::setPessoaId(int valor) {
        this->pessoaId = valor;
    }

    string PessoaDTO::getNome() const {
        return nome;
    }

    void PessoaDTO::setNome(const string &valor) {
        this->nome = valor;
    }

    string PessoaDTO::getEmail() const {
        return email;
    }

    void PessoaDTO::setEmail(const string &valor) {
        this->email = valor;
    }
}