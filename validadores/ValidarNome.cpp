//
// Created by caleb on 19/09/2025.
//
#include <iostream>
#include "../validadores/ValidarNome.h"

#include <string>

using namespace std;

//     throw invalid_argument("Endereco invalido");
// implementar nos COUT

void ValidarNome::validarNome(string nome) {
    // lógica de validação do nome
    int nomeTamanho = nome.length();
    if (nomeTamanho < 5 || nomeTamanho > 20) {
        cout << "Erro: Nome com tamanho invalido\n";
        return ;
    }

    bool primeiraLetraCaixaAlta = true;
    int contEspaco = 0;

    for (int i = 0; i < nomeTamanho; i++) {
        if (nome[i] == ' ') {
            primeiraLetraCaixaAlta = true;
            contEspaco++;
            if (contEspaco > 1) {
                cout << "Erro: Espaco em branco seguido por outro espaco\n";
                return ;
            }
        } else if (isalpha(nome[i])) {
            contEspaco = 0;
            if (primeiraLetraCaixaAlta && !isupper(nome[i])) {
                cout << "Erro: Primeira letra de cada termo deve ser maiuscula\n";
                return ;
            }
            primeiraLetraCaixaAlta = false;
        } else {
            cout << "Erro: Nome com caracter invalido\n";
            return ;
        }
    }
    if (nome[nomeTamanho - 1] == ' ') {
        cout << "Erro: Nome nao pode terminar com espaco\n";
        return ;
    }
}
