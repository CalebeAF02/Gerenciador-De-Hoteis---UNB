#include "../dominios/Hospede.h"

void Hospede::validar(int tipo, const string valor) {
    switch (tipo) {
        case TIPO_ENDERECO:
            ValidarEndereco::validar(valor);
            break;
        case TIPO_CARTAO:
            validarCartao(valor);
            break;
    }
}

void Hospede::validarCartao(const string valor) {
    if (valor.length() != 16) {
        throw invalid_argument("Erro: Tamanho invalido");
    } // implementar algoritimo de lunn
}
