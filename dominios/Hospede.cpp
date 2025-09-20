//
// Created by caleb on 10/09/2025.
//

#include "../dominios/Hospede.h"
#include "../validadores/ValidarEndereco.h"


void Hospede::validar(int tipo, string valor) {
    switch (tipo) {
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
    //throw invalid_argument("Cartao invalido");
}