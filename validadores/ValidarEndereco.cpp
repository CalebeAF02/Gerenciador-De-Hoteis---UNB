//
// Created by caleb on 19/09/2025.
//

#include "../validadores/ValidarEndereco.h"

void ValidarEndereco::validar(string endereco) {
    int cont_branco = 0;

    int enderecoTamanho = endereco.length();
    if (enderecoTamanho < 5 || enderecoTamanho > 30) {
        throw invalid_argument("Erro: Endereco com tamanho invalido");
    }

    bool primeiraLetraCaixaAlta = true;
    int caracteres_brancos = 0;
    int contCaracter = 0;
    int contLetra = 0;

    for (int i = 0; i < enderecoTamanho; i++) {
        if (endereco[i] == ',' || endereco[i] == '.') {
            primeiraLetraCaixaAlta = true;
            contCaracter++;
            if (contCaracter > 1) {
                throw invalid_argument("Erro: Simbolo seguido por outro simbolo");
            }
        } else if (endereco[i] == ' ') {
            caracteres_brancos += 1;
            cont_branco += 1;
            if (cont_branco > 1) {
                throw invalid_argument("Erro: Espaco em branco seguido por outro espaco em branco");
            }
        } else if (cont_branco == 1 && endereco[i] != (isalpha(endereco[i]))) {
            throw invalid_argument("Erro: Espaco em branco seguido por caracter invalido");
        } else if (cont_branco == 1 && isalpha(endereco[i])) {
            cont_branco = 0;
            contLetra += 1;
        } else if (isalpha(endereco[i])) {
            contLetra += 1;
        }
    }
    if (endereco[enderecoTamanho - 1] == ' ') {
        throw invalid_argument("Erro: Endereco nao pode terminar com espaco");
    }
};