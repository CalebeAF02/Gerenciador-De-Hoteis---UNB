//
// Created by caleb on 07/09/2025.
//

#include "../d_cabecalho/Pessoa.h"


using namespace std;

void Pessoa::validar(int tipo, string valor) {
    switch (tipo) {
        case TIPO_NOME: {
            ValidarNome::validar(valor);
            break;
        };
        case TIPO_EMAIL: {
            ValidarEmail::validar(valor);;
            break;
        };
    }
}