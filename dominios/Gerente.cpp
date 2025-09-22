//
// Created by caleb on 10/09/2025.
//
#include <iostream>
#include "../dominios/Gerente.h"

void Gerente::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_RAMAL: {
            ValidarRamal::validar(valor);
            break;
        };
    };
};

void Gerente::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_SENHA: {
            validarSenha(valor);
            break;
        };
    };
};

void Gerente::validarRamal(int valor) {
    if (valor < 0 || valor > 50) {
        throw invalid_argument("Erro: Formato de Ramal invalido! Digite um valor entre 00 e 50");
    } else {
        //cou << "Senha: Valida! " << endl;
    }
}

void Gerente::validarSenha(string senha) {
    // Deve ser editado ainda

    int senhaTamanho = senha.length();
    if (senhaTamanho < 5 || senhaTamanho > 20) {
        throw invalid_argument("Erro: Senha com tamanho invalido");
    }

    bool primeiraLetraCaixaAlta = true;
    int contEspaco = 0;

    for (int i = 0; i < senhaTamanho; i++) {
        if (senha[i] == ' ') {
            primeiraLetraCaixaAlta = true;
            contEspaco++;
            if (contEspaco > 1) {
                throw invalid_argument("Erro: Espaco em branco seguido por outro espaco");
            }
        } else if (isalpha(senha[i])) {
            contEspaco = 0;
            if (primeiraLetraCaixaAlta && !isupper(senha[i])) {
                throw invalid_argument("Erro: Primeira letra de cada termo deve ser maiuscula");
            }
            primeiraLetraCaixaAlta = false;
        } else {
            throw invalid_argument("Erro: Senha com caracter invalido");
        }
    }
    if (senha[senhaTamanho - 1] == ' ') {
        throw invalid_argument("Erro: Senha nao pode terminar com espaco");
    }
};