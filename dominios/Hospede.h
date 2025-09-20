//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_HOSPEDE_H
#define CODIGOS_CLION_TP1_IML_HOSPEDE_H


#include "../dominios/Pessoa.h"
#include "../validadores/ValidarEndereco.h"
#include "../validadores/ValidarNome.h"
#include "../validadores/ValidarInt.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Hospede : public Pessoa, ValidarInt, ValidarNome, ValidarEndereco, exception {
private:
    string nome;
    string endereco;
    string cartao;

public:
    static int const TIPO_NOME = 1;
    static int const TIPO_ENDERECO = 2;
    static int const TIPO_CARTAO = 3;

    // Regras específicas de validação do hóspede
    void valida(int tipo, int valor) override;
    void validar(int tipo, string valor) override;
    void validarCartao(string telefone);

    Hospede();


    void setNome(string nome) {
        validar(TIPO_NOME, nome);
        this->nome = nome;
    };
    void setEndereco(string endereco) {
        validar(TIPO_ENDERECO, endereco);
        this->endereco = endereco;
    };
    void setCartao(string cartao) {
        validar(TIPO_CARTAO, cartao);
        this->cartao = cartao;
    };

    //Get
    string getNome();
    string getEndereco();
    string getCartao();


};
inline string Hospede::getEndereco() {
    return endereco;
};
inline string Hospede::getCartao() {
    return cartao;
};

inline string Hospede::getNome() {
    return nome;
};
#endif //CODIGOS_CLION_TP1_IML_HOSPEDE_H
