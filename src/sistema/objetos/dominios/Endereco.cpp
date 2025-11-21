#include <sstream>
#include <cctype>
#include <stdexcept>

#include "Endereco.hpp"

//
// Created by caleb on 01/10/2025.
//

#include "Endereco.hpp"

namespace Hotelaria {
    Endereco::Endereco(const string &valor) {
        setValor(valor);
    };

    void Endereco::setValor(const string &valor) {
        validar(valor);
        this->enderecoStr = valor;
    }

    string Endereco::getValor() const {
        return enderecoStr;
    }

    void Endereco::validar(const string endereco) {
        int enderecoTamanho = endereco.length();
        if (enderecoTamanho < 5 || enderecoTamanho > 30) {
            throw invalid_argument("Erro: Endereco com tamanho invalido");
        }

        if (endereco[0] == ' ' || endereco[0] == ',' || endereco[0] == '.') {
            throw invalid_argument("Erro: Endereco nao pode comecar com ' ' ou ',' ou '.' !");
        }

        if (endereco[enderecoTamanho - 1] == ' ' || endereco[enderecoTamanho - 1] == ',' || endereco[
                enderecoTamanho - 1] ==
            '.') {
            throw invalid_argument("Erro: Endereco nao pode terminar com ' ' ou ',' ou '.' !");
        }

        int cont_branco = 0;
        int contCaracterEspecial = 0;
        int contLetra = 0;

        for (int i = 0; i < enderecoTamanho; i++) {
            char caractere = endereco[i];

            if (caractere == ',' || caractere == '.') {
                cont_branco = 0;
                contCaracterEspecial++;

                if (contCaracterEspecial > 1) {
                    throw invalid_argument("Erro: Simbolo seguido por outro simbolo");
                }
            } else if (caractere == ' ') {
                contCaracterEspecial = 0;
                cont_branco++;
                if (cont_branco > 1) {
                    throw invalid_argument("Erro: Espaco em branco seguido por outro espaco em branco");
                }
            } else if (cont_branco == 1) {
                if (isalpha(caractere) || isdigit(caractere)) {
                    contCaracterEspecial = 0;
                    cont_branco = 0;
                } else {
                    throw invalid_argument("Erro: Espaco em branco seguido por outro caracter");
                }
            }
        }
    };
}