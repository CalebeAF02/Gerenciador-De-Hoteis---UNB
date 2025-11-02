#include "Senha.hpp"
#include <stdexcept>
#include <cctype>

void Senha::validar(const string senha) {
    if (senha.length() != 5) {
        throw invalid_argument("Erro: Senha com tamanho invalido");
    }

    bool tem_maiuscula = false;
    bool tem_minuscula = false;
    bool tem_digito = false;
    bool tem_especial = false;

    for (size_t i = 0; i < senha.length(); ++i) {
        char atual = senha[i];
        char anterior = (i > 0) ? senha[i - 1] : '\0';

        if (isalpha(atual)) {
            if (islower(atual)) tem_minuscula = true;
            if (isupper(atual)) tem_maiuscula = true;

            if (isalpha(anterior)) {
                throw invalid_argument("Erro: letra seguida por letra");
            }
        } else if (isdigit(atual)) {
            tem_digito = true;

            if (isdigit(anterior)) {
                throw invalid_argument("Erro: digito seguido por digito");
            }
        } else if (atual == '\'' || atual == '!' || atual == '?' || atual == '$' ||
                   atual == '%' || atual == '&' || atual == '*' || atual == '.') {
            tem_especial = true;
        } else {
            throw invalid_argument("Erro: caracter invalido");
        }
    }

    if (!tem_maiuscula || !tem_minuscula || !tem_digito || !tem_especial) {
        throw invalid_argument("Erro: senha deve conter letra maiúscula, minúscula, número e especial");
    }
}