//
// Created by caleb on 21/09/2025.
//

#include "../d_cabecalho/Reserva.h"

void Reserva::validar(int tipo, const string valor) {
    switch (tipo) {
        case TIPO_CODIGO: {
            ValidarCodigo::validar(valor);
            break;
        };
    };
};

void Reserva::validar(int tipo, const int valor) {
    switch (tipo) {
        case TIPO_DINHEIRO: {
            ValidarDinheiro::validar(valor);
        }
    }
};