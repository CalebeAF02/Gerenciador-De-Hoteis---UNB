#include <sstream>
#include <cctype>
#include <stdexcept>

#include "Endereco.hpp"

//
// Created by caleb on 01/10/2025.
//

#include "Endereco.hpp"


void Endereco::validar(const string endereco)
{
    int enderecoTamanho = endereco.length();
    if (enderecoTamanho < 5 || enderecoTamanho > 30)
    {
        throw invalid_argument("Erro: Endereco com tamanho invalido");
    }

    if (endereco[0] == ' ' || endereco[0] == ',' || endereco[0] == '.')
    {
        throw invalid_argument("Erro: Endereco nao pode comecar com ' ' ou ',' ou '.' !");
    }

    if (endereco[enderecoTamanho - 1] == ' ' || endereco[enderecoTamanho - 1] == ',' || endereco[enderecoTamanho - 1] ==
        '.')
    {
        throw invalid_argument("Erro: Endereco nao pode terminar com ' ' ou ',' ou '.' !");
    }

    int cont_branco = 0;
    int contNumeros = 0;
    int caracteres_brancos = 0;
    int contCaracter = 0;
    int contLetra = 0;

    for (int i = 0; i < enderecoTamanho; i++)
    {
        if (endereco[i] == ',' || endereco[i] == '.')
        {
            cont_branco = 0;
            contCaracter += 1;
            if (contCaracter > 1)
            {
                throw invalid_argument("Erro: Simbolo seguido por outro simbolo");
            }
        }
        else if (endereco[i] == ' ')
        {
            contCaracter = 0;
            caracteres_brancos += 1;
            cont_branco += 1;
            if (cont_branco > 1)
            {
                throw invalid_argument("Erro: Espaco em branco seguido por outro espaco em branco");
            }
        }
        else if (cont_branco == 1)
        {
            if (isalpha(endereco[i]))
            {
                contCaracter = 0;
                cont_branco = 0;
                contLetra += 1;
            }
            else
            {
                throw invalid_argument("Erro: Espaco em branco seguido por outro caracter");
            }
        }
        else if (isalpha(endereco[i]))
        {
            contCaracter = 0;
            cont_branco = 0;
            contLetra += 1;
        }
        else if (isalpha(endereco[i]))
        {
            contCaracter = 0;
            cont_branco = 0;
            contLetra += 1;
        }
        else if (isdigit(endereco[i]))
        {
            contCaracter = 0;
            cont_branco = 0;
            contNumeros += 1;
        }
    }
};

/*
void Endereco::validar(const string endereco) {
    if (endereco.length() < 5 || endereco.length() > 30) {
        throw invalid_argument("Erro: Endereco com tamanho invalido");
    }

    // Separar os componentes: rua, número, complemento
    istringstream iss(endereco);
    string rua, numero, complemento;

    if (!(iss >> rua >> numero)) {
        throw invalid_argument("Erro: Endereco deve conter pelo menos rua e numero");
    }

    getline(iss, complemento); // complemento pode ter espaços

    // Validar rua: cada termo começa com maiúscula
    istringstream ruaStream(rua);
    string termo;
    while (getline(ruaStream, termo, ' ')) {
        if (!isupper(termo[0])) {
            throw invalid_argument("Erro: Rua deve comecar com letra maiuscula em cada termo");
        }
    }

    // Validar número: inteiro positivo
    for (char c: numero) {
        if (!isdigit(c)) {
            throw invalid_argument("Erro: Numero do endereco deve conter apenas digitos");
        }
    }
    if (stoi(numero) <= 0) {
        throw invalid_argument("Erro: Numero do endereco deve ser positivo");
    }

    // Validar complemento (se existir): cada termo começa com maiúscula
    if (!complemento.empty()) {
        istringstream compStream(complemento);
        string compTermo;
        while (compStream >> compTermo) {
            if (!isupper(compTermo[0])) {
                throw invalid_argument("Erro: Complemento deve comecar com letra maiuscula em cada termo");
            }
        }
    }
}
*/