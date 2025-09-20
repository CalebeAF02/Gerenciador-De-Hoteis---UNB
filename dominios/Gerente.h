//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_GERENTE_H
#define CODIGOS_CLION_TP1_IML_GERENTE_H

#include "../dominios/Pessoa.h"

#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarInt.h"

#include<string>
#include<stdexcept>
using namespace std;

class Gerente : public Pessoa, ValidarInt, ValidarNome, ValidarRamal, exception {
private:
    string nome;
    string ramal;
    string senha;

public:
    static int const TIPO_RAMAL = 1;
    static int const TIPO_SENHA = 2;

    void validarInt(int tipo, string valor) override;
    void validarString(int tipo, int valor) override;
    void validarRamal(int ramal);
    void validarSenha(int senha);

    Gerente();

    void setNome(string nome) {
        validar(TIPO_NOME, nome);
        this->nome = nome;
    }
    void setRamal(string ramal) {
        validar(TIPO_RAMAL, ramal);
        this->ramal = ramal;
    }
    void setSenha(string senha) {
        validar(TIPO_SENHA, senha);
        this->senha = senha;
    }

    //Get
    string getNome();
    string getRamal();
    string getSenha();

    // Regras específicas de validação do gerente

};
inline string Gerente::getRamal() {
    return ramal;
};
inline string Gerente::getSenha() {
    return senha;
};

#endif //CODIGOS_CLION_TP1_IML_GERENTE_H
