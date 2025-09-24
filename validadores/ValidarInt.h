//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARINT_H
#define CODIGOS_CLION_TP1_IML_VALIDARINT_H

#include <stdexcept>

using namespace std;

class ValidarInt : public exception {
public:
    // Método abstrato: toda classe filha PRECISA implementar
    virtual void validar(int tipo, int valor) = 0; // interface pura
};


#endif //CODIGOS_CLION_TP1_IML_VALIDARINT_H