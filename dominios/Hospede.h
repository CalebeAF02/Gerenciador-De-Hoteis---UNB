//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_HOSPEDE_H
#define CODIGOS_CLION_TP1_IML_HOSPEDE_H


#include "../dominios/Pessoa.h"
#include "../validadores/ValidarEndereco.h"
#include "../validadores/ValidarString.h"

#include <iostream>
#include <string>

#include <stdexcept>

using namespace std;

class Hospede : public Pessoa, ValidarString, ValidarEndereco, exception {
private:
    string endereco;
    string cartao;

public:
    static int const TIPO_ENDERECO = 1;
    static int const TIPO_CARTAO = 2;

    // Regras específicas de validação do hóspede
    void validar(int tipo, string valor) override;

    void validarCartao(string cartao);

    void setEndereco(string endereco) {
        validar(TIPO_ENDERECO, endereco);
        this->endereco = endereco;
    };

    void setCartao(string cartao) {
        validar(TIPO_CARTAO, cartao);
        this->cartao = cartao;
    };

    //Get
    string getEndereco();

    string getCartao();
};

inline string Hospede::getEndereco() {
    return endereco;
};

inline string Hospede::getCartao() {
    return cartao;
};
#endif //CODIGOS_CLION_TP1_IML_HOSPEDE_H
