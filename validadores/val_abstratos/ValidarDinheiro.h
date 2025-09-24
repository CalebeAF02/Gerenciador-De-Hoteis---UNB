//
// Created by caleb on 21/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_VALIDARDINHEIRO_H
#define PROJETOS_CPP_UNB_7_IML_VALIDARDINHEIRO_H

#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarDinheiro: public exception{
public:
    static void validar(int dinheiro);
};
#endif //PROJETOS_CPP_UNB_7_IML_VALIDARDINHEIRO_H