#include "dominios/Reserva.h"

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