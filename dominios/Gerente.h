//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_GERENTE_H
#define CODIGOS_CLION_TP1_IML_GERENTE_H

#include "../dominios/Pessoa.h"
#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarInt.h"

#include "stdexcept"

using namespace std;

class Gerente : public Pessoa, ValidarInt, ValidarRamal, exception {
private:
    int ramal;
    int senha;

public:
    static int const TIPO_RAMAL = 1;
    static int const TIPO_SENHA = 2;

    void validar(int tipo, int valor) override;
    void validarRamal(int ramal);
    void validarSenha(int senha);


    void setRamal(int ramal) {
        validar(TIPO_RAMAL, ramal);
        this->ramal = ramal;
    }
    void setSenha(int senha) {
        validar(TIPO_SENHA, senha);
        this->senha = senha;
    }

    //Get
    int getRamal();
    int getSenha();

    // Regras específicas de validação do gerente

};
inline int Gerente::getRamal() {
    return ramal;
};
inline int Gerente::getSenha() {
    return senha;
};

#endif //CODIGOS_CLION_TP1_IML_GERENTE_H
