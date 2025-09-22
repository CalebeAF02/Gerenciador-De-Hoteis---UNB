//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARENDERECO_H
#define CODIGOS_CLION_TP1_IML_VALIDARENDERECO_H

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarEndereco: public exception{
public:
    static void validar(string endereco);
};


#endif //CODIGOS_CLION_TP1_IML_VALIDARENDERECO_H