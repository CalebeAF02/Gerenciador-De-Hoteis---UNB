#include "Hospede.hpp"

namespace Hotelaria {
    void Hospede::setNome(const Nome &newNome) {
        Pessoa::setPessoaNome(newNome);
    };

    void Hospede::setEmail(const Email &newEmail) {
        Pessoa::setPessoaEmail(newEmail);
    };

    void Hospede::setEndereco(const Endereco &newEndereco) {
        this->endereco = newEndereco;
    };

    void Hospede::setCartao(const Cartao &newCartao) {
        this->cartao = newCartao;
    };

    string Hospede::getEndereco() const {
        return endereco.getValor();
    };

    string Hospede::getCartao() const {
        return cartao.getValor();
    };
}