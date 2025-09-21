//
// Created by caleb on 21/09/2025.
//

#include "Reserva.h"

void Reserva::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_CHEGADA: {
            validarChegada(valor);
            break;
        };
        case TIPO_PARTIDA: {
            validarPartida(valor);
            break;
        };
        case TIPO_CODIGO: {
            validarCodigo(valor);
            break;
        };
    };
};
void Reserva::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_DINHEIRO: {
            ValidarDinheiro::validar(tipo);
        }
    }
};
void Reserva::validarChegada(string valor) {
    throw invalid_argument("Erro: Caracter não é caracterunico de ddi '+'");
}
void Reserva::validarPartida(string valor) {
    throw invalid_argument("Erro: Caracter não é caracterunico de ddi '+'");
}
void Reserva::validarCodigo(string valor) {
    throw invalid_argument("Erro: Caracter não é caracterunico de ddi '+'");
}