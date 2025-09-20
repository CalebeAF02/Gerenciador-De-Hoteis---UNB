#ifndef CODIGOS_CLION_TP1_PESSOA_H
#define CODIGOS_CLION_TP1_PESSOA_H

#include <string>
#include <stdexcept>
#include "../validadores/ValidarString.h"
#include "../validadores/ValidarNome.h"

using namespace std;

class Pessoa : public ValidarString,ValidarNome, exception {
private:
    //Atributos
    string nome;
    string email;

public:
    //Switch para validar
    static int const TIPO_NOME = 1;
    static int const TIPO_EMAIL = 2;


    //Entra Com os valores e tenta validalos
    void setNome(string nome) {
        validar(TIPO_NOME, nome);
        this->nome = nome;
    };

    void setEmail(string email) {
        validar(TIPO_EMAIL, email);
        this->email = email;
    };

    // Atribui aos Atributos o valor
    string getNome();

    string getEmail();


    // Implementação do método abstrato
    void validar(int tipo, string valor) override;
    void validarEmail(string email);

};

//Inline Atribui em tempo de execucao o valor aos atributos
inline string Pessoa::getNome() {
    return nome;
};

inline string Pessoa::getEmail() {
    return email;
};

#endif //CODIGOS_CLION_TP1_PESSOA_H
