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
    if (valor <0 || valor > 50) {
        throw invalid_argument("Erro: Formato de Ramal invalido! Digite um valor entre 00 e 50");
    }else {
        //cou << "Senha: Valida! " << endl;
    }
}

void Gerente::validarSenha(string valor) {
    throw invalid_argument("Erro: Formato de Senha invalido! Digite um valor entre 00 e 50");
}
