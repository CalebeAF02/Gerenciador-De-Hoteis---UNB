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
    virtual void validar(int tipo, double valor) = 0 ;

};

#endif //CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H