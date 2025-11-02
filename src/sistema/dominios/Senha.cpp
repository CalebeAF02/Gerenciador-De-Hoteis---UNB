#include "Senha.hpp"
#include <stdexcept>
#include <cctype>

void Senha::validar(const std::string senha) {
    if (senha.length() != 5) {
        throw std::invalid_argument("Erro: Senha com tamanho invalido");
    }

    bool tem_maiuscula = false;
    bool tem_minuscula = false;
    bool tem_digito = false;
    bool tem_especial = false;

    for (size_t i = 0; i < senha.length(); ++i) {
        char atual = senha[i];
        char anterior = (i > 0) ? senha[i - 1] : '\0';

        if (std::isalpha(atual)) {
            if (std::islower(atual)) tem_minuscula = true;
            if (std::isupper(atual)) tem_maiuscula = true;

            if (std::isalpha(anterior)) {
                throw std::invalid_argument("Erro: letra seguida por letra");
            }
        } else if (std::isdigit(atual)) {
            tem_digito = true;

            if (std::isdigit(anterior)) {
                throw std::invalid_argument("Erro: digito seguido por digito");
            }
        } else if (atual == '\'' || atual == '!' || atual == '?' || atual == '$' ||
                   atual == '%' || atual == '&' || atual == '*' || atual == '.') {
            tem_especial = true;
        } else {
            throw std::invalid_argument("Erro: caracter invalido");
        }
    }

    if (!tem_maiuscula || !tem_minuscula || !tem_digito || !tem_especial) {
        throw std::invalid_argument("Erro: senha deve conter letra maiúscula, minúscula, número e especial");
    }
}