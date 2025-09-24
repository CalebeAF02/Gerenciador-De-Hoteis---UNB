//
// Created by caleb on 10/09/2025.
//

#include "../dominios/Hospede.h"

void Hospede::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_ENDERECO:
            ValidarEndereco::validar(valor);
            break;
        case TIPO_CARTAO:
            validarCartao(valor);
            break;
    }
}

void Hospede::validarCartao(string valor) {
    if (valor.length() < 0 || valor.length() > 16) {
        throw invalid_argument("Erro: Tamanho invalido");
    } // implementar algoritimo de lunn
}
