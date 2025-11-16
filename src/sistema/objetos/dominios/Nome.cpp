//
// Created by caleb on 01/10/2025.
//

#include "Nome.hpp"
namespace Hotelaria {
    void Nome::validar(const string &nome) {
        int nomeTamanho = nome.length();
        // 1. REGRA DE TAMANHO
        if (nomeTamanho < 5 || nomeTamanho > 20) {
            throw invalid_argument("Erro: Nome com tamanho invalido");
        }

        bool primeiraLetraCaixaAlta = true;
        int contEspaco = 0;

        for (int i = 0; i < nomeTamanho; i++) {
            char c = nome[i];

            if (c == ' ') {
                // 2. REGRA DE ESPAÇOS
                primeiraLetraCaixaAlta = true;
                contEspaco++;
                if (contEspaco > 1) {
                    throw invalid_argument("Erro: Espaco em branco seguido por outro espaco");
                }
            } else if (isalpha(c)) {
                contEspaco = 0;

                // 3. REGRA DE CAIXA
                if (primeiraLetraCaixaAlta) {
                    if (!isupper(c)) {
                        throw invalid_argument("Erro: Primeira letra de cada termo deve ser maiuscula");
                    }
                    primeiraLetraCaixaAlta = false;
                }
                // 4. REGRA DE CARACTERE INVÁLIDO (Números, Símbolos)
            } else {
                // Se não for espaço, e não for letra, é inválido.
                // Isso cobre números, símbolos e pontuação não permitida.
                throw invalid_argument("Erro: Nome com caracter invalido (Deve ser letra ou espaco).");
            }
        }

        // 5. REGRA DE ESPAÇO FINAL
        if (nome[nomeTamanho - 1] == ' ') {
            throw invalid_argument("Erro: Nome nao pode terminar com espaco");
        }

        // As contagens de letras maiúsculas/minúsculas não são estritamente necessárias
        // pois a lógica de `primeiraLetraCaixaAlta` já verifica o formato.
    }
}