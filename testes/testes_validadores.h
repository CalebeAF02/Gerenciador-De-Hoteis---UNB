//
// Created by caleb on 20/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H
#define PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H

#include "../dominios/Gerente.h"

class TesteValidadores {
public:


    static const int DEVE_DAR_ERRADO = -1;
    static const int DEVE_DAR_CERTO = 1;


    static void testarEntradas ();

    static void testarValidadorNome(int esperando_resultado, Pessoa* ptr, string nome);
    static void testarValidadorEmail(Pessoa* ptr, string email);

};

#endif //PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H