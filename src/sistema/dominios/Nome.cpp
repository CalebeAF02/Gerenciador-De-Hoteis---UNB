//
// Created by caleb on 01/10/2025.
//

#include "Nome.hpp"

void Nome::validar(const string &nome) {
    int cont_alta = 0;
    int cont_baixa = 0;
    // logica de validacao do nome
    int nomeTamanho = nome.length();
    if (nomeTamanho < 5 || nomeTamanho > 20) {
        throw invalid_argument("Erro: Nome com tamanho invalido");
    }

    bool primeiraLetraCaixaAlta = true;
    int contEspaco = 0;

    for (int i = 0; i < nomeTamanho; i++) {
        if (nome[i] == ' ') {
            primeiraLetraCaixaAlta = true;
            contEspaco++;
            if (contEspaco > 1) {
                throw invalid_argument("Erro: Espaco em branco seguido por outro espaco");
            }
        } else if (isalpha(nome[i])) {
            contEspaco = 0;
            if (primeiraLetraCaixaAlta && !isupper(nome[i])) {
                throw invalid_argument("Erro: Primeira letra de cada termo deve ser maiuscula");
            }
            primeiraLetraCaixaAlta = false;
        } else if (isupper(nome[i])) {
            cont_alta += 1;
        } else if (islower(nome[i])) {
            cont_baixa += 1;
        } else {
            throw invalid_argument("Erro: Nome com caracter invalido");
        }
    }
    if (nome[nomeTamanho - 1] == ' ') {
        throw invalid_argument("Erro: Nome nao pode terminar com espaco");
    }
}