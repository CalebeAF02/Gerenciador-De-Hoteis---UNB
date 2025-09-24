//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H
#define CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar email em hotel e pessoa
class ValidarEmail : public exception {
public:
    static void validar(string valor);
};

#endif //CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H