#pragma once

#include "validadoresPrincipais/ValidarString.h"
#include "validadoresAbstratos/ValidarNome.h"
#include "validadoresAbstratos/ValidarEmail.h"

#include <sstream>
#include <string>

using namespace std;

class Pessoa : public ValidarString {
protected:
    //Atributos
    string nome;
    string email;

public:
    //Switch para validar
    static int const TIPO_NOME = 1;
    static int const TIPO_EMAIL = 2;


    // Implementação do método abstrato
    void validar(int tipo, string valor) override;

    //Entra Com os valores e tenta validalos
    void setNome(const string nome) {
        validar(TIPO_NOME, nome);
        this->nome = nome;
    };

    void setEmail(const string email) {
        validar(TIPO_EMAIL, email);
        this->email = email;
    };

    // Atribui aos Atributos o valor
    string getNome();

    string getEmail();
};

//Inline Atribui em tempo de execucao o valor aos atributos
inline string Pessoa::getNome() {
    return nome;
};

inline string Pessoa::getEmail() {
    return email;
};