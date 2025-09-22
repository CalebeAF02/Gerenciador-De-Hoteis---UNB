//
// Created by caleb on 21/09/2025.
//

#include "Reserva.h"

void Reserva::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_CODIGO: {
            ValidarCodigo::validar(valor);
            break;
        };
    };
};

void Reserva::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_DINHEIRO: {
            ValidarDinheiro::validar(valor);
        }
    }
};