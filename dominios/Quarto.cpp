//
// Created by caleb on 10/09/2025.
//
#include <iostream>
#include "../dominios/Quarto.h"

using namespace std;

void Quarto::validar(int tipo, int valor) {
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
        }
        case TIPO_RAMAL: {
            ValidarRamal::validar(valor);
            break;
        };
    };
};

void Quarto::validarNumero(int valor) {
    if (valor < 1 || valor > 999) {
        throw invalid_argument("Erro: Formato de Numero invalido! Digite um valor entre 001 e 999");
    } else {
        //cou << "Numero: Valido! " << endl;
    }
};

void Quarto::validarCapacidade(int valor) {
    if (valor < 1 || valor > 4) {
        throw invalid_argument("Erro: Capacidade invalida! Digite um valor entre 1 e 4");
    } else {
        //cou << "Senha: Valida! " << endl;
    }
};

void Quarto::validarDiaria(int valor) {
    if (valor == 800) {
        // tipo 1 de quarto
    } else if (valor == 1200) {
        // tipo 2 de quarto
    } else {
        throw invalid_argument("Erro: Valor invalido! Digite o valor R$ 800 ou R$ 1200 !");
    }
};
