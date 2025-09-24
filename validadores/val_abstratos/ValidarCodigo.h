//
// Created by caleb on 21/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_VALIDARCODIGO_H
#define PROJETOS_CPP_UNB_7_IML_VALIDARCODIGO_H

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarCodigo: public exception{
public:
    static void validar(string codigo);
};
#endif //PROJETOS_CPP_UNB_7_IML_VALIDARCODIGO_H