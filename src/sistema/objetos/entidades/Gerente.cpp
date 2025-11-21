#include "Gerente.hpp"

namespace Hotelaria {
    void Gerente::setNome(const Nome &newNome) {
        Pessoa::setPessoaNome(newNome);
    }

    void Gerente::setEmail(const Email &newEmail) {
        Pessoa::setPessoaEmail(newEmail);
    }

    void Gerente::setRamal(const Ramal &newRamal) {
        this->ramal = newRamal;
    }

    void Gerente::setSenha(const Senha &newSenha) {
        this->senha = newSenha;
    }

    string Gerente::getRamal() const {
        return ramal.getValor();
    }

    string Gerente::getSenha() const {
        return senha.getValor();
    }
}