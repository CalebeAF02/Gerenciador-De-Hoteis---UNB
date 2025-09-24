//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_GERENTE_H
#define CODIGOS_CLION_TP1_IML_GERENTE_H

#include "../dominios/Pessoa.h"
#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarInt.h"

#include <string>

using namespace std;

class Gerente : public Pessoa, public ValidarInt, public ValidarRamal {
private:
    int ramal;
    string senha;

public:
    static int const TIPO_RAMAL = 3;
    static int const TIPO_SENHA = 4;

    void validar(int tipo, int valor) override;

    void validarRamal(int ramal);

    void validar(int tipo, string valor) override;

    void validarSenha(string senha);


    void setNome(string nome) {
        validar(TIPO_NOME, nome);
        this->nome = nome;
    }

    void setEmail(string email) {
        validar(TIPO_EMAIL, email);
        this->email = email;
    }

    void setRamal(int ramal) {
        validar(TIPO_RAMAL, ramal);
        this->ramal = ramal;
    }

    void setSenha(string senha) {
        validar(TIPO_SENHA, senha);
        this->senha = senha;
    }

    //Get
    int getRamal();

    string getSenha();
};

inline int Gerente::getRamal() {
    return ramal;
};

inline string Gerente::getSenha() {
    return senha;
};

#endif //CODIGOS_CLION_TP1_IML_GERENTE_H