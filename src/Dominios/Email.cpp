//
// Created by caleb on 01/10/2025.
//

#include "../../include/Dominios/Email.h"

#include "../validadoresAbstratos/ValidarEmail.h"


void validar(const string email)
{
    // lógica de validação do email
    int posicaoArroba = email.find("@");
    if (posicaoArroba == string::npos)
    {
        throw invalid_argument("Erro: Email invalido (sem @)");
    }

    string parteLocal = email.substr(0, posicaoArroba);
    string parteDominio = email.substr(posicaoArroba + 1);

    if (parteLocal.empty() || parteLocal.length() > 64)
    {
        throw invalid_argument("Erro: Parte local invalida");
    }
    if (parteDominio.empty() || parteDominio.length() > 255)
    {
        throw invalid_argument("Erro: Parte dominio invalida");
    }

    int contSimboloParteLocal = 0;
    for (int i = 0; i < parteLocal.length(); i++)
    {
        // Regra 1
        if (isalpha(parteLocal[i]) || isdigit(parteLocal[i]) || parteLocal[i] == '.' || parteLocal[i] == '-')
        {
            // Regra 2
            if (i == 0 || i == parteLocal.length() - 1)
            {
                if (parteLocal[i] == '.' || parteLocal[i] == '-')
                {
                    throw invalid_argument("Erro: Email nao pode comecar com '.' ou '-' !");
                }
            }
            //Regra 1 - Se a letra é minuscula
            if (islower(parteLocal[i]))
            {
                contSimboloParteLocal = 0;
                //cout << "Esta letra e minuscula? " << parteLocal[i] << " Sim!" << endl;
                //Regra 1 - Se o Caracter é numero
            }
            else if (isdigit(parteLocal[i]))
            {
                contSimboloParteLocal = 0;
                //cout << "Este Caracter e um numero? " << parteLocal[i] << " Sim!" << endl;
                // Regra 3
            }
            else if (parteLocal[i] == '.' || parteLocal[i] == '-')
            {
                contSimboloParteLocal += 1;
                //cout << "Esta caracter e '.' ou '-' ? " << parteLocal[i] << " Sim!" << endl;
                if (contSimboloParteLocal > 1)
                {
                    throw invalid_argument("Erro: Email nao pode ter dois simbolos seguidos");
                }
            }
            else
            {
                throw invalid_argument("Erro: Caracter invalido! ");
            }
        }
        else
        {
            throw invalid_argument("Erro: Caracter invalido! ");
        }
    }
    // print se parteLocal OK
    //cout <<"parteLocal percoeu por completo e esta ok: "<< parteLocal << endl;

    if (parteDominio.length() > 255)
    {
        throw invalid_argument("Erro: parteDominio do Email com tamanho invalido");
    }
    int contSimboloParteDominio = 0;
    for (int i = 0; i < parteDominio.length(); i++)
    {
        // Regra 1
        if (isalpha(parteDominio[i]) || isdigit(parteDominio[i]) || parteDominio[i] == '.' || parteDominio[i] == '-')
        {
            // Regra 2
            if (i == 0 || i == parteDominio.length() - 1)
            {
                if (parteDominio[i] == '.' || parteDominio[i] == '-')
                {
                    throw invalid_argument("Erro: Email nao pode comecar com '.' ou '-' !");
                }
            }
            //Regra 1 - Se a letra é minuscula
            if (islower(parteDominio[i]))
            {
                contSimboloParteDominio = 0;
                //cout << "Esta letra e minuscula? " << parteDominio[i] << " Sim!" << endl;
                //Regra 1 - Se o Caracter é numero
            }
            else if (isdigit(parteDominio[i]))
            {
                contSimboloParteDominio = 0;
                //cout << "Este Caracter e um numero? " << parteDominio[i] << " Sim!" << endl;
                // Regra 3
            }
            else if (parteDominio[i] == '.' || parteDominio[i] == '-')
            {
                contSimboloParteDominio += 1;
                //cout << "Esta caracter e '.' ou '-' ? " << parteDominio[i] << " Sim!" << endl;
                if (contSimboloParteDominio > 1)
                {
                    throw invalid_argument("Erro: Email nao pode ter dois simbolos seguidos");
                }
            }
            else
            {
                throw invalid_argument("Erro: Caracter invalido! ");
            }
        }
        else
        {
            throw invalid_argument("Erro: Caracter invalido! ");
        }
    }
}