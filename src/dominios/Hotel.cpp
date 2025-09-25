#include "dominios/Hotel.h"

void Hotel::validar(int tipo, const string valor) {
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
        case TIPO_CODIGO: {
            ValidarCodigo::validar(valor);
            break;
        };
    };
};

void Hotel::validarTelefone(const string valor) {
    string ddi = "";
    string ddd = "";
    string numero = "";
    if (valor.length() != 14) {
        throw invalid_argument("Erro: Sem caracteres suficientes ou acima do esperado ");
    }
    for (int i = 0; i < valor.length(); i++) {
        if (i == 0) {
            if (valor[i] != '+') {
                throw invalid_argument("Erro: Caracter nao e caracter unico de ddi '+'");
            }
        }
        if (valor[i] < 1 || valor[i] > 9) {
            if (i < 3) {
                ddi += valor[i];
            } else if (i < 5) {
                ddd += valor[i];
            } else if (i < valor.length()) {
                numero += valor[i];
            }
        } else {
            throw invalid_argument("Erro: Caracter nao e numero");
        }
    }
};