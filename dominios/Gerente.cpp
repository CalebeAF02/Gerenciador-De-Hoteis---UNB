//
// Created by caleb on 10/09/2025.
//
#include <iostream>
#include "../dominios/Gerente.h"
#include "../validadores/ValidarRamal.h"

using namespace std;


void Gerente::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_RAMAL: {
            ValidarRamal::validar(valor);
            break;
        };
        case TIPO_SENHA: {
            validarSenha(valor);
            break;
        };
    };
};

void Gerente::validarRamal(int valor) {
    //throw invalid_argument("Ramal invalido");
}

void Gerente::validarSenha(int valor) {
    //throw invalid_argument("Senha invalido");
}
