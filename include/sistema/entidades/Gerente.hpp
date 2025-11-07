#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Ramal.hpp"
#include "Senha.hpp"

#include <string>

using namespace std;

class Gerente : public Pessoa {
private:
    Ramal ramal;
    Senha senha;

public:
    // Construcutor -----------
    Gerente() : Pessoa(Nome(), Email()) {
    };

    Gerente(Nome nomePessoaObj, Email emailPessoaObj, Ramal ramal, Senha senha) : Pessoa(nomePessoaObj, emailPessoaObj),
        ramal(ramal), senha(senha) {
    };

    // virtuais ----------------
    void exibirInfo() const override {
        cout << "Sou um Gerente\n";
    };

    // seters -----------------
    void setNome(const Nome &newNome) {
        Pessoa::setPessoaNome(newNome);
    }

    void setEmail(const Email &newEmail) {
        Pessoa::setPessoaEmail(newEmail);
    }

    void setRamal(const Ramal &newRamal) {
        this->ramal = newRamal;
    }

    void setSenha(const Senha &newSenha) {
        this->senha = newSenha;
    }

    // geters -----------------
    string getRamal() const;

    string getSenha() const;
};

inline string Gerente::getRamal() const {
    return ramal.getValor();
}

inline string Gerente::getSenha() const {
    return senha.getValor();
}

#endif