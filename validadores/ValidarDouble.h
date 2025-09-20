//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H
#define CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H

#include<stdexcept>

using namespace std;


class ValidarDouble: public exception {

public:
    // Método abstrato: toda classe filha PRECISA implementar
    virtual void validarDouble(int tipo, double valor) = 0 ;

    // Sempre que tiver métodos virtuais, destrutor deve ser virtual também
    virtual ~ValidarDouble() = default;
};

#endif //CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H