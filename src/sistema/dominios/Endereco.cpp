//
// Created by caleb on 01/10/2025.
//

#include "Endereco.h"


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