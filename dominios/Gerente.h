//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_GERENTE_H
#define CODIGOS_CLION_TP1_IML_GERENTE_H

#include "../dominios/Pessoa.h"
#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarInt.h"
#include "../validadores/ValidarString.h"

#include <iostream>
#include <string>
#include "stdexcept"

using namespace std;

class Gerente : public Pessoa, public ValidarInt, public ValidarString, public ValidarRamal, public exception {
private:
    int ramal;
    string senha;

public:
    static int const TIPO_RAMAL = 1;
    static int const TIPO_SENHA = 2;

    void validar(int tipo, int valor) override;

    void validarRamal(int ramal);

    void validar(int tipo, string valor) override;

    void validarSenha(string senha);


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

    // Regras específicas de validação do gerente
};

inline int Gerente::getRamal() {
    return ramal;
};

inline string Gerente::getSenha() {
    return senha;
};

#endif //CODIGOS_CLION_TP1_IML_GERENTE_H