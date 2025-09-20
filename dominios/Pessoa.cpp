//
// Created by caleb on 07/09/2025.
//

#include "../dominios/Pessoa.h"
#include "../validadores/ValidarNome.h"
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

void Pessoa::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_NOME: {
            ValidarNome::validar(valor);
            break;
        };
        case TIPO_EMAIL: {
            validarEmail(valor);;
            break;
        };
    }
}
void Pessoa::validarEmail(string email) {
    // lógica de validação do email
    int posicaoArroba = email.find("@");
    if (posicaoArroba == string::npos) {
        cout << "Erro: Email invalido (sem @)\n";
        return ;
    }

    string parteLocal = email.substr(0, posicaoArroba);
    string parteDominio = email.substr(posicaoArroba + 1);

    if (parteLocal.empty() || parteLocal.length() > 64) {
        cout << "Erro: Parte local invalida\n";
        return ;
    }
    if (parteDominio.empty() || parteDominio.length() > 255) {
        cout << "Erro: Parte dominio invalida\n";
        return ;
    }

    int contSimboloParteLocal = 0;
    for (int i = 0; i < parteLocal.length(); i++) {
        // Regra 1
        if (isalpha(parteLocal[i]) || isdigit(parteLocal[i]) || parteLocal[i] == '.' || parteLocal[i] == '-') {
            // Regra 2
            if (i == 0 || i == parteLocal.length() - 1) {
                if (parteLocal[i] == '.' || parteLocal[i] == '-') {
                    cout << "Erro: Email nao pode comecar com '.' ou '-' !" << endl;
                    return ;
                }
            }
            //Regra 1 - Se a letra é minuscula
            if (islower(parteLocal[i])) {
                contSimboloParteLocal = 0;
                //cout << "Esta letra e minuscula? " << parteLocal[i] << " Sim!" << endl;
                //Regra 1 - Se a letra é numero
            } else if (isdigit(parteLocal[i])) {
                contSimboloParteLocal = 0;
                //cout << "Esta caracter e um numero? " << parteLocal[i] << " Sim!" << endl;
                // Regra 3
            } else if (parteLocal[i] == '.' || parteLocal[i] == '-') {
                contSimboloParteLocal += 1;
                //cout << "Esta caracter e '.' ou '-' ? " << parteLocal[i] << " Sim!" << endl;
                if (contSimboloParteLocal > 1) {
                    cout << "Erro: Email nao pode ter dois simbolos seguidos" << endl;
                    return ;
                }
            } else {
                cout << "Erro: Esta letra nao e miniscula! " << parteLocal[i] << endl;
                return ;
            }
        }
    }
    // print se parteLocal OK
    //cout <<"parteLocal percoeu por completo e esta ok: "<< parteLocal << endl;

    if (parteDominio.length() > 255) {
        cout << "Erro: parteDominio do Email com tamanho INVALIDO" << endl;
        return ;
    }
    int contSimboloParteDominio = 0;
    for (int i = 0; i < parteDominio.length(); i++) {
        // Regra 1
        if (isalpha(parteDominio[i]) || isdigit(parteDominio[i]) || parteDominio[i] == '.' || parteDominio[i] == '-') {
            // Regra 2
            if (i == 0 || i == parteDominio.length() - 1) {
                if (parteDominio[i] == '.' || parteDominio[i] == '-') {
                    cout << "Erro: Email nao pode comecar com '.' ou '-' !" << endl;
                    return ;
                }
            }
            //Regra 1 - Se a letra é minuscula
            if (islower(parteDominio[i])) {
                contSimboloParteDominio = 0;
                //cout << "Esta letra e minuscula? " << parteDominio[i] << " Sim!" << endl;
                //Regra 1 - Se a letra é numero
            } else if (isdigit(parteDominio[i])) {
                contSimboloParteDominio = 0;
                //cout << "Esta caracter e um numero? " << parteDominio[i] << " Sim!" << endl;
                // Regra 3
            } else if (parteDominio[i] == '.' || parteDominio[i] == '-') {
                contSimboloParteDominio += 1;
                //cout << "Esta caracter e '.' ou '-' ? " << parteDominio[i] << " Sim!" << endl;
                if (contSimboloParteDominio > 1) {
                    cout << "Erro: Email nao pode ter dois simbolos seguidos" << endl;
                    return ;
                }
            } else {
                cout << "Erro: Esta letra nao e miniscula! " << parteDominio[i] << endl;
                return ;
            }
        }
    }
}