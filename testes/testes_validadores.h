//
// Created by caleb on 20/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H
#define PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H

#include "../dominios/Gerente.h"
#include "../dominios/Hotel.h"
#include "Teste.h"

class TesteValidadores {
public:
    static void testarEntradas ();
;

    static void testarValidadorNome(int esperando_resultado, Pessoa* ptr, string nome);
    static void testarValidadorEmail(int esperando_resultado, Pessoa* ptr, string email);
    static void testarValidadorEndereco(int esperando_resultado, Hotel* ptr, string endereco);
};

#endif //PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H