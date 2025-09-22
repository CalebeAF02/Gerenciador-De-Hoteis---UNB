//
// Created by caleb on 19/09/2025.
//

#include "../validadores/ValidarEndereco.h"

#include <string>

using namespace std;

void ValidarEndereco::validar(string endereco) {
    int enderecoTamanho = endereco.length();
    if (enderecoTamanho < 5 || enderecoTamanho > 30) {
        throw invalid_argument("Erro: Endereco com tamanho invalido");
    }

    bool primeiraLetraCaixaAlta = true;
    int contEspaco = 0;

    for (int i = 0; i < enderecoTamanho; i++) {
        if (endereco[i] == ' ') {
            primeiraLetraCaixaAlta = true;
            contEspaco++;
            if (contEspaco > 1) {
                throw invalid_argument("Erro: Espaco em branco seguido por outro espaco");
            }
        } else if (isalpha(endereco[i])) {
            contEspaco = 0;
            if (primeiraLetraCaixaAlta && !isupper(endereco[i])) {
                throw invalid_argument("Erro: Primeira letra de cada termo deve ser maiuscula");
            }
            primeiraLetraCaixaAlta = false;
        } else {
            throw invalid_argument("Erro: Endereco com caracter invalido");
        }
    }
    if (endereco[enderecoTamanho - 1] == ' ') {
        throw invalid_argument("Erro: Endereco nao pode terminar com espaco");
    }
};