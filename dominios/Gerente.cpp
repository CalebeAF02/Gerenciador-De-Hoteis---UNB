//
// Created by caleb on 10/09/2025.
//
#include <iostream>
#include <string>
#include "../dominios/Pessoa.h"
#include "../dominios/Gerente.h"
#include "../validadores/ValidarNome.h"
#include "../validadores/ValidarRamal.h"

using namespace std;

Gerente::Gerente() {
    // Inicialize atributos se necessário
}
void Gerente::validarInt(int tipo, int valor) {
    switch (tipo) {
        case TIPO_RAMAL: {
            ValidarRamal::validarRamal(valor);
            break;
        };
        case TIPO_SENHA: {
            validarSenha(valor);
            break;
        };
    };
};

void Gerente::validarRamal(int valor) {
    throw invalid_argument("Ramal invalido");
}

void Gerente::validarSenha(int valor) {
    throw invalid_argument("Senha invalido");
}
