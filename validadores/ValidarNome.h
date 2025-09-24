//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARNOME_H
#define CODIGOS_CLION_TP1_IML_VALIDARNOME_H

#include <iostream>
#include <string>

#include <stdexcept>

using namespace std;

// Funcao estatica para validar nome em hotel e pessoa
class ValidarNome: public exception {
public:
    static void validar(string nome);
};


#endif //CODIGOS_CLION_TP1_IML_VALIDARNOME_H