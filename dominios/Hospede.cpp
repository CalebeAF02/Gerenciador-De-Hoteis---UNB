//
// Created by caleb on 10/09/2025.
//

#include "../dominios/Hospede.h"
#include "../validadores/ValidarNome.h"
#include "../validadores/ValidarEndereco.h"

void Hospede::validarInt(int tipo, int valor) {
    switch (tipo) {
        case TIPO_CARTAO:
            ValidarInt::validar(valor);
            break;
        default:
            throw invalid_argument("Tipo inválido para validação de inteiro.");
    }
}

void Hospede::validarString(int tipo, string valor) {
    switch (tipo) {
        case TIPO_NOME:
            ValidarNome::validar(valor);
            break;
        case TIPO_ENDERECO:
            ValidarEndereco::validar(valor);
            break;
        case TIPO_CARTAO:
            validarCartao(valor);
            break;
        default:
            throw invalid_argument("Tipo inválido para validação de string.");
    }
}
void Hospede::validarCartao(string valor) {
    throw invalid_argument("Cartao invalido");
}