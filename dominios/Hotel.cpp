//
// Created by caleb on 10/09/2025.
//

#include "../dominios/Hotel.h"
#include "../validadores/ValidarEndereco.h"
#include "../validadores/ValidarNome.h"


void Hotel::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_NOME: {
            ValidarNome::validar(valor);
            break;
        };
        case TIPO_ENDERECO: {
            ValidarEndereco::validar(valor);
            break;
        };
        case TIPO_TELEFONE: {
            validarTelefone(valor);
            break;
        };
    };
};

void Hotel::validarTelefone(string valor) {
    throw invalid_argument("Telefone invalido");
}