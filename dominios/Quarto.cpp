//
// Created by caleb on 10/09/2025.
//
#include <iostream>
#include "../dominios/Quarto.h"
#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarInt.h"

using namespace std;

Quarto::Quarto() {

};
void Quarto::validar(int tipo, int valor){
    switch (tipo) {
        case TIPO_NUMERO: {
            validarNumero(valor);
            break;
        };
        case TIPO_CAPACIDADE: {
            validarCapacidade(valor);
            break;
        };
        case TIPO_DIARIA: {
            validarDiaria(valor);
            break;
        };
        case TIPO_RAMAL: {
            ValidarRamal::validarRamal(valor);
            break;
        };
    };
};

void Quarto::validarNumero(int valor) {
    throw invalid_argument("Numero invalido");
};

void Quarto::validarCapacidade(int valor) {
    throw invalid_argument("Capacidade invalido");
};

void Quarto::validarDiaria(double valor) {
    throw invalid_argument("Diaria invalido");
};
