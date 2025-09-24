//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H
#define CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H

#include<stdexcept>

using namespace std;


class ValidarEmail : public exception {
public:
    virtual void validar(string valor);
};

#endif //CODIGOS_CLION_TP1_IML_VALIDARDOUBLE_H