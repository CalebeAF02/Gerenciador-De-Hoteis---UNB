//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARINT_H
#define CODIGOS_CLION_TP1_IML_VALIDARINT_H

#include <stdexcept>

using namespace std;

class ValidarInt: public exception {
public:
    // Método abstrato: toda classe filha PRECISA implementar
    virtual void validarInt(int valor) = 0;

    // Sempre que tiver métodos virtuais, destrutor deve ser virtual também
    virtual ~ValidarInt() = default;
};


#endif //CODIGOS_CLION_TP1_IML_VALIDARINT_H